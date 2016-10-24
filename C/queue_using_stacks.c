#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 250 //maxsize already defined of queue
/* implementing queue using stacks */
/* this can be implemented usng two stacks*/


struct stack
{
	int Array[MAXSIZE];
	int top;
};


void intialize_top(struct stack *(temp))
{
	temp->top = -1;
}




int IsEmpty(struct stack *temp)
{
	if(temp->top == -1)
	return 1;
	else
	return 0;
}



int IsFull(struct stack *temp)
{
	if(temp->top == MAXSIZE-1)
	{
		return 1;
	}
	else
	return 0;
}

void Push(struct stack *temp,int element)
{
	if(!IsFull(temp))
	{
		temp->Array[++temp->top] = element;
	}
	else
	{
		printf("stack is now full no space left :(");
		return;
	}
}

int Top(struct stack (*temp))
{
	if(!IsEmpty(temp))
	{
		return temp->Array[temp->top];
	}
	else
	{
		return -1;
	}
}






void Pop(struct stack *temp)
{
	if(!IsEmpty(temp))
	{
	//	printf("element going to deleted is : %d\n",temp->Array[temp->top]);
		temp->top--;
	}
	else
	{
		printf("sorry stack is empty please fill in some items in that :(");
		return;
	}
}

int main()
{
	
	struct stack s1,s2;
	intialize_top(&s1);
	intialize_top(&s2);
	int choice;
	
do{
	
	printf("enter 1 to insert the element in to queue \n : ");
    printf("enter 2 to delete the element in to queue \n : ");
	printf("enter 3 to get the front element in the queue \n:");
	printf("enter 0 to exit");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1 : 
			   	 
			   	 printf("enter the element to insert \n");
			   	 int info;
		   	     scanf("%d",&info);
			   	 Push(&s1,info);
			   	 break;
		case 2 :
			
			   	if(IsEmpty(&s2))
  				{
				 	while(!IsEmpty(&s1))
	 				{
					 	int top = Top(&s1);
		                Pop(&s1);
					    Push(&s2,top);	
  					}
			    }
				int top = Top(&s2);
				Pop(&s2);
				printf("element deleted is %d \n",top);
				break;
  					
  		case 3 :
  		 	   	printf("element on front is ");
  				int tope = Top(&s2);	
			    printf("%d",tope);
				break;
  		default : break;			
		  			
	};
	
	
	
	
		
}while(choice != 0);
	
	
	
	
	
	
	return 0;
}
