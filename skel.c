#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 500

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)


int n;  //n*n matrix

int main()
{
    char cmd_type[15];
    int i, j;
    int** matrix;

    while (1)
    {
        scanf("%s", cmd_type);

        if (!strcmp(cmd_type, "new"))
        {

            scanf("%d", &n);
            if(n>300 || n<0){
                printf("invalid size for SKKU matrix!\n");
                return 0;
            }
            matrix = (int**)malloc(sizeof(int*)*n);
            for(int i=0;i<n;i++){
                matrix[i] = (int*)malloc(sizeof(int)*n);
                for(int j=0;j<n;j++){
                    scanf("%d",&matrix[i][j]); 
                }
            }

        }
        else if (!strcmp(cmd_type, "row_swap"))
        {
            //문제 발생
            scanf("%d %d", &i, &j);
            int *temp;
            temp = matrix[i-1];
            matrix[i-1] = matrix[j-1];
            matrix[j-1] = temp;

        }
        else if (!strcmp(cmd_type, "col_swap"))
        {
            scanf("%d %d", &i, &j);
            int temp;
            for(int x = 0; x<n; x++){
                temp = matrix[x][i-1];
                matrix[x][i-1] = matrix[x][j-1];
                matrix[x][j-1] = temp;
            }

        }
        else if (!strcmp(cmd_type, "row_shift"))
        { 
          //what if row_shift 4 2? 4번째 row를 2번째로 이동시킨다
            scanf("%d %d", &i, &j);
            if (i < j){
                int *temp;
                temp = matrix[i - 1];
                for (int x = i; x < j; x++){
                    matrix[x - 1] = matrix[x];
                }
                matrix[j - 1] = temp;
            }
            else if (i > j)
            {
                int *temp;
                temp = matrix[i - 1];
                for(int x = i-2; x >= j-1; x--){
                     matrix[x+1] = matrix[x];
                }
                matrix[j-1] = temp;
            }

        }
        else if (!strcmp(cmd_type, "col_shift"))
        {
            scanf("%d %d", &i, &j);
            if (i > j)
            {
                for (int x = 0; x < n; x++)
                {
                    int temp = matrix[x][i - 1];
                    for (int y = i - 2; y >= j - 1; y--)
                    {
                        matrix[x][y + 1] = matrix[x][y];
                    }
                    matrix[x][j - 1] = temp;
                }
            }
            else if (i < j)
            {
                for (int x = 0; x < n; x++)
                {
                    int temp = matrix[x][i - 1];
                    for (int y = i; y <j; y++)
                    {
                        matrix[x][y-1] = matrix[x][y];
                    }
                    matrix[x][j - 1] = temp;
                }
            }

        }
        else if (!strcmp(cmd_type, "print"))
        {
            scanf("%d %d", &i,&j);
            printf("%d\n", matrix[i-1][j-1]);
        }
        else if (!strcmp(cmd_type, "exit"))
        {
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    printf("%d ", matrix[i][j]);
                }
                printf("\n");
            }
            for(int x=0;x<n;x++){
                free(matrix[x]);
            }
            free(matrix);
            break;
        }
    }
    
    return 0;
}