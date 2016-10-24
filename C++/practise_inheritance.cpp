#include <iostream>
using namespace std;

class X 
{
  private:
  int x;
  public:
  X(int i)
  {
      x = i;
  }
 
 int getx() const
 {
     return x;
 }
  
};

class Y : public virtual X
{
    private:
    int b;
    int c;
    public:
    Y(int i,int j):X(i)
    {
        b = i;
        c = j;
    }
    
    int getYb()  const
    {
        return b;
    }
    int getYc()  const
    {
        return c;
    }    
};

class Z : public virtual X
{
    private:
    int m;
    int n;
    public:
    Z(int i,int j):X(i)
    {
        m = i;
        n = j;
    }
    
    int getm()  const
    {
        return m;
    }
    int getn()  const
    {
        return n;
    }    
};

class set : public Z,public Y
{
    private:
    int h;
    int k;
    public:
    set(int i,int j):X(i),Z(i,j),Y(i,j)
    {
        
        h = i;
        k = j;
    }
    
    void show()
    {
        cout << "set class h "<<h<<endl;
        cout << "set class k "<<k<<endl;
        cout << "X class x "<<getx()<<endl;
        cout << "Y class b  "<<getYb()<<endl;
        cout << "Y class c  "<<getYc()<<endl;
        cout << "Z class m  "<<getm()<<endl;
        cout << "Z class n  "<<getn()<<endl;
    }
    
    
    
    
    
    
    
};


int main()
{
    set doctor(4,5);
    doctor.show();
    cout<<"size of doctor"<< sizeof(doctor)<<endl;
    return 0;
}






