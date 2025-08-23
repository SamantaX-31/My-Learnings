#include<stdio.h>
#define SIZE 20
void Selection_sort(int[],int);
void input_array(int[],int);
void swap(int[],int,int);
void display(int[],int);
int main()
{
    int arr[SIZE], n;

    printf("Enter the number of elements:");
    scanf("%d",&n);

    input_array(arr,n);
    Selection_sort(arr,n);
    printf("The sorted array is......");
    display(arr,n);

    return 0;
}
void input_array(int arr[],int n)
{
    int i;

    for(i=0 ; i<n ; i++)
    {
        printf("Enter data arr[%d]:",i);
        scanf("%d",&arr[i]);
    }
}
void Selection_sort(int arr[],int n)
{
    int i,j,min;
    for(i=0;i<=n-2;i++)
    {
        min = i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min = j;
            }
        }
        if(min!=i)
        {
            swap(arr,min,i);
        }
    }
}
void swap(int arr[], int min, int i)
{
    int temp;
        temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
}
void display(int arr[],int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}