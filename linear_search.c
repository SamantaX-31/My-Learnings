/*Linear Search Revise 20.07.2025*/
#include<stdio.h>
int linear_search(int[],int,int);
void input_data(int[],int);
int main()
{
	int arr[50], n,Search,data;
	printf("Enter the number of elements:");
	scanf("%d",&n);

	input_data(arr,n);
	printf("Enter the number to search:");
	scanf("%d",&data);
	Search = linear_search(arr,n,data);
	
	if(Search == -1)
	{
		printf("The number you entered is not found\n");
	}
	else
	{
		printf("The number found on %d position\n",Search);
	}
	return 0; 
}

void input_data(int arr[],int n)
{
	int i;

	for(i=0;i<=n;i++)
	{
		printf("Enter data a[%d]:",i);
		scanf("%d",&arr[i]);
	}
}

int linear_search(int arr[],int n , int data)
{
	int i;
	for(i=0;i<=n;i++)
	{
		if(arr[i]==data)
		return i;
	}
	return -1;
}
