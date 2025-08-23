#include<stdio.h>
#include<stdlib.h>
#define max 5
void insert(int [], int *, int *, int *, int);
int delete(int [], int *, int *, int *);
int menu()
{
    int a;
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Exit\n");
    printf("Enter your Choice(1-3):");
    scanf("%d",&a);
    return a;
}
int main()
{
    int Q[max], front, rear, count, item, choice;
    
    front=rear=count=0;
    while(1)
    {
        choice=menu();
        switch(choice)
        {
            case 1:printf("Enetr data ");
                   scanf("%d", &item);
                   insert(Q, &rear,&front, &count, item);
                   break;
            case 2:item=delete(Q, &rear, &front, &count);
                   printf("Deleted item=%d\n", item);
                   break;                
            case 3:exit(0);
             
        }
    }

    
    return 0;
}


void insert(int Q[], int *r, int *f, int *c, int item)
{
    if(*c == max)
    {
        printf("Queue is full");
        return;
    }
    *r = (*r + 1)% max;
    Q[*r]=item;
    (*c)++;
    }
    
    
int delete(int Q[], int *r, int *f, int *c)
{
    if(*c == 0)
    {
        printf("Queue is empty");
        return -999;
    
    }
    *f = (*f + 1)% max;
    *c = *c - 1;
    return Q[*f];
} 