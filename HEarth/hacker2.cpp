<<<<<<< HEAD
#include <iostream>
using namespace std;

struct x
{
	int *arr;
};
void merge(int *,int, int , int );
void mergesort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
}
void merge(int *a, int low, int high, int mid)
{
    int i, j, k, c[low+high+1];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] > a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
}
void printArray(int *A,int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int T;
	cin>>T;
    int N;
    x Array[T];
    int L[T];
    
   if(T>=1 && T<=100)
   {
   		for(int i=0;i<T;i++)
   		{
   			cin>>N;
   			L[i] = N;
	   		if(N >= 1 && N <= 100000)
	   		{
	   			Array[i].arr = new int[N];
	   			for(int j=0;j<N;j++)
	   			{
	   				cin>>Array[i].arr[j];
	   			}
	   			
	   		}
   		}
   		for(int i=0;i<T;i++)
   		{
   		
   			mergesort(Array[i].arr,0,L[i]-1);
   			printArray(Array[i].arr,L[i]);
   		}
   }
    return 0;
}

=======
#include <iostream>
using namespace std;

struct x
{
	int *arr;
};
void merge(int *,int, int , int );
void mergesort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
}
void merge(int *a, int low, int high, int mid)
{
    int i, j, k, c[low+high+1];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] > a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
}
void printArray(int *A,int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int T;
	cin>>T;
    int N;
    x Array[T];
    int L[T];
    
   if(T>=1 && T<=100)
   {
   		for(int i=0;i<T;i++)
   		{
   			cin>>N;
   			L[i] = N;
	   		if(N >= 1 && N <= 100000)
	   		{
	   			Array[i].arr = new int[N];
	   			for(int j=0;j<N;j++)
	   			{
	   				cin>>Array[i].arr[j];
	   			}
	   			
	   		}
   		}
   		for(int i=0;i<T;i++)
   		{
   		
   			mergesort(Array[i].arr,0,L[i]-1);
   			printArray(Array[i].arr,L[i]);
   		}
   }
    return 0;
}

>>>>>>> a3a9cc0590ad200d8e072f7eff31541cbda2e3a6
