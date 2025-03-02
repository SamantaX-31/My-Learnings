#include<stdio.h>
#define pi 3.14159
int main()
{
    float radius, volume;
    printf("Enter the radius of your sphere:");
    scanf("%f",&radius);
    printf("The volume your sphere is %f",(4*pi*radius*radius*radius)/3);
    return 0;
}