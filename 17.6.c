#include <stdio.h>

void triangle(int arr[], int n) {
    int i, aux;

    if (n == 1) {
        printf("%d", arr[0]);
        return;
    }
    else {
        for(i = 0; i < n-1; i++) {
            printf("%d ", arr[i]);
            arr[i] += arr[i+1];
        }
        printf("%d\n", arr[n-1]);
        return triangle(arr, n-1);
    }
}

int main() {
    int arr[100];
    int i, n;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

    }

    printf("\n");
    triangle(arr, n);

    return 0;
}
