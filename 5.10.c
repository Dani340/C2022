#include <stdio.h>

void greedyTaskSchedule(int n, int A[n][2]) {
    int i, j, k[100], aux, bool1[100];

    for(i = 0; i < n-1; i++) {
        bool1[i] = 0;
        for(j = i + 1; j < n; j++) {
            if(A[i][1] < A[j][1]) {
                aux = A[i][1];
                A[i][1] = A[j][1];
                A[j][1] = aux;

                aux = A[i][0];
                A[i][0] = A[j][0];
                A[j][0] = aux;
            }
        }
    }
    bool1[n-1] = 0;
    for(i = 0; i < n; i++) {
        printf("%d %d\n", A[i][0], A[i][1]);
    }

    for(i = 0; i < n; i++) {
        for(j = A[i][1]-1; j >= 0; j--) {
            if(bool1[j] == 0) {
                bool1[j] = 1;
                k[j] = i+1;
                break;
            }
        }
    }

    for(i = 0; i < n; i++) {
        if(bool1[i] == 1) {
            printf("%d ", k[i]);
        }
    }

}

int main() {
    int n, i;
    int A[100][2];

    printf("Enter the number of tasks: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter the deadline for task number %d: ", i+1);
        scanf("%d", &A[i][0]);
        printf("Enter the profit for task number %d: ", i+1);
        scanf("%d", &A[i][1]);
    }

    greedyTaskSchedule(n, A);

    return 0;
}
