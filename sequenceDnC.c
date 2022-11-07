#include <stdio.h>

int sequenceDnC(int A[], int left, int right, int r) {

    if(right - left == 1) {
        if(A[right] - A[left] != r) {
            return A[left]+r;
        }
        else {
            return 0;
        }
    }

    int mid, res = 0;

    mid = (left+right) / 2;

    res += sequenceDnC(A, mid, right, r);
    if(res > 0) {
        return res;
    }
    res += sequenceDnC(A, left, mid, r);


    return res;
}

int main() {
    int i, n, r, res;
    int A[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the array\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    r = (A[n-1]-A[0]) / n;

    res = sequenceDnC(A, 0, n-1, r);

    printf("%d", res);

    return 0;
}
