#include <stdio.h>

#define MAX 100

// Structure to represent a sparse matrix element
typedef struct {
    int row;
    int col;
    int value;
} SparseMatrix;

// Function to find the transpose of a sparse matrix
void transpose(SparseMatrix a[], SparseMatrix b[]) {
    int i, j, n;

    // Step 1: Initialize the first element of the transposed matrix
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = a[0].value;

    n = a[0].value;  // Number of non-zero elements

    int k = 1;  // Index for the transposed matrix

    // Step 2: Transpose by swapping row and column indices
    for (i = 0; i < a[0].col; i++) {  // Iterate over columns
        for (j = 1; j <= n; j++) {    // Iterate over non-zero elements
            if (a[j].col == i) {      // If the element's column matches the current column
                b[k].row = a[j].col;  // Assign column index to row
                b[k].col = a[j].row;  // Assign row index to column
                b[k].value = a[j].value;  // Copy the value
                k++;  // Move to the next element in the transposed matrix
            }
        }
    }
}

// Function to print a sparse matrix
void printSparseMatrix(SparseMatrix a[]) {
    int i;
    printf("Row\tColumn\tValue\n");
    for (i = 0; i <= a[0].value; i++) {
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].value);
    }
}

int main() {
    SparseMatrix a[MAX], b[MAX];
    int i, rows, cols, numTerms;

    // Input: Number of rows, columns, and non-zero elements
    printf("Enter the number of rows and columns in the matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the number of non-zero elements: ");
    scanf("%d", &numTerms);

    a[0].row = rows;
    a[0].col = cols;
    a[0].value = numTerms;

    // Input: Non-zero elements of the matrix
    printf("Enter row, column, and value for each non-zero element:\n");
    for (i = 1; i <= numTerms; i++) {
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
    }

    // Perform transpose
    transpose(a, b);

    // Output: Transposed matrix
    printf("\nTranspose of Sparse Matrix:\n");
    printSparseMatrix(b);

    return 0;
}

