#include<stdio.h>
int binary_search(int[],int,int);
void input_array(int[],int);
int main()
{
    int arr[50],n,data,Pos;

    printf("Enter the number of elements:");
    scanf("%d",&n);

    input_array(arr,n);
    printf("Enter the number to search:");
    scanf("%d",&data);
    Pos = binary_search(arr,n,data);
    
    if(Pos==-1)
    {
        printf("Your enter number not found...\n");
    }
    else
    {
        printf("Your entered number found on %d position..\n",Pos);
    }
    return 0;
}

void input_array(int arr[], int n)
{
     int i;
     for(i=0;i<n;i++)
     {
        printf("Enter data arr[%d]",i);
        scanf("%d",&arr[i]);
     }
}

int binary_search(int arr[],int n, int data)
{
    int i,lb = 0, ub = n-1,mid;

    mid = (lb+ub+1)/2;
    while(lb<ub)
    {
        if(arr[mid]== data)
        return mid;
        else if(arr[mid]<data)
        ub = mid-1;
        else if(arr[mid]>data)
        lb = mid+1;
    }
    return -1;
}