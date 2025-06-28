#include<stdio.h>
int main()
{
    int repeat = 0 ;
    printf("How strong is your love 1-10? :");
    scanf("%d", &repeat);
    printf("\n I Love You Very");
    while(repeat>0)
    {
        printf("\n very");
        repeat--;
    };
    printf("much.\n\n");
    return 0;
    
};