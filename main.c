#include <stdio.h>
#include "mazeProblem.h" //problem 3.13
#include "knightProblem.h" //problem 3.14

double h(int n, double x) { //problem 3.2
    if (!n) return 1;
    if (n==1) return 2*x;
    return 2 * n * h(n-1, x) - 2 * (n-1) * h(n-2,x);
}

int main() {
    printf("choose the problem to solve:\n");
    printf("a) 3.2\nb) 3.13\nc) 3.14\n");
    int option=getchar()-'a';
    getchar();
    switch (option) {
        case 0: { ///3.2
            printf("Enter values for n and x:\n");
            int n,x;
            scanf("%d\n%lf", &n, &x);
            printf("%lf\n", h(n,x));
            break;
        }
        case 1: { ///3.13
            printf("Enter values for m,n,i,j and the maze matrix\n");
            int m,n,x,y, **a, **s;
            scanf("%d\n%d\n%d\n%d\n", &m, &n, &x, &y);
            s=initSolution(m,n);
            a=initSolution(m,n);
            for (int i=0;i<m;++i)
                for (int j=0;j<n;++j)
                    scanf("%d", a[i][j]);
            labyrinthExit(x,y,m,n,a,s);
        }
        case 2: { ///3.14
            printf("Enter dimension of table:\n");
            int n;
            scanf("%d\n", &n);
            int **board=initSolution(n,n);
            findPath(0,0,n,board,0);
        }
    }
    return 0;
}
