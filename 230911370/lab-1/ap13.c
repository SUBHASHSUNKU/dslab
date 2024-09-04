#include <stdio.h>

#define ROWS 3
#define COLS 3

// Function to multiply two matrices
void multiplyMatrices(int A[ROWS][COLS], int B[ROWS][COLS], int C[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            C[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to add two matrices
void addMatrices(int A[ROWS][COLS], int B[ROWS][COLS], int C[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to check if a square matrix is a magic square
int isMagicSquare(int A[ROWS][COLS]) {
    int sum = 0;
    for (int i = 0; i < ROWS; i++) {
        sum += A[i][0];
    }
    for (int i = 0; i < ROWS; i++) {
        int rowSum = 0;
        int colSum = 0;
        for (int j = 0; j < COLS; j++) {
            rowSum += A[i][j];
            colSum += A[j][i];
        }
        if (rowSum != sum || colSum != sum) {
            return 0;
        }
    }
    return 1;
}

int main() {
  /*  int A[ROWS][COLS], B[ROWS][COLS], C[ROWS][COLS];

    // Read matrix A
    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Read matrix B
    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Multiply matrices A and B
    multiplyMatrices(A, B, C);
    printf("Product of matrices A and B:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Add matrices A and B
    addMatrices(A, B, C);
    printf("Sum of matrices A and B:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }*/
    printf("enter the matrix that you want to check whether it is a magic square or not: ");
    int M[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &M[i][j]);
        }
    }
    // Check if matrix M is a magic square
    if (isMagicSquare(M)) {
        printf("Matrix M is a magic square.\n");
    } else {
        printf("Matrix M is not a magic square.\n");
    }

    return 0;
}

