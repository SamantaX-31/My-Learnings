#include<stdio.h>
#include<math.h>
int main()
{
    float a,b;
    printf("Enter the value of a\n");
    scanf("%f",&a);
    printf("Enter the Value of a'\n");
    scanf("%f",&b);
    printf("The Value is %f\n", pow(a,b));
    return 0;  
}