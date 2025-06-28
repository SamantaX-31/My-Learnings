#include <stdio.h>

int main() {
    float eng, ben, chem, math, comp;
    float total, percentage;

    printf("Enter your English Marks:\n");
    scanf("%f", &eng);
    
    printf("Enter your Bengali Marks:\n");
    scanf("%f", &ben);
    
    printf("Enter your Chemistry Marks:\n");
    scanf("%f", &chem);
    
    printf("Enter your Mathematics Marks:\n");
    scanf("%f", &math);
    
    printf("Enter your Computer Marks:\n");
    scanf("%f", &comp);

    total = eng + ben + chem + math + comp;
    percentage = (total / 500.0) * 100;

    printf("Total marks = %f\n", total);
    printf("Percentage = %f\n", percentage);
    
    if(percentage>=90)
    {
        printf("Your Grade is A\n");
    }
    
    else if(percentage>=80)
    {
        printf("Your Grade is B\n");
    }
    
    else if(percentage>=70)
    {
        printf("Your Grade is C\n");
    }
    
    else if(percentage>=60)
    {
        printf("Your Grade is D\n");
    }
    
    else
    {
        printf("Your Grade is Fail\n");
    }

    return 0;
}