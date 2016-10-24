#include <iostream>
#include <string>
using namespace std;

//practising the virtual inheritance;


class father
{
    private:
    int age;
    
    public:
    father(int a)
    {
        age = a;
        
    }
    
    int retage() const
    {
        return age;
    }
    
    virtual void showage()  const
    {
        std::cout << "the father age is : "<<retage()<< std::endl;
    }
};

class son : public father
{
    private:
    int age;
    public:
    son(int x,int y):father(y)
    {
        age = x;
    }
   int retsonage() const
    {
        return age;
    }
    
     void showage()  const
    {
        std::cout << "the son age is : "<<retsonage()<< std::endl;
    } 
    void showword()
    {
        cout<<"father always remains father and son always son : "<<endl;
    }
    
};

int main()
{
    father *f = NULL;
    f = new father(55);
    f->showage();
    
    delete f;
    
    f = new son(18,55);
    f->showage();
    //f->showword();//we cant use this as a rule
    //but
    ((son*)f)->showword();
    
    return 0;
}



















