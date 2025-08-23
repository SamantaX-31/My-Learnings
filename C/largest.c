#include<stdio.h>

int main()
{
    int a, b, c, max;
    printf("Enter three numbers you want to compare: ");
    scanf("%d %d %d", &a, &b, &c); 

    if (a >= b) 
    {
        if (a >= c)
        {
            max = a;
        }
        else 
        {
            max = c;
        }
    }
    else 
    {
        if (b >= c)
        {
            max = b;
        }
        else 
        {
            max = c;
        }
    }

    printf("Max = %d\n", max); 
    return 0;
}