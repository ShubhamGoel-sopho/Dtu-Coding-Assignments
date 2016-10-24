#include<iostream>
using namespace std;

//practising the pure virtual functions 
//creating the base abstract class whose object is never gonna instantiated
class numberdecimal
{
    private:
    int number;
    public:
    numberdecimal(int x)
    {
        //cout<<"enter the number:"<<endl;
        number = x;
    }
    int retnumber()
    {
        return number;
    }
    
//    virtual void shownumber() = 0;
};

class octal:public numberdecimal
{
  public:
  octal(int x):numberdecimal(x){}
  
  void shownumber()
  {
     cout<<"the octal representation of the no is:"<<endl;
     cout.unsetf(ios::dec);
     cout.setf(ios::oct|ios::showbase);
     std::cout << retnumber() << std::endl;
     cout.unsetf(ios::oct);
     cout.setf(ios::dec|ios::showbase);
  }
  
};

class hexadecimal:public numberdecimal
{
  public:
  hexadecimal(int x):numberdecimal(x){}
  
  void shownumber()
  {
     cout<<"the hexadecimal representation of the no is:"<<endl;
     cout.unsetf(ios::dec);
     cout.setf(ios::hex|ios::showbase);
     std::cout << retnumber() << std::endl;
     cout.unsetf(ios::hex);
     cout.setf(ios::dec|ios::showbase);
  }
  
};



int main()
{
    octal b(143);
    b.shownumber();
   hexadecimal h(158);
   h.shownumber();
    return 0;
}