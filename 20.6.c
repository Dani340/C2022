#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char digitSum(char n[], int k, int c) {
    int i, size, sum = 0;
    size = strlen(n);

    if (size == 1) {
        return n[0];
    }
    else {
        for(i = 0; i < size; i++) {
            sum += n[i]-48;
        }

        if(c == 0) {
            sum *= k;
        }

        itoa(sum, n, 10);
        return digitSum(n, k, c+1);
    }
}

int main() {
    char n[100], res;
    int i, k;

    scanf("%s", n);
    scanf("%d", &k);

    res = digitSum(n, k, 0);
    printf("%c", res);

    return 0;
}
