#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    /*char *mystring = "I love my india";
    char *mystring = new char[20];
    cout<<"enter your name:"<<endl;
    gets(mystring);
    puts(mystring);
    cout<<"your saved string is: "<<mystring<<endl;
    cout<<"length of string "<<strlen(mystring)<<endl;*/
 /*   string mystring ;
    cout<<"enter :"<<endl;
    getline(cin,mystring);
    cout<<mystring<<endl;
    cout<<mystring.length()<<endl;
    for(int i=0;i<mystring.length();i++)
    {
        cout<<mystring[i];
    }
    cout<<endl;*/
    string mystring1;
    vector<string> mystring;
    cout<<"enter the name of the person enter null to stop"<<endl;
    int i=1;
    do{
       cout<<"person "<<i<<endl;
       getline(cin,mystring1);
       if(mystring1.compare("null") !=0  && mystring1.compare("NULL") !=0)
       {
           mystring.push_back(mystring1);
       }
        i++;
        
    }while(mystring1.compare("null") !=0 && mystring1.compare("NULL") !=0);
   sort(mystring.begin(),mystring.end());
   cout<<"after sorting the list the names are"<<endl;
   for(unsigned int i=0;i<mystring.size();i++)
   {
       cout<<"person : "<<i+1<<" "<<mystring.at(i)<<endl;
   }
    
    /*
    
    
     char *msg = "welcome back to coding";
    cout<<msg<<endl;
    puts(msg);
    char name[30];
    cout<<"enter the name name"<<endl;
    gets(name);
    char *ptr=name;
    cout<<name<<endl;
    cout<<ptr<<endl;
    for(int i =0;*ptr !='\0';i++)
    {
            cout<<*ptr<<"..";
            ptr++;
            
}
cout<<endl;
for(int k=0;name[k]!='\0';k++)
{
        cout<<name[k];
        }
        cout<<endl;
    char *top="you are tyhe topper";
                
  for(int i= 0;*top !='\0';i++) 
    {
            cout<<*top;   
            top++;     
            }
    
    char *tope ="my another skill";
    for(int i= 0;tope[i]!='\0';i++)
      
    {
            cout<<tope[i];
            
            }  
            cout<<endl;
            cout<<"my skillls continue"<<endl;
            char nam[50];
            char *pt=nam;
            cout<<"enter the another the name "<<endl;
            gets(pt);
            cout<<endl;
            cout<<pt<<endl;          
            
            
                       
    char *jkl = "welcome to the india";
  *jkl+2;
    cout<<jkl;
    
    char *person[5];
   for(int i=0;i<5;i++)
   {
           person[i]=new char[20];
           cout<<"enter the person"<<i<<endl;
           gets(person[i]);
           cout<<endl;
           }
         for(int i=0;i<5;i++)
   {
           
           cout<<" the person"<<i<<endl;
           puts(person[i]);
           cout<<endl;
           }                     
                 char *temp;
                 temp=person[2];
                 person[2]=person[3];
                 person[3]=temp;
                 
                 cout<<endl;
                   for(int i=0;i<5;i++)
   {
   
           cout<<" the person"<<i<<endl;
           puts(person[i]);
           cout<<endl;
           }
                 
    
    */    return 0;
}