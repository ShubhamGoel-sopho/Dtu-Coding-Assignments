#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
  short N;
  cin>>N;
  int x;
  vector<int> real,ideal;
  
  for(int t=0;t<N;t++)
  {
  	cin>>x;
  	real.push_back(x);
  }
  
   for(int t=0;t<N;t++)
  {
  	cin>>x;
  	ideal.push_back(x);
  }
  int p = 0;
  int count=0;
  int i;
   while(!real.empty())
   {
   		
   		 
   		 for(i=0;i<real.size();i++)
   		 {
   		 	if(real.at(i) == ideal.at(p))
   		 	break;
   		 	
   		 }
   		 if(i == p || p>i)
   		 {
   		 	real.erase(real.begin());
   		 	count++;
   		 	p++;
   		 }
   		 else
   		 {
	   		 swap(real.at(i-1),real.at(i));
	   		 count++;
	      }	 
   		 
   		 
   		 
   }
   ideal.clear();
   real.clear();
   cout<<count<<endl;
  
  
  
  
  
  
  
  
    
    return 0;
}

