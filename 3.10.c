#include <stdio.h>
#include <stdlib.h>

int **greedyActivitySelector(int n, int A[n][2]) {
    int i, aux, k = 0, x = 1;

    int** S = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        S[i] = (int*)malloc(2 * sizeof(int));
    }

    for(i = 0; i < n-1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(A[i][1] > A[j][1]) {
                aux = A[i][1];
                A[i][1] = A[j][1];
                A[j][1] = aux;

                aux = A[i][0];
                A[i][0] = A[j][0];
                A[j][0] = aux;
            }
        }
    }

    S[0][0] = A[0][0];
    S[0][1] = A[0][1];

    for(i = 1; i < n; i++) {
        if(A[i][0] >= A[k][1]) {
            S[x][0] = A[i][0];
            S[x][1] = A[i][1];
            k = i;
            x++;
        }
    }

    S[x][0] = -1;
    return S;
}

int main() {
    int n, i, A[100][2];
    int **S;

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter the start time for activity number %d: ", i+1);
        scanf("%d", &A[i][0]);
        printf("Enter the finish time for activity number %d: ", i+1);
        scanf("%d", &A[i][1]);
    }

    S = greedyActivitySelector(n, A);

    i = 0;
    while(S[i][0] != -1) {
        printf("(%d, %d); ", S[i][0], S[i][1]);
        i++;
    }

    for (i = 0; i < n; i++)
        free(S[i]);

    free(S);

    return 0;
}

