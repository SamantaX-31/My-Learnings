#include<stdio.h>
#include<ctype.h>
#define MAX 100
void infix_to_postfix(char[]);
void push(char[],int *,char);
char pop(char[],int *);
int precedence(char);
int main()
{
    char infex[MAX];
    printf("Enter your infix expression:");
    scanf("%s",infex);
    infix_to_postfix(infex);

    return 0;
}
void infix_to_postfix(char infix[])
{
    char stack[MAX];
    int top = -1,i,j=0;
    char result[MAX];
    push(stack,&top,'(');
    for(i=0;infix[i]!='\0';i++)
    {
        if(isalpha(infix[i]))
        {
            result[j++] = infix[i];
        }
        else if(infix[i]=='(')
            {
                push(stack,&top,infix[i]);
            }
        else if(infix[i] == ')')
        {
            while(stack[top] != '(') 
            {
                if(stack[top] == '(') 
                {
                    pop(stack, &top);
                    break;
                }
                result[j++] = pop(stack, &top);
            }
        }
        else
            {
                while(precedence(infix[i])<=precedence(stack[top]))
                {
                    result[j++]= pop(stack,&top);
                }
                push(stack,&top,infix[i]);
            }
    }
    while(stack[top] != '(')
    {
        result[j++] = pop(stack, &top);
    }
    result[j]='\0';
    printf("The Postfix Expression:%s\n",result);
}
void push(char stack[], int *top, char item )
{
    if(*top == MAX -1)
    {
        printf("Stack is Full");
        return;
    }
    (*top)++;
    stack[*top]=item;
}
char pop(char stack[],int *top)
{
    char temp;
    if(*top == -1)
    {
        printf("Stack is empty");
        return '#';
    }
    temp = stack[*top];
    (*top)--;
    return temp;
}
int precedence(char stack)
{
    switch (stack)
    {
    case '^':return 3;break;
    case '*':
    case '/':return 2;break;
    case '+':
    case '-':return 1;break;
    default: return -999;
    }
}