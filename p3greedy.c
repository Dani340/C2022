#include <stdio.h>

int coinsGreedy(int V) {
    int n = 10;
    int i, count = 0, coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

    n--;
    while(V != 0) {
        if(V - coins[n] >= 0) {
            V -= coins[n];
            count++;
        }
        else {
            n--;
        }
    }

    return count;
}

int main() {
    int V, count;

    printf("Enter the value: ");
    scanf("%d", &V);

    count = coinsGreedy(V);

    printf("%d", count);

    return 0;
}
