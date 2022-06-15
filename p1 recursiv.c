#include <stdio.h>

int product(int list[], int i, int n) {
    if (i < n) {
        return list[i] * product(list, i+1, n);
    }
    else {
        return 1;
    }
}

int main() {
    int list[100], produs, i, n;
    
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }
    i = 0;

    produs = product(list, i, n);

    printf("%d", produs);
    
    return 0;
}
