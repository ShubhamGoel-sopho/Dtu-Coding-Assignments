#include <iostream>

using namespace std;
class Queue
{
private:
	int *A;
	int size;
	int front, rear; 
public:
	// Constructor - set front and rear as -1. 
	// We are assuming that for an empty Queue, both front and rear will be -1.
	Queue(int n)
	{
		A = new int[n];
		size = n;
		front = -1; 
		rear = -1;
	}

	// To check wheter Queue is empty or not
	bool empty()
	{
	 if(rear == -1 && front == -1)
	 return true;
	 else
	 return false;
	}

	// To check whether Queue is full or not
	bool full()
	{
	     if(rear == size-1)
	     return true;
	     else
	     return false;
	}

	// Inserts an element in queue at rear end
	void push(int x)
	{
		cout<<"Enqueuing "<<x<<" \n";
		if(full())
		{
			cout<<"Error: Queue is Full\n";
			return;
		}
		if (empty())
		{ 
			front = rear = 0; 
		}
		else
		{
		    rear = (rear+1);
		}
		A[rear] = x;
	}

	// Removes an element in Queue from front end. 
	void pop()
	{
		cout<<"Dequeuing \n";
		if(empty())
		{
			cout<<"Error: Queue is Empty\n";
			return;
		}
		else if(front == rear ) 
		{
			rear = front = -1;
		}
		else
		{
			front = (front+1);
		}
	}
	// Returns element at front of queue. 
	int Front()
	{
		if(front == -1)
		{
			cout<<"Error: cannot return front from empty queue\n";
			return -1; 
		}
		return A[front];
	}

};


int main()
{
  short N;
  cin>>N;
  int x;
  
  Queue real(N),ideal(N);
  for(int i=0;i<N;i++)
  {
  	cin>>x;
  	real.push(x);
  	
  }
  for(int i=0;i<N;i++)
  {
  	cin>>x;
  	ideal.push(x);
  	
  }
  
  int count = 0;
  int frontreal,frontideal;
  while(!real.empty())
  {
  	frontreal = real.Front();
  	frontideal = ideal.Front();
  	if(frontreal == frontideal)
  	{
  		count++;
  		real.pop();
  		ideal.pop();
  	}
  	else
  	{
  		int fr = real.Front();
  		real.pop();
  		real.push(fr);
  		count++;
  	}
  	
  }
  
  
  
  cout<<count<<endl;
  
  
  
  
  
  
  
  
    
    return 0;
}

