#include <iostream>
#include<string.h>
using namespace std;

struct use
{
	int N;
	int *p;
	unsigned long long T,A,B;
	int x1;
};
int main()
{
	//xi = (a*x(i-1)+b)%N ==== (a*x(i-1)%N+b%N)%N === ( ((a%N)*(x(i-1)%N))%N + b%N)%N 
  	short Q;
  	cin>>Q;
  	use use_me[Q];
  //input to be taken for each case
  	for(int i=0;i<Q;i++)
  	{
  		cin>>use_me[i].N;
  		use_me[i].p = new int[use_me[i].N];
  		for(int j=0;j<use_me[i].N;j++)
  		{
  			cin>>use_me[i].p[i];
  		}
  		cin>>use_me[i].x1>>use_me[i].A>>use_me[i].B>>use_me[i].T;
  	}
  	for(int i=0;i<Q;i++)
  	{
  		unsigned int count = 0;
  		int ARRAY[use_me[i].T];
  		ARRAY[0] = use_me[i].x1;
  		for(int j=1;j<use_me[i].T;j++)
  		{
  			ARRAY[j] = ( ((use_me[i].A%use_me[i].N)*(ARRAY[j-1]%use_me[i].N))%use_me[i].N + use_me[i].B%use_me[i].N)%use_me[i].N;
  		}
  		int ARRAY1[use_me[i].N] ;
  		memset(ARRAY1,0,sizeof(ARRAY1));
  
  		for(int j=0;j<use_me[i].T;j++)
  		{
  			ARRAY1[ARRAY[j]]++;
  			
  		}
  		for(int k=0;k<use_me[i].N;k++)
  		{
  			ARRAY1[k] /= use_me[i].p[k];
  			count +=ARRAY1[k];
  		}
  		cout<<count<<endl;
  		
  	}
  	
  
    return 0;
}

