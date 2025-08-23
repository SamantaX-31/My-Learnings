#include<stdio.h>
#include<stdlib.h>
#define MAX 5
void push(int[],int *,int);
int pop(int[],int *);
int menu()
{
    int a;
    printf("1. push\n");
    printf("2. pop\n");
    printf("3.exit\n");

    printf("Enter your choice(1-3):");
    scanf("%d",&a);
    return a;
}
int main()
{
    int a[MAX], top = -1, item;
    int ch,popv;

    while(1)
    {
        ch = menu();
        switch(ch)
        {
            case 1:
            printf("Enter data:");
            scanf("%d",&item);
            push(a,&top,item);
            break;
            case 2:
            popv = pop(a,&top);
            printf("%d is poped out\n",popv);
            break;
            case 3:
            exit(0);
        }
    }
    return 0;
}

void push(int a[],int *top,int item)
{
    if(*top == MAX -1)
    {
        printf("Your stack is full");
        return;
    }
    (*top)++;
    a[*top]=item;
}
int pop(int a[], int *top)
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
