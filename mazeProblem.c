//
// Created by mbogd on 5/01/2020.
//

#include "mazeProblem.h"
#include <stdio.h>
#include <stdlib.h>
void printMatrix(int **solution, int m, int n) {
    for (int i=0;i<m;++i) {
        for (int j = 0; j < n; ++j)
            printf("%d ", solution[i][j]);
        printf("\n");
    }
}

int** initSolution(int m, int n) {
    int **sol = (int**)malloc(m* sizeof(int*));
    for (int i=0;i<m;++i) {
        sol[i] = (int *) malloc(n * sizeof(int));
        for (int j = 0; j < n; ++j) sol[i][j] = 0;
    }
    return sol;
}

void labyrinthExit(int i, int j, int m, int n, int **a, int **solution) {//p3.13
    if ((i==0 || j==0 || i==m-1 || j==n-1)&&a[i][j]==1) printMatrix(solution,m,n);
    else {
        solution[i][j]=1;
        if (a[i-1][j]==1 && solution[i-1][j]==0) labyrinthExit(i-1, j, m, n, a, solution);
        if (a[i][j+1]==1 && solution[i][j+1]==0) labyrinthExit(i, j+1, m, n, a, solution);
        if (a[i+1][j]==1 && solution[i+1][j]==0) labyrinthExit(i+1, j, m, n, a, solution);
        if (a[i][j-1]==1 && solution[i][j-1]==0) labyrinthExit(i, j-1, m, n, a, solution);
    }
}
