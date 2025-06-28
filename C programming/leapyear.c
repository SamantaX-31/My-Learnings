#include <stdio.h>

int main() {
    int year;

    printf("Enter a year: ");
    scanf("%d", &year);

    
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("your entered year is a leap year.\n", year);
    } else {
        printf("your entered year is not a leap year.\n", year);
    }

    return 0;
}