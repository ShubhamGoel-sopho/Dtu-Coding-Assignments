
//first function is that to reverse the link list in pairs done
//second function is that to sum of two link list to form another list
//cloning the link list with random pointer pointing in it.. 
//reverse k blocks of the link list with given value of k done

//implementing the first function reverse in pairs

node *reverse_in_pairs()
{
	//iterative approach
	node *temp1;
	temp1 = NULL;
	
	temp1 = head;
	
	if(head == NULL)
	{
		return NULL;
	}
	else if(head->next == NULL)
	{
		return head;
	}
	else
	{
		int count = 0;
	 	//reverse the link list in the pairs from here
	 	//count the size of the link list if even do some thing or odd do something
	 	while(temp != NULL)
	 	{
	 		count++;
	 		temp = temp->next;
	    }
        temp = head;
        if(count%2 == 0)
        {
        	//even count
        		node *p,*q,*r;
			p = q = r =NULL;
			p = head;
			q = head->next;
			r = head->next->next;
			count /= 2;
			
			for(int i=1;i<=count;i++)
			{
				if(i == 1)
				{
					//first reverse
					q->next = p;
					p->next = r;
					head = q;
					p = head;
					q = temp;
					temp = head;
					
					//pointer fixed;
					
					temp = temp->next;
					p = r;
					q = p->next;
					r = q->next;
				}
				else if(i == count)
				{
					//last pair to reverse
					if(r == NULL)
					{
						q->next= p;
						p->next = NULL;
						temp->next = q;
					}
				}
				else
				{
				    q->next = p;
					p->next = r;
					temp->next = q;
					q = p;
					p = temp->next;
					temp = temp->next;
					
					
					p = r;
					q = p->next;
					r = q->next;
				}
			}
     	}
		else
		{
			//odd count
			node *p,*q,*r;
			p = q = r =NULL;
			p = head;
			q = head->next;
			r = head->next->next;
			count /= 2;
			
			for(int i=1;i<=count;i++)
			{
				if(i == 1)
				{
					//first reverse
					q->next = p;
					p->next = r;
					head = q;
					p = head;
					q = temp;
					temp = head;
					
					//pointer fixed;
					
					temp = temp->next;
					p = r;
					q = p->next;
					r = q->next;
					
				}
				else
				{
				    q->next = p;
					p->next = r;
					temp->next = q;
					q = p;
					p = temp->next;
					temp = temp->next;
					
					
					p = r;
					q = p->next;
					r = q->next;
						
				}
			}  
		}
	    return NULL;		
	}
}


//reverse the link list in k blocks from the starting of the list

node *reverse_K_blocks(unsigned int k)
{
    if(head == NULL)
	{
		return NULL;
	}
	else if(head->next == NULL)
	{
		return head;
	}
	else
	{
		if(k >=2)
		{
			
			node *start,*next,*prev;
			prev = NULL;
			start = head;
			next = head->next;
			for(int i=1;i<=k;i++)
			{
				start->next = prev;
				prev = start;
				start = next;
				next = next->next;
			}
		}
	}
}

//cloning the link list
struct node
{
	int data;
	node *next;
	node *rand;
}
struct helper
{
	int d;
	node *address;
}
node *head = NULL;

node *clone_the_list()
{
	node *newhead = NULL;
	
	node *temp = head;
	node *temp1 = NULL;
	int count = 0;
	while(temp != NULL)
	{
		if(newhead == NULL)
		{
			count++;
		 *temp1 = createnode(); //helper fnction to allocate new memory
			temp1->data = temp->data; 
			newhead = temp1;
			temp1->rand =  NULL;
			temp = temp->next
			
			
			
		}
		else
		{
			count++;
			temp1->next = createnode();
			temp1 = temp1->next;
			temp1->data = temp->data;
			temp1->rand =  NULL;
			temp = temp->next; 
			
		}
	}
	
	//till now we created the utility for cloning the simple list
	helper *help = new helper[count];
	temp = head;
    temp1 = newhead;
	for(int i = 0;i<count;i++)
	{
	 	map<int,node*> p;
	    do some mapping here which nothing but simple hashing 
		
	}
	
	
}
