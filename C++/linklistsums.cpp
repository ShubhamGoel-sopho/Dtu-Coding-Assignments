
node *sum_two_list(node* root1,node* root2)
{
	if(root1 == NULL && root2 == NULL)
	{
		return NULL;
	}
	else if(root2 == NULL)
	{
		return root1;
	}
	else if(root1 == NULL)
	{
		return root2;
	}
	else
	{
		//start summing the link lists 
		unsigned int count1,count2;
		count1=count2 = 0;
		node *temp = root1;
		while(temp != NULL)
		{
		    count1++;
			temp = temp->next;
		}
		temp = root2;
		while(temp != NULL)
		{
		    count2++;
			temp = temp->next;
		}
		
		node *last1 = root1;
			node *last2 = root2;
			while(last1->next != NULL)
			{
				last1 = last1->next;
			}
			while(last2->next != NULL)
			{
				last2 = last2->next;
			}
         node* sumhead = NULL;
		int x = 0;
		int num;
		if(count1 == count2)
		{
			
			//assuming it to doubly link list
			for(int i=0;i<count1;i++)
			{
				sumhead = create_node_at_start(sumhead);
				num = x + last1->value1 + last2->value2;
				if(num > 9)
				{
					
					sumhead->value = num%10;
					num /=10;
					x = num;
				}
				else
				{
					sumhead->value = num;
					x = 0;
				}
				last1 = last1->prev;
				last2 = last2->prev;
			}
			
			
		}
		else if(count1 > count2)
		{
			for(int i=0;i<count2;i++)
			{
				sumhead = create_node_at_start(sumhead);
				num = x + last1->value1 + last2->value2;
				if(num > 9)
				{
					
					sumhead->value = num%10;
					num /=10;
					x = num;
				}
				else
				{
					sumhead->value = num;
					x = 0;
				}
				last1 = last1->prev;
				last2 = last2->prev;
			}
			last2 = NULL;
			int count = count1 - count2;
			for(int i=0;i<count;i++)
			{
				sumhead = createnode(sumhead);
				sumhead->value = same as previosly done
			}
		}
		
		else
		{
			same as prevois case just copy and paste
		}
	}
}
