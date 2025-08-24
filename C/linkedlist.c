#include<stdio.h>
#include<stdlib.h>
typedef struct n
{
    int info;
    struct n *next;
}node;
void insertend(node **,int);
void display(node *);
void insertbegin(node **,int);
int deletebegin(node **);
int menu();
int main()
{
    int ch,data;
    node *start = NULL;
    while(1)
    {
        ch = menu();
        switch(ch)
        {
            case 1:printf("Enter data:");
            scanf("%d",&data);
            insertend(&start, data);
            break;
            case 2:display(start);
            break;
            case 3:printf("Enter data:");
            scanf("%d",&data);
            insertbegin(&start, data);
            break;
            case 4: printf("%d deleted from the linkedlist..\n",deletebegin(&start));
            break;
            case 5:exit(0);
            break;
        }
    }
    return 0;
}
void insertend(node **start, int item)
{
    node *newnode,*temp;
    newnode = (node *)malloc(sizeof(node));
    newnode -> info = item;
    newnode -> next = NULL;
    if(*start == NULL)
    {
        *start = newnode;
        return;
    }
    temp = *start;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = newnode;
}
void display(node *start)
{
    node *temp;
    temp = start;
    while(temp != NULL)
    {
        printf("%d -->",temp->info);
        temp = temp -> next;
    }
    printf("\n\n");
}
void insertbegin(node **start,int item)
{
    node *newnode,*temp;
    newnode = (node *)malloc(sizeof(node));
    newnode -> info = item;
    newnode -> next = NULL;
    if(*start == NULL)
    {
        *start = newnode;
        return;
    }
    newnode -> next = *start;
    *start = newnode;
}
int deletebegin(node **start)
{
    node *temp;
    int data;
    if(*start == NULL)
    {
        printf("Linkedlist is Empty");
        return -1;
    }
    temp = *start;
    data = temp -> info;
    *start = temp ->next;
    free(temp);
    return data;
}
int menu()
{
    int a;
    printf("1. Insert End\n");
    printf("2. Traverse\n");
    printf("3. Insert Begin\n");
    printf("4. Delete Begin\n");
    printf("5. Exit\n");
    printf("Enter your choice(1-4):");
    scanf("%d",&a);
    return a;
}