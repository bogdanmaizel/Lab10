//
// Created by mbogd on 5/01/2020.
//

#include "knightProblem.h"
#include <stdio.h>

void printSolution(int n, int **board) {
    for (int i=0;i<n;++i) {
        for (int j = 0; j < n; ++j)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

int stillInside(int i, int j, int n) {
    return (i>=0 && i<n && j>=0 && j<n);
}

void findPath(int i, int j, int n, int **board, int step) {
    if (step==n*n-1) {
        board[i][j]=step;
        printSolution(n, board);
    }
    else {
        board[i][j]=step;
        if (board[i-1][j-2]==0 && stillInside(i-1, j-2, n)) findPath(i-1, j-2, n, board, step+1);
        if (board[i-1][j+2]==0 && stillInside(i-1, j+2, n)) findPath(i-1, j+2, n, board, step+1);
        if (board[i+1][j-2]==0 && stillInside(i+1, j-2, n)) findPath(i+1, j-2, n, board, step+1);
        if (board[i+1][j+2]==0 && stillInside(i+1, j+2, n)) findPath(i+1, j+2, n, board, step+1);
        if (board[i-2][j-1]==0 && stillInside(i-2, j-1, n)) findPath(i-2, j-1, n, board, step+1);
        if (board[i-2][j+1]==0 && stillInside(i-2, j+1, n)) findPath(i-2, j+1, n, board, step+1);
        if (board[i+2][j-1]==0 && stillInside(i+2, j-1, n)) findPath(i+2, j-1, n, board, step+1);
        if (board[i+2][j+1]==0 && stillInside(i+2, j+1, n)) findPath(i+2, j+1, n, board, step+1);
    }
}
