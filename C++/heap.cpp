#include <iostream>

using namespace std;
const int maxsize = 255;
class Heap {
private:
  int heaparray[maxsize];
  int track_last_index;
public:
    Heap()
    {
        track_last_index = -1;
    }
    
  void Insert_heap(int value);
  void delete_heap();
  void delete_downwards(int start,int end);
  void print_heap();
  ~Heap();
};
void Heap ::Insert_heap(int value)
{
    int index;
    int index2;
    if(track_last_index == -1)
    {
        track_last_index +=1;
        heaparray[track_last_index] = value;
    }
    else
    {
        track_last_index +=1;
        heaparray[track_last_index] = value;
        
        index = track_last_index;
        
        index2 = (index-1/2);
        if(value > heaparray[index2])
        {
        while((value > heaparray[index2]) && (index >0))
        {
           
           heaparray[index]=heaparray[index2];
           index=index2;
           index2=index2-1/2;

        }
        heaparray[index] = value;
        }
       
    }



}

void Heap ::delete_heap()
{
    if(track_last_index !=-1)
    {
    int index = 0;
 
    if(track_last_index == 0)
    {
        track_last_index = -1;
        cout << "heap is empty now "<<endl;
    }
    else
    {
        heaparray[index] = heaparray[track_last_index];
        track_last_index--;
        delete_downwards(index,track_last_index);
    }}
    else
    {
        cout<<"heap is empty cant delete anything"<<endl;
        
    }
}
void Heap::delete_downwards(int start,int end)
{
    int max,lchild,rchild,temp,index2;
    
    lchild = 2*start+1;
    rchild = lchild+1;
    if(lchild<=end)
    {
        max = heaparray[lchild];
        index2 = lchild;
            if(rchild <= end)
            {
                if(heaparray[rchild] > max)
                {
                    max  = heaparray[rchild];
                    index2 = rchild;
                }}
                
                if(heaparray[start]<heaparray[index2])
                {
                    temp = heaparray[start];
                    heaparray[start] = heaparray[index2];
                    heaparray[index2]=temp;
                    delete_downwards(index2,end);
                    }
    }}

void Heap ::print_heap()
{
    if(track_last_index !=-1)
    {
        for(int i=0;i<=track_last_index;i++)
        {
            cout<<"Heap "<<i+1<<" "<<heaparray[i]<<endl;
        }
    }
}
    
Heap::~Heap()
{
    cout<<"destructor on the work"<<endl;

}
      

int main()
{    
    Heap H;
    int choice;
    int ele;
    do
    {
        cout<<"Enter 1. to insert in the Heap"<<endl;
        cout<<"Enter 2. to delete in the Heap"<<endl;
        cout<<"Enter 3. to print the heap "<<endl;
        cout<<"Enter Any other number to quit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1: cout<<"Enter the element to be inserted"<<endl;
                    cin>>ele;
                    H.Insert_heap(ele);
                    break;
            case 2: cout<<"OK the root element will be deleted"<<endl;
                    H.delete_heap();
                    break;
            case 3: cout<<"Ok the heap looks like"<<endl;
                    H.print_heap();
                    break;
            default : cout<<"Ok"<<endl;
                    break;
        }
        
    }while(choice<=3&&choice>=1);


    return 0;
}
