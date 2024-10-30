#include<iostream>
#include<cmath>
#define pi 3.14159 
#define a 1.3333

using namespace std;
 
 int main()
 {
   double radius,volume,surface_area,Circumference;
    
   cout<<"Enter the radius of your Sphere"<<endl;
   cin>>radius;
    
   surface_area= 4 * pi * radius *radius;
   volume = a * pi * radius * radius *radius;
   Circumference = 4 * pi;

   cout<<"The Surface Area of your Sphere is:"<<surface_area<<endl;
   cout<<"The Volume of your Sphere is:"<<volume<<endl;
   cout<<"The Circumference of your Sphere is:"<<Circumference<<endl;

   return 0;
 }