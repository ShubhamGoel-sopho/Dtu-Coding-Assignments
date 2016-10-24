#include<iostream>

using namespace std;

node *reverseLL(node *root)
{
	struct node *start,*prev,*mid;
	mid = root;
	start = root;
	mid = root->next;
	while(mid != NULL)
	{
		start = mid;
		mid = mid->next;
		start->next = prev;
		prev = start;
	}
	root->next = NULL;
	root = mid;
	
}


node *findnthnodefromlast(node *root,int n)
{
	node *one,*two;
	one = root;
	two = root;
    int i=1;
	while(i !=n)
	{
		one = one->next;
		i++;
	}	
	//after that
	while(one !=NULL)
	{
		two = two->next;
	}
	
	return two;
	
}

node *mergepointoftwolinklist(node *root1,node *root2)
{
	if(root1 != NULL && root2 !=NULL)
	{
		int n,m;
		n = 0;
		m = 0;
		//calculate the size of the list
		while(root1 != NULL)
		{
			n++;
		}
		while(root2 != NULL)
		{
   		    m++;
		}
		
		unsigned int diff = abs(m-n);
		if(m > n)
		{
			//root2 is greater increment root2 by the diff
			for(int i=0;i<diff;i++)
			{
				root2 = root2->next;
			}
			
		}
		else if(n>m)
		{
			//root1 is greater increment root1 by the diff
			for(int i=0;i<diff;i++)
			{
				root1 = root1->next;
			}
			
		}
	    while(root1 != root2)
	    {
	    	root1 = root1->next;
    	    root2 = root2->next;
 	    }
 	    if(root1 == root2)
 	    {
 	    	return root2;
	    }
	    else
	    {
	    	return NULL;
		}
		
	}
	
	
}





