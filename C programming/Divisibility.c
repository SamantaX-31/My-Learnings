#include<stdio.h>
#include<math.h>
int main()
//write a Program to determine whether a number divisible by 97 or not
{
    int num;
    printf("Enter the number\n");
    scanf("%d",&num);
    printf("Divisibility test Returns: %d\n", num%97);
    return 0;  
}