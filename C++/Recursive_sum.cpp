#include<iostream>
#include<cmath>
using namespace std;
int recursive_sum(int);
int main()
{
	int n;
	cout<<"n:";
	cin>>n;
	int sum= recursive_sum(n);
	cout<<"sum="<<sum;
	return 0;
}
int recursive_sum(int n)
{
	if(n==0)
	return 0;
	else
	return n+ recursive_sum(n-1);
	
}