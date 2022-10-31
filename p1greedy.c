#include <stdio.h>

int stocks(int n, int A[n]) {
    int i, buyPoint, buyPointVal, sellPointVal=0;


    for(i = 0; i < n; i++) {
        if(i == 0) {
            buyPointVal = A[0];
            buyPoint = 0;
        }
        else if(buyPointVal > A[i]) {
            buyPointVal = A[i];
            buyPoint = i;
        }
    }

    for(i = buyPoint+1; i < n; i++) {
        if(sellPointVal < A[i]) {
            sellPointVal = A[i];
        }
    }

    return (sellPointVal-buyPointVal);
}

int main() {
    int n, profit;
    int prices[100];

    printf("Enter the number of prices: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    profit = stocks(n, prices);

    printf("The profit is %d", profit);

    return 0;
}
