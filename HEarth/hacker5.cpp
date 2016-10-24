<<<<<<< HEAD
#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<stdio.h>
#include<list>
using namespace std;

list<string> perm;
bool ispalindrome(string str,int start,int end)
{
	int length = end-start;
	bool flag = false;
	 for(int i=start;i <=length;i++){
        if(str[i] != str[length-i]){
            flag = true;
            break;
	   }
	}
    
    if (flag) {
        return false; 
    }    
    else {
       return true;
 		}
}

/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the
   string. */
   
void permute(char *a, int l, int r)
{
   int i;
   if (l == r)
   {
   	perm.push_back(a);
   }
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
       }
   }
}
bool check_palindromicity(int start,int end)
{
	bool y = false;
	for(int i = 0;i<perm.size();i++)
	{
		string x = perm.front();
		 perm.pop_front();
		 y=ispalindrome(x,start,end);
		if(y == true)
		{
			return true;
		}
	}
	return false;
}
   

int main()
{
	//length of string N declared wih the constraint
	unsigned int N,Q;
	cin>>N>>Q;
	if(N >= 1 && N <= 100000)
	{
		
		if(Q >= 1 && Q <= 100000)
		{
			char G[N];
			gets(G);
			unsigned int H[Q],L[Q],M[Q];
			
			for(int i=0;i<Q;i++)
			{
				cin>>H[i]>>L[i]>>M[i];
				
			}
			
			for(int k=0;k<Q;k++)
			{
				if(H[k] == 1)
				{
					char x = M[k];
					G[L[k]] = x;
					
				}
				else if(H[k] == 2)
				{
					permute(G,L[k],M[k]);	
					bool z = check_palindromicity(0,N-1);
					if(z == true)
					cout<<"yes"<<endl;
					else
					cout<<"no"<<endl;
				}
			}
			
			
			
		}
		
	}
	
    
    return 0;
}

=======
#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<stdio.h>
#include<list>
using namespace std;

list<string> perm;
bool ispalindrome(string str,int start,int end)
{
	int length = end-start;
	bool flag = false;
	 for(int i=start;i <=length;i++){
        if(str[i] != str[length-i]){
            flag = true;
            break;
	   }
	}
    
    if (flag) {
        return false; 
    }    
    else {
       return true;
 		}
}

/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the
   string. */
   
void permute(char *a, int l, int r)
{
   int i;
   if (l == r)
   {
   	perm.push_back(a);
   }
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
       }
   }
}
bool check_palindromicity(int start,int end)
{
	bool y = false;
	for(int i = 0;i<perm.size();i++)
	{
		string x = perm.front();
		 perm.pop_front();
		 y=ispalindrome(x,start,end);
		if(y == true)
		{
			return true;
		}
	}
	return false;
}
   

int main()
{
	//length of string N declared wih the constraint
	unsigned int N,Q;
	cin>>N>>Q;
	if(N >= 1 && N <= 100000)
	{
		
		if(Q >= 1 && Q <= 100000)
		{
			char G[N];
			gets(G);
			unsigned int H[Q],L[Q],M[Q];
			
			for(int i=0;i<Q;i++)
			{
				cin>>H[i]>>L[i]>>M[i];
				
			}
			
			for(int k=0;k<Q;k++)
			{
				if(H[k] == 1)
				{
					char x = M[k];
					G[L[k]] = x;
					
				}
				else if(H[k] == 2)
				{
					permute(G,L[k],M[k]);	
					bool z = check_palindromicity(0,N-1);
					if(z == true)
					cout<<"yes"<<endl;
					else
					cout<<"no"<<endl;
				}
			}
			
			
			
		}
		
	}
	
    
    return 0;
}

>>>>>>> a3a9cc0590ad200d8e072f7eff31541cbda2e3a6
