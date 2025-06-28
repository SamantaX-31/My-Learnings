#include<stdio.h>
#include<conio.h>
int main()
{
    float height,radius,pi=3.14;
    printf("Enter the height of your cilinder:\n");
    scanf("%f",&height);
    printf("Enter the radius of your cilinder:");
    scanf("%f",&radius);
    printf("The volume your cilinder is %f",pi*height*radius);
    return 0;
}