#include <stdio.h>
#include<string.h>
#include<ctype.h>
#define max 20
void infix2postfix(char [], char []);
void push(char [], int *, char);
char pop(char [], int *);
int priority(char );
int isoperator(char);
int main()
{
    char infix[50], postfix[50];
    printf("Enter in infix expression");
    scanf("%s", infix);
    infix2postfix(infix, postfix);
    printf("postfix expression is=%s", postfix);

    return 0;
}



void infix2postfix(char in[], char post[])
{
    char stack[max], x;
    int i, top=-1, j;
    i=j=0;
    strcat(in, ")");
    push(stack, &top, '(');
    while(top!=-1)
    {
       if(isalpha(in[i])) // This line is corrected to handle numbers and letters
            post[j++]=in[i];
        else if(in[i]=='(')
                push(stack, &top, '(');
        else if(in[i]==')')
                {
                   while((x=pop(stack, &top)) !='(')
                        post[j++]=x;
                }
        else
            {
                while(isoperator(stack[top]) && priority(stack[top])>=priority(in[i]))
                    post[j++]=pop(stack, &top);
                push(stack, &top, in[i]);
            }
            i++;
    }
    post[j] = '\0';
}
void push(char st[], int *ptr, char item)
{
    if(*ptr == max-1)
    {
        printf("Stack is full ");
        return;
    }
    
    (*ptr)++;
    st[*ptr]=item;
}

char pop(char st[], int *ptr)
{
    char item;
    if(*ptr==-1)
    {
        printf("Stack is empty ");
        return -1;
    }
    
    item=st[*ptr];
    (*ptr)--;
    return item;
}



int priority(char op)
{
    switch(op)
    {
        case '^': return 3;
        case '/': 
        case '*': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}


int isoperator(char x)
{
    switch(x)
    {
        case '^':
        case '/':
        case '*':
        case '-':
        case '+': return 1;
        default: return 0;
    }
}