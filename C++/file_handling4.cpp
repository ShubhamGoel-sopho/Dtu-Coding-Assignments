#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
/////////using by cha acter and chars////////////////
using namespace std;
int main()
{
    ofstream fout;
    fout.open("file4.txt",ios::out);
    if(!fout)
    {
        cerr<<"there was an error in opening the file"<<endl;
        return 1;
    }
    else
    {
        
     
        
        char ch;
        cout<<"start entering the the lines"<<endl;
        char c;
        bool x= true;
        while(x)
        {
             
            cin.get(ch);
            if(ch == 126)
            {
                cout<<"are you sure"<<endl;
                cin>>c;
                if(c == 'Y' || c=='y')
                {
                    x = false;
                    break;
                }
                else
                {
                    fout.put(ch);
                    continue;
                }
            }
            fout.put(ch);
           
        }
       
        fout.close();
        ifstream fin;
        fin.open("file4.txt",ios::in);
      if(!fin)
    {
        cerr<<"there was an error in opening the file"<<endl;
        return 2;
    }
    else
    {
        
    
    
    
       char ch1;
       
       while(!fin.eof())
       {
          //getline(fin,x);
          
           fin.get(ch1);
           cout<<ch1;
       }   
        fin.close();
        
    }
    
    
    
    
    
    
    
        
        
        
        
        
        
        
        
    }
    
    
   
    
    
    
    
    
    
    
    return 0 ;
}