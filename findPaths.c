#include <stdio.h>

int isSafe(int i, int j, int r, int c)
{
    return (i >= 0 && i < r && j >= 0 && j < c);
}

int solvePathsUtil(int r, int c, int mat[r][c], int i, int j, int movec, int *sol, int iMove[], int jMove[])
{
    int x=0, k, next_i, next_j;
    if (i == r-1 && j == c-1) {
        while(sol[x] != -1) {
            printf("%d ", sol[x]);
            x++;
        }
        printf("\n");
        return 1;
    }
    else if(i >= r || j >= c) {
        return 0;
    }

    for (k = 0; k < 3; k++) {
        next_i = i + iMove[k];
        next_j = j + jMove[k];
        if (isSafe(next_i, next_j, r, c)) {
            sol[movec] = mat[next_i][next_j];
            if (solvePathsUtil(r, c, mat, next_i, next_j, movec + 1, sol, iMove, jMove) == 1) {
                movec = 1;
                sol[0] = mat[0][0];
                for (int i = 1; i < r*c; i++) {
                    sol[i] = -1;
                }
                return 1;
            }
            else {
                sol[movec] = -1;
            }
        }
    }

    return 0;
}

void solvePaths(int r, int c, int mat[r][c])
{
    int sol[r*c];
    for (int i = 1; i < r*c; i++) {
        sol[i] = -1;
    }

    int iMove[3] = {1, 0, 1};
    int jMove[3] = {1, 1, 0};

    sol[0] = mat[0][0];

    solvePathsUtil(r, c, mat, 0, 0, 1, sol, iMove, jMove);
}

int main() {
    int r, c;
    int A[100][100];

    printf("Enter the number of rows: ");
    scanf("%d", &r);

    printf("Enter the number of columns: ");
    scanf("%d", &c);

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    solvePaths(r, c, A);
    return 0;
}
