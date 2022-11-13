#include <stdio.h>
#include <string.h>

void findPermutations(char *A, int left, int right) {
    int aux;

    if(left == right) {
        printf("%s\n", A);
    }

    else {
        for(int i = left; i <= right; i++) {
            aux = A[left];
            A[left] = A[i];
            A[i] = aux;
            findPermutations(A, left+1, right);
            aux = A[left];
            A[left] = A[i];
            A[i] = aux;
        }
    }
}

int main() {
    int n;
    char A[100];

    printf("Enter the string: ");
    scanf("%s", A);

    n = strlen(A)-1;

    findPermutations(A, 0, n);

    return 0;
}
