#include<stdio.h>
int main()
{
    float height,base;
    float a=0.5;
    printf("Enter the height of your triangle:\n");
    scanf("%f",&height);
    printf("Enter the basee of your triangle:\n");
    scanf("%f",&base);
    printf("Area of the traingle is %f",a*height*base);
    return 0;
}