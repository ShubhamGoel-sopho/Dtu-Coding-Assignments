#include <iostream>
#include <stack>
using namespace std;

int main()
{
	short T;
	cin>>T;
	unsigned long int test;
	int cars[T];
   stack<unsigned long int> foo[T];
	for(int i=0;i<T;i++)
	{
		cin>>cars[i];
		for(int j=0;j<cars[i];j++)
		{
			cin>>test;
			foo[i].push(test);
		}
	}
	
    int output;
    bool flag ;
   for(int i=0;i<T;i++)
   {	flag = true;
        output = 1;
	   	while(flag)
	   	  {
		   	  	test = foo[i].top();
		   	  	foo[i].pop();
		   	  	if( !foo[i].empty() && foo[i].top() > test)
		   	  	{
		   	  		flag = false;
		   	  	}
		   	  	else if(!foo[i].empty())
		   	  	{
		   	  	
				        output++;
		   	  	}
		   	  	else
		   	  	{
		   	  		flag = false;
		        }
	   	  	
   	  		
	   	  
	   	  }
	   	  cout<<output<<endl;
   }
   
    return 0;
}

