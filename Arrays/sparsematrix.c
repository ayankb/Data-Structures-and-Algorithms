#include<stdio.h>
#include<stdlib.h>

struct Sparse {
    int row;
    int col;
    int val;
};

// Function to convert normal matrix to sparse (returns number of non-zero)
int convsertSparse(int **mat, int r, int c, struct Sparse *SM) {
    int i=0, j=0, k=0;
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            if(mat[i][j] != 0){
                SM[k].row = i;
                SM[k].col = j;
                SM[k].val = mat[i][j];
                k++;
            }
    

    return k;
}

void printSparse(struct Sparse *SM, int no_of_nz_e){
    printf("\nRow Col Val\n");
    for(int i=0; i<no_of_nz_e; i++){
        printf("%d %d %d\n", SM[i].row, SM[i].col, SM[i].val);
    }
}

int main(){
    int r, c, i, j;

    printf("Enter the row and column for first matrix:\n");
    scanf("%d %d", &r, &c);

    int **A = (int**)malloc(r * sizeof(int));
    for(i=0; i<r; i++){
        A[i] = (int*)malloc(c * sizeof(int));
    }
    printf("Enter the element of first matrix:\n");
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            scanf("%d", &A[i][j]);

    struct Sparse *SM = (struct Sparse*)malloc(r * c * sizeof(struct Sparse));
    
    int nm = convsertSparse(A, r, c, SM);

    printf("Sparse A:\n");
    printSparse(SM, nm);


    return 0;
}
