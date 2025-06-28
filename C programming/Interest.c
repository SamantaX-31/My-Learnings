#include<stdio.h>
int main()
{
    int principal=100, rate=4, years=1;
    int simpleinterest = (principal * rate * years)/100;
    printf("The value of Simple Interest is %d",simpleinterest);
    return 0;
}