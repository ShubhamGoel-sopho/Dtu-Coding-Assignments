#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 250
int top_1_location = (MAXSIZE/2)+1;
int top_2_location = (MAXSIZE/2)-1;
struct stack
{
	int Array[MAXSIZE];
	int top1;
	int top2;
};


void intialize_top(struct stack *(temp))
{
	temp->top1 = top_1_location;
	temp->top2 = top_2_location;
}




int IsEmpty_One(struct stack *temp)
{
	if(temp->top1 == top_1_location)
	return 1;
	else
	return 0;
}

int IsEmpty_Two(struct stack *temp)
{
	if(temp->top2 == top_2_location)
	return 1;
	else
	return 0;
}

int IsFull_One(struct stack *temp)
{
	if(temp->top1 == 0) 
	{
		return 1;
	}
	else
	return 0;
}
int IsFull_Two(struct stack *temp)
{
	if(temp->top2 == MAXSIZE-1)
	{
		return 1;
	}
	else
	return 0;
}

void Push_In_One(int element,struct stack *temp)
{
	if(!IsFull_One(temp))
	{
		temp->Array[--temp->top1] = element;
	}
	else
	{
		printf("stack one is now full no space left :(");
		return;
	}
}


void Push_In_Two(int element,struct stack *temp)
{
	if(!IsFull_Two(temp))
	{
		if(IsEmpty_Two(temp))
		{
			temp->top2 +=2;
			temp->Array[temp->top2] = element;
		}
		else
		temp->Array[++temp->top2] = element;
	}
	else
	{
		printf(" stack two is now full no space left :(");
		return;
	}
}



void Pop_One(struct stack *temp)
{
	if(!IsEmpty_One(temp))
	{
		printf("element going to deleted is : %d\n",temp->Array[temp->top1]);
		temp->top1++;
	}
	else
	{
		printf("sorry stack one is empty please fill in some items in that :(");
		return;
	}
}


void Pop_Two(struct stack *temp)
{
	if(!IsEmpty_Two(temp))
	{
	    if(temp->top2 == MAXSIZE/2)
	    {
	    	printf("sorry stack two is empty please fill in some items in that :(");
	    	temp->top2--;
		}
		else{
		
		printf("element going to deleted is : %d\n",temp->Array[temp->top2]);
		
		temp->top2--;
		}
	}
	else
	{
		printf("sorry stack two is empty please fill in some items in that :(");
		return;
	}
}


int main()
{
	struct stack S;
	intialize_top(&S);
	
	Push_In_One(10,&S);
	Push_In_One(20,&S);
	Push_In_One(30,&S);
	Push_In_One(40,&S);
	Push_In_One(50,&S);
	Push_In_Two(10,&S);
	Push_In_Two(30,&S);
	Push_In_Two(50,&S);
	Push_In_Two(70,&S);
	Push_In_Two(90,&S);
	
	Pop_One(&S);
	Pop_One(&S);
	Pop_One(&S);
	Pop_One(&S);
	Pop_One(&S);
	Pop_One(&S);
	printf("\n");
	Pop_Two(&S);
	Pop_Two(&S);
    Pop_Two(&S);
   	Pop_Two(&S);
	Pop_Two(&S);
	Pop_Two(&S);
	
	return 0;
	
}
