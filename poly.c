/*Polynomial Addition*/
#include<stdio.h>
#include<stdlib.h>
typedef struct s
{
int coef;
int expo;
struct s *next;
}node;
void insertend(node **, int, int);
node *polyadd(node *, node *);
void display(node *);
int menu();


void insertend(node **ptr, int coef, int expo)
{

node *temp, *newnode;
newnode= (node *)malloc(sizeof(node));
newnode->coef=coef;
    newnode->expo=expo;
    newnode->next=NULL;
    if(*ptr==NULL)
    {
        *ptr=newnode;
        return;
    }
   
    temp=*ptr;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newnode;
}

node *polyadd(node *p1, node *p2)
{
  node *p3=NULL; // head pointer of third polynomia
  int r;
  while(p1!=NULL && p2!=NULL)
  {
  if(p1->expo > p2->expo)
  {
  insertend(&p3, p1->coef, p1->expo);
  p1= p1->next;
  }
  else if(p2->expo>p1->expo)
  {
  insertend(&p3, p2->coef, p2->expo);
  p2= p2->next;
  }
  else
  {
  r=p1->coef+p2->coef;
  if(r!=0)
     insertend(&p3, r, p1->expo);
  p1=p1->next;
  p2=p2->next;
  }

  }
 
 
  while(p1!=NULL)
  {
  insertend(&p3, p1->coef, p1->expo);
  p1=p1->next;
  }
 
  while(p2!=NULL)
  {
  insertend(&p3, p2->coef, p2->expo);
  p2=p2->next;
  }
  return p3;
}
 
 
int main()
{

    node *head1=NULL, *head2=NULL, *head3=NULL;

    int choice,co,ex;
    while(1)
    {
        choice=menu();
        switch(choice)
        {
            case 1: printf("Enter the terms of 1st polynomial\n");
                    while(1)
                    {
                        printf("Enter coefficient at end");
                        scanf("%d", &co);
                        if(co==0)
                            break;
                        printf("Enter exponent at end");
                        scanf("%d", &ex);
                        insertend(&head1, co, ex);
                    }
                    break;
                   
                   
             case 2:printf("Enter the terms of 2nd polynomial\n");
                    while(1)
                    {
                        printf("Enter coefficient at end");
                        scanf("%d", &co);
                        if(co==0)
                            break;
                        printf("Enter exponent at end");
                        scanf("%d", &ex);
                        insertend(&head2, co, ex);
                    }
                    break;
                   
              case 3:head3 = polyadd(head1, head2);
                     break;
               case 4: display(head3);
                        break;
                       
                case 5:exit(0);
        }
    }
    return 0;
}
int menu()
{
int a;
printf("1.To Enter 1st Polynomial\n");
printf("2.To Enter 2nd Polynomial\n");
printf("3.To Add Two Polynomial\n");
printf("4.To Display the result Polynomial\n");
printf("5. Exit\n");
printf("Enter your choice(1-5):");
scanf("%d",&a);
return a;
}

void display(node *p)
{
    while(p!=NULL)
    {
       
        printf("%dx^%d+", p->coef,p->expo);
        p=p->next;
       
    }
    printf("\n");
 }