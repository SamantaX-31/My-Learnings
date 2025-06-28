#include<stdio.h>
int main()
{
    float height,radius,pi=3.14;
    printf("Enter the height of your circle:\n");
    scanf("%f",&height);
    printf("Enter the radius of your circle:");
    scanf("%f",&radius);
    printf("The volume your circle is %f",pi*height*radius*radius);
    return 0;
}