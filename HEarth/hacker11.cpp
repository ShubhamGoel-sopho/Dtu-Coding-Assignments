#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
/*
 * Node Declaration
 */
struct node
{
    int info;
    struct node *next;
    struct node *prev;
}*last,*first;
 
/*
 * Class Declaration
 */
class circular_llist
{
    public:
        void create_node(int value);
        
        circular_llist()
        {
            last = NULL;  
			first = NULL;         
        }
};
 

/*
 * Create Circular Link List
 */
void circular_llist::create_node(int value)
{
    struct node *temp;
    temp = new(struct node);
    temp->info = value;
    if (last == NULL)
    {
        last = temp;
        first = last;
        temp->next = last; 
		temp->prev = last;  
    }
    else
    {
    	
    	first->next = temp;
    	temp->prev = first;
    	temp->next = last;
    	last->prev = temp;
        first = first->next;
		/*temp->next = last->next; 
        last->next = temp;
        last = temp;*/
    }
}
 




int main()
{
	circular_llist cl;
	
	int T;
	int N;
		unsigned long long int money,temp;
		short x,entering_gate;
		cin>>T;
	while(T--)
	{
		cin>>N;
		
		for(int j=0;j<N;j++)
		{
			cin>>temp;
			cl.create_node(temp);
		}
		cin>>entering_gate;
		cin>>money;
		cin>>x;
		
		node *temp = last;
		
		short int index;
		for(index=1;index<=entering_gate;index++)
		{
			temp= temp->next;
		}
		index = index-1;
		while(money > temp->info )
		{
			if(temp == last)
			{
				index = 1;
			}
			money -= temp->info;
			if(x == 1)
			{
			 temp = temp->next;
		    }
		    else
		    {
		    	temp = temp->prev;
			}
			index++;
		}
		
		/*-----------------------------------------------*/
		cout<<index+1<<endl;
		
		
		
		
		
	}
	return 0;
}


