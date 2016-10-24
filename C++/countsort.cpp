#include <iostream>
using namespace std;

void countsort(int *A,int *B,int *C,int sizeA,int range)
{
    ////initialized c array with 0////////
    for(int i=0;i<range;i++)
    {
        C[i] = 0;
    }
////////////now in the C array i have count of every no occurance////////    
    for(int i=0;i<sizeA;i++)
    {
        C[A[i]] = C[A[i]]+1;
    }
    
    for(int j =1;j<range;j++)
    {
        C[j] =  C[j]+C[j-1];
    }
    
    for(int k = sizeA-1;k>=0;k--)
    {
        B[C[A[k]]-1] = A[k];
        C[A[k]] -=1;
    }
    
    
    
}




int main()
{
    int A[] = {5,9,7,5,3,0,2,0,1,3,6,8,7,8,9,5,4,1,2,3,0,4,5,7};
    int B[24];
    int *C = new int[10];
    countsort(A,B,C,24,10);
    cout<<"Array after sort looks like :"<<endl;
    for(int i=0;i<24;i++)
    {
        cout<<B[i]<<" --- ";
    }
    cout<<endl;
    //delete C;
    return 0;
}