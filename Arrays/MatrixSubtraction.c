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

    // Matrix subtraction
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            result[i][j] = a[i][j] - b[i][j];
        }
    }

    printf("Subtraction of the two matrices is:\n");
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}