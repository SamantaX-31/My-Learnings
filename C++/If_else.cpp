#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int num;
    cout<<"Enter Your Number"<<endl;
    cin>>num;

    if(num % 2 == 0)
    {
        cout<<"Your entered number is even\n"<<num;
    }
    else
    {
        cout<<"Your entered number is odd\n"<<num;
    }
}
