#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<char, int> firstmap ;
 /*   cout<<"enter the value corresponding to map the 26 characters :"<<endl;
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
   for (auto& x: firstmap)
    std::cout << " [" << x.first << ':' << x.second << ']';
  std::cout << '\n';*/
 
 
   firstmap['A'] = 100;
   firstmap['a'] = 200;
   firstmap['b'] = 300;
   firstmap['B'] = 400;
   firstmap['x'] = 3050 ;
      firstmap['y'] = 3005;
         firstmap['z'] = 340;
    firstmap['m'] = 30470;
     firstmap['g'] = 700;
     
     //map<char, int> secondmap(firstmap.begin(),firstmap.end()) ;
  for(map<char,int>::iterator it=firstmap.begin();it != firstmap.end();it++)
  {
      cout<<it->first<<" => "<<it->second<<endl;
  }
    cout<<firstmap.size();
    cout<<endl;
    
  //  firstmap.clear();
    /*firstmap['y'] = 3005;
    firstmap['z'] = 340;
    firstmap['m'] = 30470;
    firstmap['g'] = 700;
   cout<<"after clear"<<endl; 
   for(map<char,int>::iterator it=firstmap.begin();it != firstmap.end();it++)
  {
      cout<<it->first<<" => "<<it->second<<endl;
  } 
    
    
    for(map<char,int>::iterator it=secondmap.begin();it != secondmap.end();it++)
  {
      cout<<it->first<<" => "<<it->second<<endl;
  }*/
    
    char c;
    for (c='a'; c<'z'; c++)
  {
    std::cout << c;
    if (firstmap.count(c)>0)
      std::cout << " is an element of mymap.\n";
    else 
      std::cout << " is not an element of mymap.\n";
  }
    
    
    return 0;
}