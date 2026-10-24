#include <iostream>
using namespace std;

int isPerfect(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

void printPerfect(int i) {
    if (isPerfect(i)) {
        printf("%d=", i);
        int sum = 0;
        for (int j = 1; j <= i / 2; j++) {
            if (i % j == 0) {
                sum += j;
                printf("%d", j);
                if (sum < i) {
                    printf("+");
                }
            }
        }
        printf("\n");
    }
}

int main() {
    int count = 0;
    for (int i = 1; i<= 20000; i++) {
        printPerfect(i);
        if (isPerfect(i)) {
            count++;
        }
    }
    printf("Total perfect numbers: %d\n", count);
    return 0;
}