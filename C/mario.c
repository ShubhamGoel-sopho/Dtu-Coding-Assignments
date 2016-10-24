#include<stdio.h>
#include<cs50.h>
void printspacehashes(int l,int n)
{ int y;
    for(y=l;y<=(n-1);y++)
    {
        printf(" ");
        
    }
    y=l;
    static int i=0;
    for(y=l;y<=(l+1+i);y++)
    {
        printf("#");
    }
    ++i;
    
    
}
int main(void)
{
    int x;
    do{
   printf("Enter the height :");
   
   x=GetInt();
   if(x==0)
   {
       return 0;
   }
    
    } while(x>23 || x<=0);
    int i;
    for(i=1;i<=x;i++)
    {
        printspacehashes(i,x);
        printf("\n");
        
    }
    
    
    
    
return 0 ;
}