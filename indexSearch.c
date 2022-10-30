#include <stdio.h>

int indexSearch(int arr[], int left, int right, int num) {
    int i, mid;

    mid = (left + right) / 2;

    if(left > right) {
        return -1;
    }
    else {
        if(arr[mid] == num) {
            return mid;
        }
        else if(num > arr[mid]) {
            indexSearch(arr, mid+1, right, num);
        }
        else {
            indexSearch(arr, left, mid-1, num);
        }
    }

}

int main() {
    int i, n, index, num;
    int A[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the array\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Enter the number to search for: ");
    scanf("%d", &num);

    index = indexSearch(A, 0, n-1, num);

    printf("%d", index);

    return 0;
}
