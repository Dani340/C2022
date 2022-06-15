#include <stdio.h>
#include <math.h>

int prime(int num, int i, int n) {
    if (i > n) {
        return 1;
    }
    else {
        if(num % i == 0) {
            return 0;
        }
        else {
            return prime(num, i+1, n);
        }
    }
}

int main() {
    int num;
    int res, i, n;

    scanf("%d", &num);

    i = 2;
    n = sqrt(num);

    res = prime(num, i, n);

    if(res == 1) {
        printf("True");
    }
    else {
        printf("False");
    }

    return 0;
}
