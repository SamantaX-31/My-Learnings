#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 20
void in_to_post(char[],char[]);
void push(char[],int *,char);
char pop(char[],int *);
int prec(char);
int isop(char);
int main()
{
    char in[MAX],post[MAX];
    printf("Enter your infix Expression:");
    scanf("%s",in);
    in_to_post(in,post);
    printf("Your Postfix Expression is:%s",post);
    return 0;
}
void in_to_post(char in[], char post[])
{
    int i=0,j = 0,top = -1;
    char stack[MAX], x;
    strcat(in,")");
    push(stack,&top,'(');
    while(top!=-1)
    {
        if(isalpha(in[i]))
        {
            post[j++]=in[i];
        }
        else if(in[i]=='(')
        {
            push(stack,&top,'(');
        }
        else if(in[i]==')')
        {
            while((x=pop(stack,&top))!= '(')
            {
                post[j++]=x;
            }
        }
        else
        {
            while(isop(stack[top]) && prec(stack[top])>=prec(in[i]))
            {
                post[j++]= pop(stack,&top);
            }
            push(stack,&top,in[i]);
        }
        i++;
    }
    post[j]='\0';
}
void push(char stack[],int *top,char c)
{
    if(*top == MAX - 1)
    {
        printf("Stack is full");
        return;
    }
    (*top)++;
    stack[*top] = c;
}
char pop(char stack[],int *top)
{
    char temp;
    if(*top == - 1)
    {
        printf("Stack is Empty\n");
    }
    temp = stack[*top];
    (*top)--;
    return temp;
}
int isop(char c)
{
    switch(c)
    {
        case '^':
        case '*':
        case '/':
        case '-':
        case '+':return 1;break;
        default: return 0;
    }
}
int prec(char c)
{
    switch(c)
    {
        case '^':return 3;
        case '*':
        case '/':return 2;
        case '+':
        case '-':return 1;
        default: return 0;
    }
}