#include <iostream>
#include<string.h>
using namespace std;



struct student
{
    char name[30];
    int age;
    char collegecode;
};
//swap function
template <class T>
void swaped(T& a,T& b)
{
    T temp ;
    temp = a;
    a = b;
    b = temp;
}

ostream& operator <<(ostream &out,student &s)
{
    out<<"name of student is :"<<s.name<<endl;
    out<<"age of the student is:"<<s.age<<endl;
    out<<"college code of the student is:"<<s.collegecode<<endl;
    
    return out;
}






template <class T>
void display(T& t)
{
    cout<<t<<endl;
}






int main()
{
   student s;
   strcpy(s.name,"shubham goel");
   s.age = 18;
   s.collegecode = 'D';
   display("Delhi Technological University");
   int year = 1996;
   display(year);
   display("student details");
   display(s);
   
   
   
   
   
   
   
   
   
    
    return 0;
}