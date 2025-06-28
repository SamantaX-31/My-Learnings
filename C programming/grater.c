#include<stdio.h>
int main()
{
    int num1,num2,num3,num4;
    int max;
    printf("Enter Your four Numbers\n");
    scanf("%d%d%d%d",&num1,&num2,&num3,&num4);
    
    if(num1>=num2 && num1>=num3 && num1>=num4)
    {
        max=num1;
    }
    
    else if(num2>=num1 && num2>=num3 && num2>=num4)
    {
        max=num2;
    }
    
    else if(num3>=num1 && num3>=num2 && num3>=num4)
    {
        max=num3;
    }
    
    else
    {
        max=num4;
    }
    printf("The gratest number is %d", max);
}