#include <stdio.h>

int Binary(int n) {
    if (n == 0) {
        return 0;
    }
    else {
        return (n%2) + 10 * Binary(n/2);
    }
}

int main() {
    int binary, n;
    
    scanf("%d", &n);

    binary = Binary(n);

    printf("%d", binary);
    
    return 0;
}

