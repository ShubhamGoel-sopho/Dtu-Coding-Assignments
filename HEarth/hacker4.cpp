<<<<<<< HEAD
#include <iostream>
#include<list>
using namespace std;

int main()
{
    unsigned short int M,N; //m is no of prime and n is no of queries
    cin>>M>>N;
    
    long long int PrimeArray[M];
    for(int i=0;i<M;i++)
    {
    	cin>>PrimeArray[i];
    }
    
    unsigned long long int X[N],Y[N]; //array for the given no of ranges
    for(int j=0;j<N;j++)
    {
    	cin>>X[j]>>Y[j];
    }
    
    for(int k=0;k<N;k++)
    {
    	
        list<int> factor;
    		for(int m=0;m<M;m++)
    		{
    			long long int primeno = PrimeArray[m];
    			
    				for(unsigned long long int l=X[k];l<=Y[k];)
    				{
    					if(l % primeno == 0)
    					{
    						
    						factor.push_back(l);
    						l = l+primeno;
    					}
    					else
    					{
    						l++;
    					}
    				}
    		   
    			
    		}
   
		    factor.sort();
		    factor.unique();
		    std::cout << factor.size() << std::endl;
		    factor.clear();
	        
	}
		    
    return 0;
}

=======
#include <iostream>
#include<list>
using namespace std;

int main()
{
    unsigned short int M,N; //m is no of prime and n is no of queries
    cin>>M>>N;
    
    long long int PrimeArray[M];
    for(int i=0;i<M;i++)
    {
    	cin>>PrimeArray[i];
    }
    
    unsigned long long int X[N],Y[N]; //array for the given no of ranges
    for(int j=0;j<N;j++)
    {
    	cin>>X[j]>>Y[j];
    }
    
    for(int k=0;k<N;k++)
    {
    	
        list<int> factor;
    		for(int m=0;m<M;m++)
    		{
    			long long int primeno = PrimeArray[m];
    			
    				for(unsigned long long int l=X[k];l<=Y[k];)
    				{
    					if(l % primeno == 0)
    					{
    						
    						factor.push_back(l);
    						l = l+primeno;
    					}
    					else
    					{
    						l++;
    					}
    				}
    		   
    			
    		}
   
		    factor.sort();
		    factor.unique();
		    std::cout << factor.size() << std::endl;
		    factor.clear();
	        
	}
		    
    return 0;
}

>>>>>>> a3a9cc0590ad200d8e072f7eff31541cbda2e3a6
