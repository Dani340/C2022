#include <stdio.h>

int superDigit(int n) {
    int sum = 0;

    if (n < 10) {
        return n;
    }
    else {
        while(n != 0) {
            sum += n%10;
            n /= 10;
        }
        return superDigit(sum);
    }
}

int main() {
    int n, digit;

    scanf("%d", &n);

    digit = superDigit(n);

    printf("%d", digit);

    return 0;
}

