#include<iostream>
#include<map>
using namespace std;
int main()
{
  /*
   for(map<char,int>::iterator it=mymap.begin();it != mymap.end();it++)
  {
      cout<<it->first<<" => "<<it->second<<endl;
  } */
  std::map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;
  mymap['d']=40;
  mymap['a']=50;
  /*while (!mymap.empty())
  {
    std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
    mymap.erase(mymap.begin());
  }*/
 for(map<char,int>::iterator it=mymap.begin();it != mymap.end();it++)
  {
      cout<<it->first<<" => "<<it->second<<endl;
  } 
    
    
    map<char,int>::iterator it ;
    it=mymap.find('a');
    mymap.erase(it);
    
    for(map<char,int>::iterator it=mymap.begin();it != mymap.end();it++)
  {
      cout<<it->first<<" => "<<it->second<<endl;
  } 
    it = mymap.find('c');
    mymap.erase(it,mymap.end());
    for(map<char,int>::iterator it=mymap.begin();it != mymap.end();it++)
  {
      cout<<it->first<<" => "<<it->second<<endl;
  } 
    
    
    return 0;
}