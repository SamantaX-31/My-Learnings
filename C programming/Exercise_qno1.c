#include<stdio.h>

double power(double x, int n)
    {
        if (n==0)
        {
            return 1;
        }
        
        else if(n>0)
        {
            return x* power(x,n-1);
        }
        
        else
        {
            return 1/power(x,n);
        }
    }
    int main()
        {
            double x;
            int n;
            printf("Enter your number\n");
            scanf("%lf", &x);
            
            printf("Enter your number's power\n");
            scanf("%d", &n);
            
            double result= power(x,n);
            printf("Result= %f",result);
            return 0;  
        }