#include<stdio.h>
#include<cs50.h>
#include<math.h>
int main(void)
{ 
    float x;
do
{
    printf("Enter the amount to owe the change :");
    x=GetFloat();
}while(x<=0);
x=x*100;
x = roundf(x);
printf("\n");
int coins;
coins=0;
bool flag=true;

while(flag)
{ if(x<25.00)
    {
        flag=false;
    }
    else{
    x=x/(25.00);
    ++coins;
    }
    
    
}
   
    flag=true;
    while(flag)
{ if(x<10.00)
    {
        flag=false;
    }
    else{
    x=x/(10.00);
    ++coins;
    }
    
    
}

flag=true;
while(flag)
{ if(x<5.00)
    {
        flag=false;
    }
    else{
    x=x/(5.00);
    ++coins;
    }
    
    
}

flag=true;
while(flag)
{ if(x<1.00)
    {
        flag=false;
    }
    else{
    
    coins +=(int)x;
    flag=false;
    }
    
    
}
printf("%d/n",coins);
    return 0 ; 
}