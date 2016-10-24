#include <iostream>
using namespace std;

//swap function
template <class T>
void swaped(T& a,T& b)
{
    T temp ;
    temp = a;
    a = b;
    b = temp;
}






//bubble sort using the template class
template <class T>
void Bubblesort(T& arr,int arrsize)
{
    bool flag;
    for(int i=0 ;i<arrsize-1;i++)
    {
        flag = true;
        for(int j=0;j<(arrsize-1-i);j++)
        {
            if(arr[j]>arr[j+1])
            {
                
               swaped(arr[j],arr[j+1]);
               flag = false; 
            }
        }
        if(flag == true )
        {
            break;
        }
        
    }
    
    
}


int main()
{
    float array[] = {4.56,41.89,45.36,1.52,2.78,7.45,15.14};
    
    Bubblesort(array,7);
    cout<<"after sorting the array:"<<endl;
    for(int i=0;i<7;i++)
    {
        cout<<array[i]<<endl; 
    }
    
    return 0;
}