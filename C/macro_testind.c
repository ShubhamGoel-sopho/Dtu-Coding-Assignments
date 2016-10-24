#include<iostream>

#pragma startup fun1()
#pragma startup fun2()
#pragma exit fun3()
using namespace std;
void fun2()
{
     cout<<"hi we are in the fun 2"<<endl;
     }
     void fun1()
     {
          cout<<"hi we are in the fun1"<<endl;
          }
          int main()
          {
              cout<<"hi we are in the main "<<endl;
              
              system ("pause");
              return 0 ;
              }
              void fun3()
              {
                   cout<<"we are int the fun3"<<endl;
                   }
                   
