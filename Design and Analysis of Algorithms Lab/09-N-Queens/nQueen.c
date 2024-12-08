#include <stdio.h>
#include <stdbool.h>

#define MAX_N 6
int board[MAX_N];
int solutions=0;

// Function to print the board
void printSolution(int n) {
    printf("Solution #%d:\n", ++solutions);
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            if (board[row] == col) {
                printf("Q\t");  // Print Queen
            } else {
                printf("*\t");  // Print Empty Cell
            }
        }
        printf("\n");
    }
}


bool isSafe(int row, int col, int n) {
    for (int prevRow = 0; prevRow < row; ++prevRow) {
        if (board[prevRow] == col || board[prevRow] - prevRow == col - row || board[prevRow] + prevRow == col + row) {
            return false;
        }
    }
    return true;
}
// Backtracking function to solve N-Queens problem
void solveNQueens(int row, int n) {
    if (row == n) {
        printSolution(n);  
        return;
    }
    for (int col = 0; col < n; ++col) {
        if (isSafe(row, col, n)) {
            board[row] = col;  // Place queen
            solveNQueens(row + 1, n);  // Recur for the next row
        }
    }
}

void main() {
    int n;
    scanf("%d", &n);
   solveNQueens(0,n);printf("Total solutions:%d\n",solutions);
}
