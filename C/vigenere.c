#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc , string argv[])
{    
    int index;
    if(argc !=2)
    {
        printf("you have wrong number of arguments");
        return 1;
        
    }
    else
    {    bool flag = true;
         for(index=0;index<strlen(argv[1]);index++)
         {
             if(isalpha(argv[1][index]))
            { 
             flag=true;
            }
             else
             {
             flag = false;
             printf("you have wrong arguments");
             return 1;
             }
         }
        
        
        string s;
    
        s = GetString();
        int k = strlen(s);
        if(s != NULL)
        {
            int i ;
            int ascii_upper = 'A';
            int ascii_lower = 'a';
            
            
            int test_length = strlen(argv[1]);
            int key;
            int index_key = 0;
          for(i=0;i<k;i++)
          {
              if(isalpha(s[i]))
            {
                if(((int)argv[1][index_key] >= 65) && ((int)argv[1][index_key]<=90))
               key = ((int)argv[1][index_key]-65)   ;
              
               if(((int)argv[1][index_key] >= 97) && ((int)argv[1][index_key]<=122))
              key = ((int)argv[1][index_key]-97)   ;
              
              index_key = (index_key + 1) %  test_length ; 
                
              if(isupper(s[i]))
               {
                 s[i] = (char)((((int)s[i]-ascii_upper + key) % 26)+ascii_upper) ;
                  
               }
              if(islower(s[i]))
               {
                 s[i] = (char)((((int)s[i]-ascii_lower + key) % 26)+ascii_lower) ;
                  
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
    
    