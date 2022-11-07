#include <stdio.h>

int binaryCount(int arr[], int left, int right, int count) {
    if(arr[right] == 0) {
        return 0;
    }

    if(arr[left] == 1) {
        return right-left+1;
    }

    int mid, L, R;

    mid = (left+right) / 2;

    count += binaryCount(arr, left, mid, count);
    count += binaryCount(arr, mid+1, right, count);

    return count;
}

int main() {
    int i, n, count;
    int A[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the array\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    count = binaryCount(A, 0, n-1, 0);

    printf("The number of 1's is %d", count);

    return 0;
}
