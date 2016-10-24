#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<char, int> firstmap ;
    cout<<"enter the value corresponding to map the 26 characters :"<<endl;
    char choice;
    int count=0;
    int value;
    char m = 'a';
    do{
        
        cout<<"enter the value to map to "<<m<<endl;
        cin>>value;
        firstmap[m] = value;
        count++;
        m++;
        
        
        
        
        
        
        
        cout<<"want to map more:"<<endl;
        cin>>choice;
      
      
    }while(choice == 'y'&& count<27);
    cout<<"you mapped :"<<endl;  
    
   // ;
 /*  for (auto& x: firstmap)
    std::cout << " [" << x.first << ':' << x.second << ']';
  std::cout << '\n';*/
  
  for(map<char,int>::iterator it=firstmap.begin();it != firstmap.end();it++)
  {
      cout<<it->first<<" => "<<it->second<<endl;
  }
    
    
    
    
    
    
    return 0;
}