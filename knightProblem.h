//
// Created by mbogd on 5/01/2020.
//

#ifndef LAB10_KNIGHTPROBLEM_H
#define LAB10_KNIGHTPROBLEM_H

void printSolution(int n, int **board);
int stillInside(int i, int j, int n);
void findPath(int i, int j, int n, int **board, int step);

#endif //LAB10_KNIGHTPROBLEM_H
