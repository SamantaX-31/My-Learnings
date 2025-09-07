#include<stdio.h>
#include<ctype.h>
#define MAX 100
void infix_to_postfix(char[],char[]);
int postfixev(char[]);
void push(char[],int *,char);
char pop(char[],int *);
int precedence(char);
int main()
{
    char infex[MAX],post[MAX];
    double result;
    printf("Enter your infix expression:");
    scanf("%s",infex);
    infix_to_postfix(infex,post);
    printf("The Postfix Expression:%s\n",post);
    result = postfixev(post);
    printf("The result is:%lf\n",result);
    return 0;
}
void infix_to_postfix(char infix[],char post[])
{
    char stack[MAX];
    int top = -1,i,j=0;
    push(stack,&top,'(');
    for(i=0;infix[i]!='\0';i++)
    {
        if(isalnum(infix[i]))
        {
            post[j++] = infix[i];
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
                post[j++] = pop(stack, &top);
            }
        }
        else
            {
                while(precedence(infix[i])<=precedence(stack[top]))
                {
                    post[j++]= pop(stack,&top);
                }
                push(stack,&top,infix[i]);
            }
    }
    while(stack[top] != '(')
    {
        post[j++] = pop(stack, &top);
    }
    post[j]='\0';
   
}
int postfixev(char post[])
{
    int top = -1,i,n1,n2,result;
    char a[MAX];
    for(i=0;post[i]!='\0';i++)
    {
        if(isdigit(post[i]))
        {
            push(a,&top,post[i]-'0');
        }
        else
        {
            n1 = pop(a,&top);
            n2 = pop(a,&top);
            switch (post[i])
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