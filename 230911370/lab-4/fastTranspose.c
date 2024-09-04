#include <stdio.h>

#define MAX 100

// Structure to represent a sparse matrix element
typedef struct {
    int row;
    int col;
    int value;
} SparseMatrix;

// Function to find the fast transpose of a sparse matrix
void fastTranspose(SparseMatrix a[], SparseMatrix b[]) {
    int rowTerms[MAX], startPos[MAX];
    int i, j, numCols = a[0].col, numTerms = a[0].value;

    // Step 1: Initialize the first element of the transposed matrix
    b[0].row = numCols;
    b[0].col = a[0].row;
    b[0].value = numTerms;

    if (numTerms > 0) {
        // Step 2: Initialize row terms array
        for (i = 0; i < numCols; i++) {
            rowTerms[i] = 0;
        }

        // Step 3: Count the number of elements in each column of the original matrix
        for (i = 1; i <= numTerms; i++) {
            rowTerms[a[i].col]++;
        }

        // Step 4: Calculate starting position for each column in transposed matrix
        startPos[0] = 1;
        for (i = 1; i < numCols; i++) {
            startPos[i] = startPos[i - 1] + rowTerms[i - 1];
        }

        // Step 5: Place elements in their correct position in transposed matrix
        for (i = 1; i <= numTerms; i++) {
            j = startPos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
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

    // Perform fast transpose
    fastTranspose(a, b);

    // Output: Transposed matrix
    printf("\nFast Transpose of Sparse Matrix:\n");
    printSparseMatrix(b);

    return 0;
}

