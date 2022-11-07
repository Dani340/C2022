#include <stdio.h>

int computePower(int x, int n) {
    int res;

    if(n == 0) {
        return 1;
    }

    res = computePower(x, n/2);

    if(n % 2 == 0) {
        return res * res;
    }
    else {
        return res * res * x;
    }
}

int main() {
    int n, x, res;

    printf("Enter the number x: ");
    scanf("%d", &x);

    printf("Enter the power of x: ");
    scanf("%d", &n);

    res = computePower(x, n);

    printf("The result is %d", res);

    return 0;
}
