/* Fibonacci............................
A=0,B=1
F(Fibonacci)=A+B+(A+B)+(B+A+B)+......+(n-2+n-1)+n */


#include<stdio.h>
int main()
{
    int fibonacci(int n)
    {
        if(n==0)
    {
        return 0;
    }

    else if(n==1)
    {
        return 1;
    }

    else
    {
        return fibonacci(n-2)+fibonacci(n-1);
    }
    }
    
    
    int n;
    printf("Enter your number\n",n);
    scanf("%d",&n);


    for(int i=0;i<=n;i++)
    {
        printf("Result is %d\n",fibonacci(i));
    }
    return 0;
}

