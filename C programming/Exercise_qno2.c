#include<stdio.h>
#include<math.h>
double fourthroot(int k)
{
    return sqrt(sqrt(k));
}
int main()
{
    int i;
    printf("Fourth Root of K\n");
    for (i=1;i<=10;i++)
    {
        printf("%d\t%f\n",i, fourthroot(i));
    }
    return 0;
}