#include <stdio.h>

int Sum(int list[], int i, int n) {
    if (i < n) {
        if (list[i] % 2 == 0) {
            return list[i] + Sum(list, i+1, n);
        }
        else {
            return Sum(list, i+1, n);
        }
    }
    else {
        return 0;
    }
}

int main() {
    int list[100], sum, i, n;
    
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }
    i = 0;

    sum = Sum(list, i, n);

    printf("%d", sum);
    
    return 0;
}

