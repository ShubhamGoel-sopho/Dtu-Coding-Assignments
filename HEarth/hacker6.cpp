#include <iostream>
#include<math.h>
using namespace std;
 
int main()
{
    int N;
    cin>>N;
    int array[N];
    for(int i=0;i<N;i++)
    {
    	cin>>array[i];
    }
    
   unsigned long long int X = pow(10,9)+7;
   unsigned long long int Y = 1;
    for(int i=0;i<N;i++)
    {
    	Y = (Y%X * array[i]%X)%X;
    	
    }
    cout<<Y<<endl;
    return 0;
}

