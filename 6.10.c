#include <stdio.h>

int toyBox(int n, int m, int A[n][2]) {
    int i, k[100], sum = 0;

    for(i = 0; i < m; i++) {
        k[i] = 0;
    }

    for(i = 0; i < n; i++) {
        if(A[i][0] > k[A[i][1]-1]) {
            k[A[i][1]-1] = A[i][0];
        }
    }

    for(i = 0; i < m; i++) {
        sum += k[i];
    }

    return sum;
}

int main() {
    int n, m, max;
    int A[100][2];

    printf("Enter the number of toys and, respectively, toy boxes\n");
    scanf("%d", &n);
    scanf("%d", &m);

    for(int i = 0; i < n; i++) {
        printf("Enter the price for toy number %d: ", i+1);
        scanf("%d", &A[i][0]);
        printf("Enter the box number assigned to toy number %d: ", i+1);
        scanf("%d", &A[i][1]);
    }

    max = toyBox(n, m, A);

    printf("%d", max);

    return 0;
}
