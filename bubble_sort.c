#include<stdio.h>
void input_array(int[],int);
void bubble_sort(int[],int);
void display(int[],int);
int main()
{
    int n, arr[50];
    printf("Enter the number of elements:");
    scanf("%d",&n);
    
    input_array(arr,n);
    bubble_sort(arr,n);
    display(arr,n);

    return 0;
}

void input_array(int arr[], int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        printf("Enter data a[%d]",i);
        scanf("%d",&arr[i]);
    }
}

void bubble_sort(int arr[], int n)
{
    int i,j,temp,swap;

    for(i=0;i<n;i++)
    {
        swap = 0;
        for(j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swap = 1;
            }
        }
        if(swap == 0)
        break;
    }
}

void display(int arr[],int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
}