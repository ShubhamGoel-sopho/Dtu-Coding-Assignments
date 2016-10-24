#include<stdio.h>
#include<cs50.h>
int main(void)
{   int x;
    printf("Enter your length of shower in minutes:");
    x=GetInt();
    printf("\n");
    printf("Bottles: %i\n",12*x);
    
    
    
    return 0;
    
    
}