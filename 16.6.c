#include <stdio.h>

int* insertionSort(int arr[], int i, int n) {
    int j, aux;

    if(i == n) {
        return arr;
    }
    else {
        j = i-1;
        aux = arr[i];

        while (aux < arr[j] && j >= 0) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = aux;

        return insertionSort(arr, i+1, n);
    }
}


int main() {
    int arr[100];
    int *arrnew;
    int i, n;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    arrnew = insertionSort(arr, 1, n);

    for(i = 0; i < n; i++) {
        printf("%d ", *(arrnew + i));
    }

    return 0;
}
