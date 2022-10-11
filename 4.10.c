#include <stdio.h>

int greedyTrainSchedule(int n, float A[n][2]) {
    int count = 1, x = 1, k[100], bool1;

    k[0] = 0;
    for(int i = 1; i < n; i++) {
        bool1 = 0;
        for(int j = 0; j < x; j++) {
            if(A[i][0] >= A[k[j]][1]) {
                k[j] = i;
                bool1 = 1;
                break;
            }
        }
        if(bool1 == 0) {
            count++;
            k[x] = i;
            x++;
        }
    }

    return count;
}

int main() {
    int n, i;
    float A[100][2];
    int count;

    printf("Enter the number of time periods: ");
    scanf("%d", &n);
    printf("Enter the arrival times for the trains\n");
    for(i = 0; i < n; i++) {
        scanf("%f", &A[i][0]);
    }
    printf("Enter the departure times for the trains\n");
    for(i = 0; i < n; i++) {
        scanf("%f", &A[i][1]);
    }

    count = greedyTrainSchedule(n, A);

    printf("%d", count);

    return 0;
}
