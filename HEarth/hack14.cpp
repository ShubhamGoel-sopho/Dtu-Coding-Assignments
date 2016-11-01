#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int N;
    cin>>N;
    
    string main_array[N];
    vector<string> foo;
    for(int i=0;i<N;i++)
    {
    	cin>>main_array[i];
    	foo.push_back(main_array[i]);
    }
    
    stable_sort(foo.begin(),foo.end());
    string temp;
    int location;
    int count_copy;
    int temp_location;
    int count;
    for(int i=0;i<N;i++){
    	temp = main_array[i];
    	
    	std::vector<string>::iterator it;

		  it = find (foo.begin(), foo.end(), temp);
		  if (it != foo.end()){
		      location = it-foo.begin() ;
		   }
        count = i;
       count_copy = i-1;
        if(count == 0)
        {
        	cout<<count<<endl;
        }
        else
        {
        	while(count_copy >=0)
        	{
        		it = find (foo.begin(), foo.end(), main_array[count_copy]);
        		temp_location = it-foo.begin();
        		if(temp_location < location)
        		{
        			count_copy--;
        		}
        		else
        		{
        			count--;
        			count_copy--;
        		}
        	}
        	cout<<count<<endl;
        }
		  
    	
    
    }
    
    return 0;
}
