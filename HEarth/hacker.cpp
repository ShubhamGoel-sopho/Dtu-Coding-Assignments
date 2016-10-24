<<<<<<< HEAD
#include<iostream>
using namespace std;

int main()
{
   
   unsigned int M,N;
   
   cin>>M;
   cout<<endl;
   cin>>N;
   unsigned int L[N],H[N];
   cout<<endl;
   for(int i=0;i<N;i++)
   {
	   
	   cin>>H[i]>>L[i];
	   
   }
   for(int k=0;k<N;k++)
   {
	   
	   if(H[k] < M || L[k] < M)
	   {
	   		cout<<"UPLOAD ANOTHER"<<endl;
	   }
	   else if(H[k] > M && L[k] > M)
	   {
	   		if(H[k] == L[k])
	   		{
	   			cout<<"ACCEPTED"<<endl;
	   		}
	   		else
	   		{
	   			cout<<"CROP IT"<<endl;
	   		}
	   }
   }   
    return 0;
}


=======
#include<iostream>
using namespace std;

int main()
{
   
   unsigned int M,N;
   
   cin>>M;
   cout<<endl;
   cin>>N;
   unsigned int L[N],H[N];
   cout<<endl;
   for(int i=0;i<N;i++)
   {
	   
	   cin>>H[i]>>L[i];
	   
   }
   for(int k=0;k<N;k++)
   {
	   
	   if(H[k] < M || L[k] < M)
	   {
	   		cout<<"UPLOAD ANOTHER"<<endl;
	   }
	   else if(H[k] > M && L[k] > M)
	   {
	   		if(H[k] == L[k])
	   		{
	   			cout<<"ACCEPTED"<<endl;
	   		}
	   		else
	   		{
	   			cout<<"CROP IT"<<endl;
	   		}
	   }
   }   
    return 0;
}


>>>>>>> a3a9cc0590ad200d8e072f7eff31541cbda2e3a6
