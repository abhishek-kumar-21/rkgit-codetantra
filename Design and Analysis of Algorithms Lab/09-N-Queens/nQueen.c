#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 6

int totalSolutions = 0;

// Function to print the board in the specified format
void printSolution(int board[MAX_N][MAX_N], int N) {
    printf("Solution #%d:\n", totalSolutions);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1)
                printf("Q\t");
            else
                printf("*\t");
        }
        printf("\n");
    }
    // printf("\n");
}

// Function to check if a queen can be placed on the board at board[row][col]
bool isSafe(int board[MAX_N][MAX_N], int row, int col, int N) {
    // Check this column for any queen
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Check upper diagonal on right side
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

// Function to solve N-Queens problem using backtracking
bool solveNQueensUtil(int board[MAX_N][MAX_N], int row, int N) {
    if (row == N) {
        totalSolutions++;
        printSolution(board, N);
        return true;
    }

    bool foundSolution = false;

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;

            // Recur to place the rest of the queens
            foundSolution = solveNQueensUtil(board, row + 1, N) || foundSolution;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return foundSolution;
}

// Wrapper function to set up the board and start solving
void solveNQueens(int N) {
    int board[MAX_N][MAX_N] = {0};
    totalSolutions = 0;

    if (!solveNQueensUtil(board, 0, N)) {
        printf("Total solutions:0\n");
    } else {
        printf("Total solutions:%d\n", totalSolutions);
    }
}

int main() {
    int N;
    // printf("Enter the number of queens (1-6): ");
    scanf("%d", &N);

    /*
    if (N < 1 || N > 6) {
        printf("Invalid input. N must be between 1 and 6.\n");
        return 1;
    }
    */

    solveNQueens(N);

    return 0;
}
