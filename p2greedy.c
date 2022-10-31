#include <stdio.h>

void intervalsGreedy(int n, int A[n][2]) {
    int i, k = 0, aux;

    for(i = 0; i < n-1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(A[i][0] > A[j][0]) {
                aux = A[i][1];
                A[i][1] = A[j][1];
                A[j][1] = aux;

                aux = A[i][0];
                A[i][0] = A[j][0];
                A[j][0] = aux;
            }
        }
    }

    for(i = 1; i < n; i++) {
        if(A[i-1][1] >= A[i][0] && A[i-1][1] <= A[i][1]) {
            A[i][0] = A[i-1][0];
            k = i;
        }
        else if(A[i-1][1] >= A[i][0] && A[i-1][1] > A[i][1]) {
            A[i][0] = A[i-1][0];
            A[i][1] = A[i-1][1];
            k = i;
        }
    }

    for(i = k; i < n; i++) {
        printf("(%d, %d) ", A[i][0], A[i][1]);
    }

}

int main() {
    int n, m, max;
    int A[100][2];

    printf("Enter the number of intervals: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter the start time for interval number %d: ", i+1);
        scanf("%d", &A[i][0]);
        printf("Enter the finish time for interval number %d: ", i+1);
        scanf("%d", &A[i][1]);
    }

    intervalsGreedy(n, A);

    return 0;
}
