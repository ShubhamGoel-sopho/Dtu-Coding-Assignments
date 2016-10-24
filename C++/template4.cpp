#include <iostream>
#include<string.h>
using namespace std;
//union of two sets using inheritance a basic example//
template <class T,unsigned int Size>
class Bag
{
    protected:
    T ArrayBag[Size];
    int itemcount;
    public:
    Bag()
    {
        itemcount = 0;
    }
    
    void fillbag(T val)
    {
        ArrayBag[itemcount] = val;
        itemcount++;
    }
    bool empty()
    {
        if(itemcount == 0)
        {
            return true;
        }
        else 
        return false;
    }
    
    bool isfull()
    {
        if(itemcount == Size)
        {
            return true;
        }
        else
        {
           return false;
        }
    }
    
    
    bool isexist(T val);
    void show();
};

template <class T,unsigned int Size>
bool Bag<T,Size>::isexist(T val)
{
    bool flag = false;
    for(int i=0;i<itemcount;i++)
    {
        if(ArrayBag[i]==val)
        {
            flag = true;
            break;
        }
    }
    if(flag == true)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

template <class T,unsigned int Size>
void Bag<T,Size>::show()
{
    cout<<"the elements in the bag are:"<<endl;
    for(int i=0;i<itemcount;i++)
    {
        cout<<"element "<<i+1<<":"<<ArrayBag[i]<<endl;
    }
}

template <class T,unsigned int Size>
class Set:public Bag<T,Size>
{
  public:
  void add(T ele)
  {
      if(!this->isfull() && !this->isexist(ele))
      {
          this->fillbag(ele);
          
      }
  }
  void read()
  {
      T x;
      cout<<"enter the values 0 to stop:"<<endl;
      for(int i=0;i<Size;i++)
      {
          cin>>x;
          if(x !=0)
          {
              add(x);
          }
          else
          {
              break;
          }
      }
  }
  
    //void operator =(Set s);
    Set operator +(Set s1); 
};

//template <class T,unsigned int Size>
/*void Set<T,Size>::operator =(Set<T,Size> s)
{
    this->itemcount = s.itemcount;
    for(int i=0;i<s.itemcount;i++)
    {
        this->ArrayBag[i] = s.ArrayBag[i];
    }
}*/

template <class T,unsigned int Size>
Set<T,Size> Set<T,Size>::operator +(Set<T,Size> s1)
{

    Set <T,Size> temp;
    
    for(int i=0;i<this->itemcount;i++)
    {
        temp.ArrayBag[i] = this->ArrayBag[i];
    }
    temp.itemcount = this->itemcount;
    for(int i=0;i<s1.itemcount;i++)
    {
        if(!this->isexist(s1.ArrayBag[i]))
        {
            temp.add(s1.ArrayBag[i]);
        }
    }
    
    return (temp);
}








int main()
{
  
   
   Set <int,25> s1;
   Set <int,25> s2;
   Set <int,25> s3;
   cout<<"enter the s1 elements"<<endl;
   s1.read();
   cout<<"----------------------------------------------------------"<<endl;
   cout<<"enter the s2 elements "<<endl;
   s2.read();
   cout<<"----------------------------------------------------------"<<endl;
   cout<<"the union of both the s1 and s2 is"<<endl;
   s3 = (s1+s2);
   cout<<"now the element in s3 are:"<<endl;
   s3.show();
   cout<<"----------------------------------------------------------"<<endl;
   
    
    return 0;
}