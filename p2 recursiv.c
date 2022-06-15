#include <stdio.h>
#include <string.h>

int palindrom(char string[], int i, int n) {
    if (i > n || i == n) {
        return 1;
    }
    else {
        if(string[i] != string[n]) {
            return 0;
        }
        else {
            return palindrom(string, i+1, n-1);
        }
    }
}

int main() {
    char string[100];
    int res, i, n;
    
    scanf("%s", string);
    
    i = 0;
    n = strlen(string)-1;

    res = palindrom(string, i, n);

    if(res == 1) {
        printf("True");
    }
    else {
        printf("False");
    }
    
    return 0;
}