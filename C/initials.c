#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    
    string s;
    s = GetString();
   // printf("you entered : %s\n",s);
   int i;
   
   if(s !=NULL)
   {
       for(i=0;i<strlen(s);i++)
        {
            s[i] = toupper(s[i]);
            
        }
        printf("%c",s[0]);
       for(i=1;i<strlen(s);i++)
       {
           if(s[i]==' ')
           {
              printf("%c",s[i+1]);
           }
       }
       printf("\n"); 
   }
    
    
    
    
}