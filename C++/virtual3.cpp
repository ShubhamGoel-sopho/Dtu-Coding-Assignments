#include<iostream>
#include<iomanip>
using namespace std;

//practising the pure virtual functions 
//creating the base abstract class whose object is never gonna instantiated
//need of virtual function shown here


int decimal_binary(int n)  /* Function to convert decimal to binary.*/
{
    int rem, i=1, binary=0;
    while (n!=0)
    {
        rem=n%2;
        n/=2;
        binary+=rem*i;
        i*=10;
    }
    return binary;
}


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
    
    virtual void shownumber() = 0;
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

class binary:public numberdecimal
{
  public:
  binary(int x):numberdecimal(x){}
  
  void shownumber()
  {
     cout<<"the binary representation of the no is:"<<endl;
     int n = retnumber();
     std::cout << decimal_binary(n) << std::endl;
     //setbase(10);
  }
  
};






int main()
{
    numberdecimal *num = new octal(147);
    num->shownumber();
    
    delete num;
    
    
    num = new hexadecimal(456);
    
    num->shownumber();
    delete num;
    
    num = new binary(568);
    num->shownumber();
    delete num;
    
    
    return 0;
}