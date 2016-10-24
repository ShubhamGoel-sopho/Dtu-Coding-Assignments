#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
/////////better version////////////////
using namespace std;
int main()
{
    ofstream fout;
    fout.open("file3.scm",ios::app);
    if(!fout)
    {
        cerr<<"there was an error in opening the file"<<endl;
        return 1;
    }
    else
    {
        
        //char name[50];
        //string name;
        int marks;

       int n;
       cout<<"how many record are there"<<endl;
       cin>>n;
     //   bool flag = true;
        int i=0;
        fflush(stdin);
       // char ch;
       fout<<"marks\n";
        while(i !=n)
        {
             
            //cout<<"enter name of student "<<i+1<<endl;
            //cin.get(ch);
            //getline(cin,name);
            cout<<"enter marks of the student "<<i+1<<endl;
            
            cin>>marks;
            /*if(name.compare("0") == 0)
            {
                flag = false;
                break;
            }*/
         //   fout<<name<<" --- ";
            fout<<marks<<"\n";
            i++;
        }
       /* fout<<"shubham goel shubham garg mr home holy functions ect i want to do \n";
        fout<<"18\n";
        fout<<"shivani\n";
        fout<<"15\n";*/
        fout.close();
        ifstream fin;
     fin.open("file3.scm",ios::in);
      if(!fin)
    {
        cerr<<"there was an error in opening the file"<<endl;
        return 2;
    }
    else
    {
        
    
    string x;
    
       
       
       while(!fin.eof())
       {
           getline(fin,x);
           cout<<x<<endl;
       }   
        fin.close();
        
    }
    
    
    
    
    
    
    
        
        
        
        
        
        
        
        
    }
    
    
   
    
    
    
    
    
    
    
    return 0 ;
}