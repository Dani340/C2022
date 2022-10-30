#include <stdio.h>
#include <string.h>

char letterSearch(char arr[], int n, char letter) {
    if(letter < arr[0] || arr[n-1] <= letter) {
        return arr[0];
    }
    else {
        int mid, left = 0, right = n-1;

        while(right - left > 1) {
            mid = (left + right) / 2;

            if(arr[mid] == letter) {
                return arr[mid+1];
            }

            else if(letter > arr[mid]) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        return arr[right];
    }

}

int main() {
    int i, n;
    char res, l;
    char A[100];

    printf("Enter the number of chars: ");
    scanf("%d", &n);

    printf("Enter the array\n");
    for(i = 0; i < n; i++) {
        scanf(" %c", &A[i]);
    }

    printf("Enter the letter to search for: ");
    scanf(" %c", &l);

    res = letterSearch(A, n-1, l);

    printf("%c", res);

    return 0;
}
