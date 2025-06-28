#include<stdio.h>
#include<math.h>
int main()
{
    int d1,m1,y1;
    int d2,m2,y2;
    int D,M,Y;


    printf("Enter Your Date of Birth(DD/MM/YYYY)\n");
    scanf("%d/%d/%d", &d2,&m2,&y2);
    
    printf("Enter Current Date(DD/MM/YYYY)\n");
    scanf("%d/%d/%d", &d1,&m1,&y1);

    
    //age calculate in years
    
        Y=y1-y2;
    
    
    //age calculate in months
    
    if(m1<=m2)
    {
        Y--;
        M=(12+m1)-m2;
    }
    else
    {
        M=m1-m2;
    }
    //age calculate in days
    if(d1<=d2)
    {
        M--;
        if(m1==1 || m1==3 || m1==5 || m1==7 
        || m1==8 || m1==10 || m1==12)
        {
            D=(31+d1)-d2;
        } 
        
        else if(m1==4 || m1==6 || m1==9 || m1==11)
        {
            D=(30+d1)-d2;
        }
        else
        {
            if((y1%4==0 && y1%100!=0)|| y1%400==0)
            {
                D=(29+d1)-d2;
            }
            else
            {
                D=(28+d1)-d2;
            }
        }
    }
    
    else
    {
        D=d1-d2;
    }
    printf("Your Age is %d years %d months %d days",Y,M,D);
    //done
    return 0;  
}