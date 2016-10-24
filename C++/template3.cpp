#include <iostream>
using namespace std;

//development of the stack class with Template programming
template <class T,unsigned int Size>
class Stack
{
  private:
  T array[Size];
  unsigned int Top;
  public:
  Stack()
  {
      Top = 0;
  }
  void pushstack(T ele)
  {
      if(Top<Size){
      Top++;
      array[Top] = ele;
          std::cout << "inserted :>" << std::endl;
      }
      else
      {
          cout<<"overflow stack is full now:"<<endl;
      }
  }
  T Gettop()
  {
      return array[Top];
  }
  bool empty()
  {
      if(Top == 0)
      {
          return true;
      }
      else
      {
          return false;
      }
  }
  bool full()
  {
      if(Top == Size)
      {
          return true;
      }
      else
      {
          return false;
          
      }
  }
  void popfullstack();
  void popstack();
    
};

template <class T,unsigned int Size>
void Stack<T,Size>::popstack()
{
    if(Top != 0)
    {
        Top--;
        std::cout << "popped :>" << std::endl;
    }
    else
    {
        std::cout << "stack is already empty" << std::endl;
    }
    
}

template <class T,unsigned int Size>
void Stack<T,Size>::popfullstack()
{
    while(Top !=0)
    {
        if(Top != 0)
        {
            cout<<array[Top]<<" => is going to popped :<"<<endl;
            Top--;
            std::cout << "popped :>" << std::endl;
            
        }
        else
        {
            cout<<"stack is fully emptied"<<endl;
            break;
        }
    }
}

















int main()
{
 
/* int size;
    cout<<"enter the size:";
    cin>>size;
 int array[size];
    cout<<"enter elements:"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>array[i];
        
        
        
    }
    for(int i=0;i<size;i++)
    {
        cout<<array[i]<<endl;
        
        
        
    }*/
    
    Stack<int,25> int_stack;
    int_stack.pushstack(10);
    int_stack.pushstack(20);
    int_stack.popstack();
    int_stack.pushstack(20);

    int_stack.pushstack(30);
    int_stack.pushstack(40);
    int_stack.pushstack(50);
    int_stack.pushstack(60);
    int_stack.pushstack(70);
    int_stack.pushstack(80);
int_stack.pushstack(90);
int_stack.pushstack(100);
int_stack.popfullstack();
    
    
    
    
    
    
    return 0;
}