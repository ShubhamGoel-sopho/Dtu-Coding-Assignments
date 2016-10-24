#include<iostream>
using namespace std;

struct avltree
{
	avltree *left;
	avltree *right;
	int info;
	int height;
};
int Height_btree(avltree *root)
{
    if(root == NULL)
    {
        return -1;
    }
    else
    {
        return max(Height_btree(root->left),Height_btree(root->right)+1);
    }
}

int Height(avltree *root)
{
	if(root != NULL)
	{
		return root->height
	}
	else
	{
		return -1;
	}
	
}


//rotations in the tree LL,RR,LR,RL

avltree *LLrotate(avltree *root)
{
	avltree *temp = root->left;
	root->left = temp->right;
	temp->right = root;
	root->height = max(Height(root->left),Height(root->right))+1;
	temp->height = max(Height(temp->left),root->height)+1;
	return temp;
}

//RR rotation
avltree *RRrotate(avltree *root)
{
	avltree *temp = root->right;
	root->right = temp->left;
	temp->left = root;
	root->height = max(Height(root->right),Height(root->left))+1;
	temp->height = max(Height(temp->right),root->height)+1;
	return temp;
}

//LR rotations


avltree* LRrotate(avltree *root)
{
	root->left = RRrotate(root->left);
	return LLrotate(root);
}



//RL rotations


avltree* RLrotate(avltree *root)
{
	root->right = LLrotate(root->right);
	return RRrotate(root);
}


//insertion in to an avl tree

avl 



