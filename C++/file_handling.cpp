#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;
int main()
{
    ofstream fout;
    fout.open("file1.txt",ios::app);
    if(!fout)
    {
        cerr<<"there was an error in opening the file"<<endl;
        return 1;
    }
    else
    {
        string mystring;


        cout<<"enter the line of the text which oyu want to store in the file"<<endl;
        cout<<"enter (enter) key for new line"<<endl;
        cout<<"0 in the new line to stop"<<endl;
        bool flag = true;
        while(flag)
        {
            
            getline(cin,mystring);
            if(mystring.compare("0") == 0)
            {
                flag = false;
                break;
            }
            fout<<mystring<<"\n";
        }
       /* fout<<"shubham goel shubham garg mr home holy functions ect i want to do \n";
        fout<<"18\n";
        fout<<"shivani\n";
        fout<<"15\n";*/
        fout.close();
     ifstream fin;
     fin.open("file1.txt",ios::out);
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