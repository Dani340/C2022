#include <stdio.h>

void Triangle(int n, int arr[]) {
    if (n == 1) {
        return;
    }
    else {
        for(int i = 0; i < n-1; i++) {
            arr[i] = arr[i] + arr[i+1];
            printf("%d ", arr[i]);
        }
        printf("\n");
        return Triangle(n-1, arr);
    }
}

int main() {
    int arr[100], n;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    Triangle(n, arr);

    return 0;
}

