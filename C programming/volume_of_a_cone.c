#include<stdio.h>
int main()
{
    float height,radius,pi=3.14,a=0.333333333;
    printf("Enter the height of your cone:\n");
    scanf("%f",&height);
    printf("Enter the radius of your cone:");
    scanf("%f",&radius);
    printf("The volume your cone is %f",pi*a*height*radius*radius);
    return 0;
}