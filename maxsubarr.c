#include <stdio.h>

int maxSubarrSumCross(int arr[], int left, int right, int mid) {
    int i, sum = 0, lsum = 0, rsum = 0, max;

    for(i = mid; i >= left; i--) {
        sum += arr[i];
        if(sum > lsum) {
            lsum = sum;
        }
    }

    sum = 0;
    for(i = mid; i <= right; i++) {
        sum += arr[i];
        if(sum > rsum) {
            rsum = sum;
        }
    }

    max = lsum + rsum - arr[mid];
    if(max < lsum) {
        max = lsum;
    }
    else if(max < rsum) {
        max = rsum;
    }

    return max;
}

int maxSubarrSum(int arr[], int left, int right) {
    if (left == right) {
        return arr[left];
    }

    int mid, L, R, C, max;

    mid = (left+right) / 2;

    L = maxSubarrSum(arr, left, mid-1);
    R = maxSubarrSum(arr, mid + 1, right);
    C = maxSubarrSumCross(arr, left, right, mid);

    if(L > R) {
        max = L;
    }
    else {
        max = R;
    }
    if(C > max) {
        max = C;
    }

    return max;
}

int main() {
    int i, n, max;
    int A[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the array\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    max = maxSubarrSum(A, 0, n-1);

    printf("The max sum is %d ", max);

    return 0;
}
