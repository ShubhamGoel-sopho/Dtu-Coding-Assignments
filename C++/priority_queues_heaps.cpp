#include <iostream>
#include <algorithm>
using namespace std;

/* here we are going to make a priority queue in full working mode 
 * by implementing the heap sort and by creating the min heap produces
 * list in the ascending order... 
 * This is the Array implementation of Priority Queues
 */
 
struct P_queue
{
	int heap_type; 	// 1 for min heap and -1 for max heap
	int *Array;
	int size;
	int capacity;
};

void resizeheap(P_queue &temp);
void initialize_heap(P_queue &temp,int  capacity,int heap_type) //time complexity O(1). initialization of heap
{
	temp.heap_type = heap_type; 
	temp.Array = NULL;
	temp.Array = new int[capacity];
	if(temp.Array == NULL)
	{
		cout<<"Memory error couldn't initialize Heap :("<<endl;
		return ;
		
	}
	else
	{
	 	temp.capacity = capacity;
		temp.size = 0;
	}
}

int GetMin(P_queue &temp) //time complexity O(1)
{
	if(temp.heap_type == 1){
		if(temp.size == 0)
		{
			return -1;
		}
		else
		{
			return temp.Array[0];
		}
	}
	else
	{
		return -1;
	}	
	
}

int GetMax(P_queue &temp)	//time complexity O(1)
{
	if(temp.heap_type == -1){	
		if(temp.size == 0)
		{
			return -1;
		}
		else
		{
			return temp.Array[0];
		}
	
	}
	else
	{
		return -1;
	}
}
int left_right_parent(P_queue &temp,int i)	//time complexity O(1)
{
	if(i <= 0 || i >= temp.size)
	{
		return -1;
	}
	else
	{
		return i-1/2;
	}
	
}
void Insert_Element(P_queue &temp,int data)  //used to insert the element the element in the heap. time complexity O(log n)
{
	int i;
	
	if(temp.size == temp.capacity)
		resizeheap(temp);
	temp.size++;
	if(temp.heap_type == 1){ 
		i = temp.size-1;
		while(i>=0 && data < temp.Array[(i-1)/2]){
			temp.Array[i] = temp.Array[(i-1)/2];
			i = i-1/2;
		}		
		 	temp.Array[i] = data;
	}
	else
	{
		i = temp.size-1;
		while(i>=0 && data > temp.Array[(i-1)/2]){
			temp.Array[i] = temp.Array[(i-1)/2];
			i = i-1/2;
		}		
		 	temp.Array[i] = data;
	
	}	 	
 }

int Get_left_child(P_queue &temp,int pos) //time complexity O(1)
{
	int left = 2*pos+1;
	if(left >= temp.size)
	{
		return -1;
	}
	else
	return left;
}

int Get_right_child(P_queue &temp,int pos) //time complexity O(1)
{
	int right = 2*pos+2;
	if(right >= temp.size)
	{
		return -1;
	}
	else
	return right;
}



void Percolate_Down(P_queue &temp,int i)  //used to Delete the element in the heap as always the minimun or the maximum element got deleted
{
	int var,left,right,max,min;
	left = Get_left_child(temp,i);
	right = Get_right_child(temp,i);
	
	
	if(temp.heap_type == 1)
	{
		// delete the minimum element in the heap
		if((left != -1) && (temp.Array[left] < temp.Array[i]))
		{
			min = left;
		}
		else min = i;
		
		if((right != -1) && (temp.Array[right] < temp.Array[min]))
		{
			min = right;
		}
		if(min != i)
		{
			swap(temp.Array[i],temp.Array[min]);
		}
		
		Percolate_Down(temp,min);	
			
	}
	else
	{
		// delete the maximum element in the heap
		if((left != -1) && (temp.Array[left] > temp.Array[i]))
		{
			max = left;
		}
		else max = i;
		
		if((right != -1) && (temp.Array[right] < temp.Array[max]))
		{
			max = right;
		}
		if(max != i)
		{
			swap(temp.Array[i],temp.Array[max]);
		}
		
		Percolate_Down(temp,max);	
	
	} 
	
}


int Delete_Max_Min(P_queue &temp) // time complexity O(log n). Deletion takes the constant time and percolate_Down takes the O(log n) time
{
	int var;
	if(temp.size == 0)
		return -1;
		
		var = temp.Array[0];
		temp.Array[0] = temp.Array[temp.size-1];
		temp.size--;
		Percolate_Down(temp,0);
		
		return var;
		
}



void resizeheap(P_queue &temp)
{
	int *old_ptr = temp.Array;
	temp.Array = new int[temp.capacity*2];
	if(temp.Array == NULL)
	{
		cout<<"Memory error"<<endl;
		return;
	}
	for(int i=0;i< temp.capacity;i++)
	{
		temp.Array[i] = old_ptr[i];
	}
	temp.capacity *=  2;
	delete old_ptr;

}
		

P_queue BuildHeap(int A[],int size) // to build the heap from the given array
{
	P_queue temp;
	initialize_heap(temp,size,1);
	for(int i=0;i<size;i++)
	{
		Insert_Element(temp,A[i]);
	}
	return temp;
}

void HeapSort(int A[],int size) //produces the sorted list from the given array in O(n*log(n)) using the Build Heap functionality
{
	P_queue temp = BuildHeap(A,size);
	
	int data_top = temp.Array[0];
	
	for(int i=0;i<size;i++)
	{
		data_top = Delete_Max_Min(temp);
		cout<<data_top<<endl;
	}
}	




int main()
{
	int A[] = {9,7,8,6,5,4,3,2,1};
	HeapSort(A,9);




	return 0;	
}	
	
	
	
		
	

	

		
		



