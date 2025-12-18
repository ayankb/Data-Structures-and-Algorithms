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


// Function to Subtrction two sparse matrices
int subSparse(struct Sparse *A, int na, struct Sparse *B, int nb, struct Sparse *C){
    int i=0, j=0, k=0;

    while(i < na && j <nb){
        // Compare positions (row, col)
        if(A[i].row < B[j].row || A[i].row == B[j].row && A[i].col < B[j].col){
            C[k] = A[i];
            k++, i++;
        } else if(B[j].row < A[i].row || B[j].row == A[i].row && B[j].col < A[i].col) {
            C[k] = B[j];
            C[k].val = -C[k].val;
            k++, j++;
        } else {
            // Same row and col → add values
            C[k].row = A[i].row;
            C[k].col = A[i].col;
            C[k].val = A[i].val - B[j].val;

            // Only add if non-zero
            if (C[k].val != 0)         
                k++;
            i++, j++;
        }
    }
    
    // Copy remaining elements
    while(i < na){
        C[k] = A[i];
        k++, i++;
    }

    while(j < nb){
        C[k] = B[j];
        C[k].val = -C[k].val;

        k++, j++; 
    }

    return k;
}


int main(){
    int r1, c1, r2, c2, i, j;

    printf("Enter the row and column for first matrix:\n");
    scanf("%d %d", &r1, &c1);
    int **A = (int**)malloc(r1 * sizeof(int));
    for(i=0; i<r1; i++){
        A[i] = (int*)malloc(c1 * sizeof(int));
    }
    printf("Enter the element of first matrix:\n");
    for(i=0; i<r1; i++)
        for(j=0; j<c1; j++)
            scanf("%d", &A[i][j]);

    printf("Enter the row and column for second matrix:\n");
    scanf("%d %d", &r2, &c2);
    int **B = (int**)malloc(r2 * sizeof(int));
    for(i=0; i<r2; i++){
        B[i] = (int*)malloc(c2 * sizeof(int));
    }
    printf("Enter the element of second matrix:\n");
    for(i=0; i<r2; i++)
        for(j=0; j<c2; j++)
            scanf("%d", &B[i][j]);

    // Dimension check
    if (r1 != r2 || c1 != c2) {
        printf("Addition not possible because dimensions do not match.\n");
        return 0;
    }

    struct Sparse *SA = (struct Sparse*)malloc(r1 * c1 * sizeof(struct Sparse));
    struct Sparse *SB = (struct Sparse*)malloc(r2 * c2 * sizeof(struct Sparse));
    
    int na = convsertSparse(A, r1, c1, SA);
    int nb = convsertSparse(B, r1, c2, SB);

    struct Sparse *SubS = (struct Sparse*)malloc((na + nb) * sizeof(struct Sparse));

    printf("Sparse A:\n");
    printSparse(SA, na);

    printf("Sparse B:\n");
    printSparse(SB, nb);

    printf("\nSubtraction");
    int nc = subSparse(SA, na, SB, nb, SubS);
    printSparse(SubS, nc);

    return 0;
}
