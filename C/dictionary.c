/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"


//size of hash table
#define HASH_MAX 5153
#define LENGTH 45

//count keeps no of words in the dictionary
unsigned int count = 0;

typedef struct node
{
    char word[LENGTH+1];
    struct node *next;
}
node;

node *Hasharray[HASH_MAX] = {NULL};



/**
  * Computes the hash key value.
  */
/*
int stringhash(const char *somevalue)
{
	int length = strlen(somevalue);
	//using horner rule for creating hash ///
	///here i choose y = 33 as suggested////
	int y =33;
	int z=0;
	int long long sum = 0;
	for(int i=0;i<length;i++)
	{
	     
		if(i == 0 || z>10)
		{
			sum +=(int)somevalue[i];
		}
		else
		{
		    sum +=(pow(y,z) * (int)somevalue[i]);
		    
		}
		
		z++;
	} 
	
	return (sum % HASH_MAX);
	
	
}*/

int stringhash (const char* word) 
 { 
     int hash = 0; 
     int n; 
     for (int i = 0; word[i] != '\0'; i++) 
     { 
         // alphabet case 
         if(isalpha(word[i])) 
             n = word [i] - 'a' + 1; 
          
         // comma case 
         else 
             n = 27; 
              
         hash = ((hash << 3) + n) % HASH_MAX; 
     } 
     return hash;     
 }





/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
        
     // creates a temp variable that stores a lower-cased version of the word 
     char temp[LENGTH+1]; 
     int len = strlen(word); 
     for(int i = 0; i < len; i++) 
         temp[i] = tolower(word[i]); 
     temp[len] = '\0'; 
      
     // find what index of the array the word should be in 
     int index = stringhash(temp); 
      
     // if hashtable is empty at index, return false 
     if (Hasharray[index] == NULL) 
     { 
         return false; 
     } 
      
     // create cursor to compare to word 
     node* cursor = Hasharray[index]; 
      
     // if hashtable is not empty at index, iterate through words and compare 
     while (cursor != NULL) 
     { 
         if (strcmp(temp, cursor->word) == 0) 
         { 
             return true; 
         } 
         cursor = cursor->next; 
     } 
      
     // if you don't find the word, return false 
     return false; 
} 
    
    
/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    //load the dictionary
    FILE *fp ;
    fp = fopen(dictionary,"r");
    if(fp == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }
    else
    {
            //create a buffer for storingthe word 
            char str[LENGTH+1];
        	int key;
	        count = 0;
	       // scan through the file, loading each word into the hash table
	        while(fscanf(fp,"%s\n",str) != EOF)
	        {
	            ///////increment dictionary size///
	            count++;
	            /////////get the key value/////////
	            key = stringhash(str);
	            ///////////malloc new node/////////
	            node *createword = malloc(sizeof(node));
	            //copy in the word part 
	            strcpy(createword->word,str);
	           
                
                if(Hasharray[key] == NULL)
                {
                    Hasharray[key] = createword;
                    createword->next = NULL;
                }
                else
                {
                    //append the node
                    createword->next = Hasharray[key];
                    Hasharray[key] = createword;
                }

	       }
        //close the file 
           fclose(fp);
        
        //return true on successful      
           return true;    
    }
}	        
    

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    if(count>0)
    {
        //if dictionary has loaded then return count
        return count;

    }
    else
    {
        //if dictionary hasn't been loaded then return 0
        return 0;
    }
}


/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
  
         
    // create a variable to go through index 
    int index = 0; 
      
      // iterate through entire hashtable array 
     while (index < HASH_MAX) 
    { 
        // if hashtable is empty at index, go to next index 
        if (Hasharray[index] == NULL) 
        { 
            index++; 
        } 
          
        // if Hasharray is not empty, iterate through nodes and start freeing 
        else 
        { 
            while(Hasharray[index] != NULL) 
            { 
                node* cursor = Hasharray[index]; 
                Hasharray[index] = cursor->next; 
                free(cursor); 
            } 
              
             // once Hasharray is empty at index, go to next index 
            index++; 
        } 
    }  
      
     // return true if successful 
     return true; 
} 

       
   
/*--------------------------------------------------------------------------------------------*/



       
