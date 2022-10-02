#include <stdio.h>

void Reverse(int i, int n, int arr[]) {
    int aux;

    if(i < n) {
        aux = arr[i];
        arr[i] = arr[n];
        arr[n] = aux;

        Reverse(i+1, n-1, arr);
    }
}

int main() {
    int arr[100], n;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Reverse(0, n-1, arr);

    for(int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }

    return 0;
}

