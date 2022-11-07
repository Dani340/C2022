#include <stdio.h>

int binarySqrt(int x, int left, int right, int res) {
    if(x == 0 || x == 1) {
        return x;
    }

    if(left <= right) {
        int mid;

        mid = (left+right) / 2;

        if(mid * mid == x) {
            return mid;
        }
        else if(mid <= x / mid) {
            res = binarySqrt(x, mid+1, right, mid);
        }
        else if(mid >= x / mid) {
            res = binarySqrt(x, left, mid-1, res);
        }
    }

    return res;
}

int main() {
    int i, x, res;

    printf("Enter the number x: ");
    scanf("%d", &x);

    res = binarySqrt(x, 1, x, 0);

    printf("The floored sqrt of %d is %d", x, res);

    return 0;
}
