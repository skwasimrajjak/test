#include<stdio.h>

int main(){
    //Initialization
    int rowFirst, columnFirst, rowSecond, columnSecond;
    int sum;
    int firstMatrix[10][10], secondMatrix[10][10], result[10][10];

    //First Matrix
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &rowFirst, &columnFirst);

    for (int i = 0; i < rowFirst; ++i) {
        for (int j = 0; j < columnFirst; ++j) {
            printf("Enter element of index[%d,%d]: ", i+1, j+1);
            scanf("%d", &firstMatrix[i][j]);
        }
    }

    //Second Matrix
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &rowSecond, &columnSecond);

    if (columnFirst != rowSecond) {
        printf("Error! Number of columns in the first matrix is not equal to the number of rows in the second matrix.\n");
    } else {

        for (int i = 0; i < rowSecond; ++i) {
            for (int j = 0; j < columnSecond; ++j) {
                printf("Enter element of index[%d,%d]:", i+1, j+1);
                scanf("%d", &secondMatrix[i][j]);
            }
        }
    }

    //Matrix Multiplication
    for (int i = 0; i < rowFirst; ++i) {
            for (int j = 0; j < columnSecond; ++j) {
                for (int k = 0; k < columnFirst; ++k) {
                    sum += firstMatrix[i][k] * secondMatrix[k][j];
                }

                result[i][j] = sum;
                sum = 0;
            }
        }

    //Display
    printf("Output Matrix:\n");
        for (int i = 0; i < rowFirst; ++i) {
            for (int j = 0; j < columnSecond; ++j) {
                printf("%d  ", result[i][j]);
                if (j == columnSecond - 1)
                    printf("\n");
            }
        }
    
}
