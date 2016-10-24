/** 
  * Shubham Goel==>2K15/MC/084==>MCE==>SectionB
  * Implementing the priority queues data structure through linear structure
  * called Array
  *
**/

#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 250

//declaration of structure queue
struct P_queue
{
	int Array[MAXSIZE];
	int front;
	int rear;
	int min;
};


//initializing the queue
void initialize_Pqueue(struct P_queue *(temp))
{
	temp->front = -1;
	temp->rear  = -1;
	temp->min = INT_MIN;   //initialized min to smallest possible value
}

//function to find the minimum element in the queue and to return it
int find_min(struct P_queue *(temp))
{
	int start = temp->front+1;
	int end = temp->rear;
	int min = temp->Array[start];
	int i;
	int index = start;
	for(i = start+1;i <= end;i++)
	{
		if(temp->Array[i] < min)
		{
			min = temp->Array[i];
			index = i;
		}
	}
	
	return index;
}

//swap routine 
void swapval(int *p,int *q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}


//boolean type function to check queue empty or not
int isempty(struct P_queue *(temp))
{
	if(temp->front == -1 && temp->rear == -1)
	{
		return 1; //true empty
	}
	else
	{
		return 0;//false not empty
	}
	
}

//function to return the minimum element present at the front
void return_min(struct P_queue *(temp))
{
	if(!isempty(temp))
	{
		printf("The minimun value is : %d \n",temp->min);
	}
}



//function to check whether queue is full or not
int isfull(struct P_queue *(temp))
{
	if(temp->rear == MAXSIZE-1)
	{
		return 1;//true full 
	}
	else
	{
		return 0;//false not full
	}
}



void add_element(int data,struct P_queue *(temp))
{
	if(isempty(temp))
	{
		printf("Added = %d \n",data);
		temp->Array[++(temp->rear)] = data;
		++(temp->front);
		temp->min = temp->Array[temp->front];
	}
	else if(isfull(temp))
	{
		printf("Sorry The List is Now Full Cannot Add more items :(");
	}
	else
	{
		printf("Added = %d \n",data);
		if(data < temp->Array[temp->front])
		{
			temp->rear = temp->rear+1;
			temp->Array[temp->rear] = temp->Array[temp->front];
			temp->Array[temp->front] = data;
			temp->min = data;
		}
		else
		{
		 	temp->Array[++(temp->rear)] = data;
	    }
	}
}

//function to delete an item from the queue
void delete_element(struct P_queue *(temp))
{
	
    if(isempty(temp))
	{
		printf("Sorry the list is Empty Nothing to delete :( \n");
	}
	else
	{
		if(temp->front == temp->rear)
		{
			printf("element going to deleted is : %d\n",temp->Array[temp->front]);
			initialize_Pqueue(temp);
		}
		else
		{
			printf("element going to deleted is : %d\n",temp->Array[temp->front]);
			int index = find_min(temp);
			temp->min = temp->Array[index];
			temp->front = temp->front+1;
			swapval(&(temp->Array[temp->front]),&(temp->Array[index]));
		}
	}
}





int main()
{
	struct P_queue list;
	initialize_Pqueue(&list);
	add_element(10,&list);
	add_element(3,&list);
	add_element(9,&list);
	add_element(12,&list);
	add_element(2,&list);
	return_min(&list);
	delete_element(&list);
	delete_element(&list);
	delete_element(&list);
	delete_element(&list);	
	add_element(1,&list);
	add_element(18,&list);
	return 0;
}

