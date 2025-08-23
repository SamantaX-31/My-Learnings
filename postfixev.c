#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 20
int postfixev(char []);
void push(int[],int *, int);
int pop(int[],int *);
int main()
{
    char s[MAX];
    int Result;
    printf("Enter your postfix expression:");
    scanf("%s",s);
    Result = postfixev(s);

    printf("The result of the postfix exp is:%d\n",Result);
    return 0;
}
int postfixev(char s[])
{
    int a[MAX],top = -1,i,n1,n2,result;
    for(i=0;s[i]!='\0';i++)
    {
        if(isdigit(s[i]))
        {
            push(a,&top,s[i]-'0');
        }
        else
        {
            n1 = pop(a,&top);
            n2 = pop(a,&top);
            switch (s[i])
            {
                case '+':
                    result = n2 + n1;
                    break;
                case '-':
                    result = n2 - n1;
                    break;
                case '*':
                    result = n2 * n1;
                    break;
                case '/':
                    result = n2 / n1;
                    break;
            }
            push(a,&top,result);
        }
    }

    return pop(a,&top);
}
void push(int a[],int *top,int item)
{
    if(*top == MAX - 1)
    {
        printf("Stack is full\n");
        return;
    }
    (*top)++;
    a[*top]= item;    
}
int pop(int a[],int *top)
{
    int temp;
    
    if(*top == -1)
    {
        printf("Stack is empty\n");
        return -999;
    }
    temp = a[*top];
    (*top)--;
    return temp;
}
