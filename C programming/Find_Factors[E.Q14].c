#include <stdio.h>
#include <math.h>
void find_factors(int n) {
    printf("Factors of %d are: ", n);
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    find_factors(n);
    return 0;
}