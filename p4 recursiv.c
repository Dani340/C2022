#include <stdio.h>

int biggest(int arr[], int i, int n, int max) {
    if (i == n) {
        return max;
    }
    else {
        if(max < arr[i]) {
            max = arr[i];
        }
        return biggest(arr, i+1, n, max);
    }
}

int main() {
    int arr[100];
    int res, i, n;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    i = 0;

    res = biggest(arr, i, n, 0);

    printf("%d", res);

    return 0;
}
