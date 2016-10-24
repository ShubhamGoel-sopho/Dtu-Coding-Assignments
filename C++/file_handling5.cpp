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
    fout.open("file5.dat",ios::out|ios::binary);
    if(!fout)
    {
        cerr<<"there was an error in opening the file"<<endl;
        return 1;
    }
    else
    {
       
        int marks;
        float percentage;
        cout<<"enter marks"<<endl;
        cin>>marks;
        cout<<"enter %"<<endl;
        cin>>percentage;
        fout.write((char*) &marks,sizeof(int));
        fout.write((char*) &percentage,sizeof(float));
       
        fout.close();
        ifstream fin;
        fin.open("file5.dat",ios::in|ios::binary);
      if(!fin)
    {
        cerr<<"there was an error in opening the file"<<endl;
        return 2;
    }
    else
    {
        int m;
        float t;
        
     fin.read((char*) &m,sizeof(int));
     fin.read((char*) &t,sizeof(float));
     
     cout<<"marks "<<m<<endl;
     cout<<"% "<<t<<endl;
     fin.close();
        
    } }
    
    
   
    
    
    
    
    
    
    
    return 0 ;
}