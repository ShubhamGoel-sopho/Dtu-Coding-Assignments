#include<iostream>
#include<string>
using namespace std;

//merging two link list

node *Merge_two_list(node *root,node *root2)
{
	node *head = NULL;
	node *temp1,*temp2;
	temp1 = root1;
	temp2 = root2;
	node *temp = NULL;

	while(temp1 != NULL && temp2 != NULL)
	{
		if(temp1->data > temp2->data)
		{
			if(head == NULL)
			{
				head = temp2;
				temp = head;
			}
			else
			{
				temp->next = temp2;
				temp = temp->next;
			}
			temp2 = temp2->next;
		}
		else
		{
            if(head == NULL)
			{
				head = temp1;
				temp = head;
			}
			else
			{
				temp->next = temp1;
				temp = temp->next;
			}
			temp1 = temp->next;
		}
	}
	if(temp1 != NULL)
	{
		temp->next = temp1;
		
	}
	else if(temp2 != NULL)
	{
		temp->next = temp2;
	}
	
	return head;
	
}



