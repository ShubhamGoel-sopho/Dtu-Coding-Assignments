#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc , string argv[])
{
    if(argc != 2)
    {
        printf("you have wrong number of arguments");
        return 1;
        
    }
    else
    {
        string s;
        s = GetString();
        int k = atoi(argv[1]);
        if(s != NULL && k != 0)
        {
            int i ;
            int ascii_upper = 'A';
            int ascii_lower = 'a';
          for(i=0;i<strlen(s);i++)
          {
              if(isalpha(s[i]))
            {
              if(isupper(s[i]))
               {
                 s[i] = (char)((((int)s[i]-ascii_upper + k) % 26)+ascii_upper) ;
                  
               }
              if(islower(s[i]))
               {
                 s[i] = (char)((((int)s[i]-ascii_lower + k) % 26)+ascii_lower) ;
                  
               }  
              
            }
              
          }
        
        }
         int i;
         for(i=0;i<strlen(s);i++)
          {
              printf("%c",s[i]);
              
          }
          printf("\n");
              
              
    
        } 
        return 0;
    }
    
    