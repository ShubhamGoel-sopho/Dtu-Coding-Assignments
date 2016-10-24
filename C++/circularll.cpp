#include<iostream>
using namespace std;


//implementing the circular link list
struct node{
	int data;
	node *next;

};
 
node *root = NULL;
node *lastptr = NULL;
node* createnode()
{
	node *temp = new node;
	temp->next = temp;
	return temp;
}
void insert(int data)
{
	//root is global
	if(root == NULL)
	{
		//if list is empty
		node *temp = createnode();
		temp->data = data;
		root = temp;
		lastptr = temp;
	}
	else
	{
		//list is not empty
		node *temp = createnode();
		temp->data = data;
		lastptr->next = temp;
		
		temp->next = root;
		lastptr = lastptr->next;
	
	}
	
}
void delete_cir()
{
	//deletion from the start
	if(root != NULL){
	
		node *temp = root;
		if(root->next != root){
		
			root = root->next;
			lastptr->next = root;
		}
		else
		{
			root = NULL;
		}
		delete temp;
    }
	
}
void printlist()
{
	node *temp = root->next;
	if(root != NULL)
	{
		while(temp != root)
		{
			cout<<temp->data<<endl;
			temp = temp->next;
			
		}
	}
}

int main()
{
	int choice;
	int choice1;
	int data;
	do{
	
		cout<<"welcome to info manipulation programme"<<endl;
		cout<<"enter the following choices :)"<<endl;
		cout<<"enter 1 to insert the values "<<endl;
		cout<<"enter 2 delete the node "<<endl;
		cout<<"enter 3 to print the information "<<endl;
		cin>>choice;
	    
	    switch(choice)
	    {
	    	case 1: cout<<"enter the data to insert "<<endl;
				 	cin>>data;
					insert(data);
					cout<<"inserted"<<endl;
					break;
			case 2: delete_cir();
			        cout<<"deleted :("<<endl;
		            break;
			case 3: cout<<"the values in the list are :"<<endl;
			        printlist();
					break;
			default:cout<<"wrong choice enter value betwwen 1-3"<<endl;
			        break;								  
		}
		
		cout<<"want to proceed more: 0 to stop and anykey to stop"<<endl;
		cin>>choice1;
		if(choice1 == 0)
		{
			break;
		}
}while(true);
	
	
	return 0;
}





