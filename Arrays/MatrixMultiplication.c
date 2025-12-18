#include<stdio.h>

int main(){
    int r, c;
    printf("Enter number of rows and columns of the matrices:\n");
    scanf("%d %d", &r, &c);
    int a[r][c], b[r][c], result[r][c];
    printf("Enter elements of first matrix:\n");
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf("%d", &b[i][j]);
        }
    }

    // Matrix multiplication
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            result[i][j] = 0;
            for(int k = 0; k < c; k++){
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("Multiplication of the two matrices is:\n");
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}