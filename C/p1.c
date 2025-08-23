#include<stdio.h>
int main()
{
	int i,j,height;
	printf("Enter the height:\n");
	scanf("%d", &height);
	
	for(i=1; i<=height ; i++)
	{
		for(j=i; j>=1 ; j--)
		{
			printf("%d",j);
		}
		printf("\n");
	}
	return 0;
}
