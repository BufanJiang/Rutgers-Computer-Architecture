#include <stdio.h>
#include <stdlib.h>

void printMatrix(int** matrix, int rows, int columns){
    int i, j;
    for(i = 0; i < rows; i++){
        for(j = 0; j < columns; j++){
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    return;
}

int main(int argc, char **argv){
    int rows1, rows2, columns1, columns2, num1, num2;
    int i,j,k; 
    FILE* fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        printf("error\n");
        return 1;
    }

    fscanf(fp, "%d", &rows1);
    fscanf(fp, "%d", &columns1);
    int** matrix1 = (int **)malloc(rows1 * sizeof(int*));
    for (i = 0; i < rows1; i++)
    {
        matrix1[i] = (int*) malloc(columns1 * sizeof(int));
    }
    for (i = 0; i < rows1; i++) {
		for (j = 0; j < columns1; j++) {
			fscanf(fp, "%d", &num1);
			matrix1[i][j] = num1;
		}
	}

    fscanf(fp, "%d", &rows2);
    fscanf(fp, "%d", &columns2);
    int** matrix2 = (int **)malloc(rows2 * sizeof(int*));
    for (i = 0; i < rows2; i++)
    {
        matrix2[i] = (int*) malloc(columns2 * sizeof(int));
    }
    for (i = 0; i < rows2; i++) {
		for (j = 0; j < columns2; j++) {
			fscanf(fp, "%d", &num2);
			matrix2[i][j] = num2;
		}
	}

    fclose(fp);

    int res = 0;
    if(columns1 == rows2)
    {
        int** matrix3 = (int**) malloc(sizeof(int*) * rows1);
        for(i = 0; i < rows1; i++)
        {
            matrix3[i] = (int*) malloc(sizeof(int) * columns2);
        }
        for(i = 0; i < rows1; i++)
        {
            for(j = 0; j < columns2; j++)
            {
                for(k = 0; k < columns1; k++)
                {
                    res += matrix1[i][k] * matrix2[k][j];
                }
                matrix3[i][j] = res;
                res = 0;
            }
        }
        printMatrix(matrix3, rows1, columns2);
        free(matrix3);
    }else
    {
        printf("bad-matrices\n");
    }

    free(matrix1);
    free(matrix2);
    return 0;

}
