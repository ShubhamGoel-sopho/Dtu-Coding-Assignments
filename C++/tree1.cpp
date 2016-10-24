#include<iostream>
#include<stack>
#include<queue>
#include<climit>
#include<process>
#include<algorithm>
using namespace std;

struct tree
{
    int data;
    tree *left;
    tree *right;
}root;
//different traversals related to trees 

//inorder traversals 

//iterative version 
void inorder_traversal(tree *root)
{
    if(root == NULL)
    {
        return NULL;
    }
    else
    {
        std::stack<tree*> inorder;
        while(true)
        {
            while(root)
            {
                cout<<root->data<<endl;
                inorder.push(root);
                root = root->left;
            }
            if(inorder.empty())
            break;
            
            root = root->right;
        }
    }
}


//iterative version of the preorder traversal

void preorder_traversal(tree *root)
{
    if(root == NULL)
    {
        return NULL;
    }
    else
    {
        std::stack<tree*> inorder;
        //here the same procedure to solve the problems comes
        while(true)
        {
            while(root)
            {
                inorder.push(root);
                root = root->left;
            }
            if(inorder.empty())
            {
                break;
            }
            else
            {
                root = inorder.top();
                inorder.pop();
                cout<<root->data<<endl;
                root = root->right;
            }
        }
    }
    
}


//iterative level order traversal for a binary tree

void level_order_traversal(tree *root)
{
    if(root == NULL)
    {
        return NULL;
    }
    else
    {
        std::queue<tree*> levelorder;
        levelorder.push(root);
        tree *temp = NULL;
        while(!levelorder.empty())
        {
            temp = levelorder.front();
            levelorder.pop();
            std::cout << temp->data << std::endl;        
            if(temp->left)
            levelorder.push(temp->left);
            
            if(temp->right)
            levelorder.push(temp->right);
            
        }
        
    }
}


//to find the maximum in the binary tree problem 1 


int find_max(tree *root)
{
    int max = INT_MIN;
    if(root == NULL)
    {
        return max;
    }
    else
    {
        int left_max = find_max(root->left);
        int right_max = find_max(root->right);
        
        max = (root->data>max(left_max,right_max))?root->data:max(left_max,right_max);
        
        
    }
    return max;
}

//find_max without recursion in the binary tree problem 2

int find_max(tree *root)
{
    //perform the level order traversal in the tree then do this
    if(root == NULL)
    {
        return NULL;
    }
    else
    {  
        int max = INT_MIN;
        std::queue<tree*> levelorder;
        levelorder.push(root);
        tree *temp = NULL;
        while(!levelorder.empty())
        {
            temp = levelorder.front();
            levelorder.pop();
            if(temp->data > max)
            {
                max = temp->data;
            }
                    
            if(temp->left)
            levelorder.push(temp->left);
            
            if(temp->right)
            levelorder.push(temp->right);
            
        }
    }

    return max;
}


//searching an element in the binary tree with using the recursion  problem 3

int find_element(tree *root,int data)
{
	if(root == NULL)
	{
	    return 0; 
	} 
	else
	{
	    if(data == root->data)
	    {
	        return 1;
	    }
	    else
	    {
	        int left_search = find_element(root->left,data);
	        
	        if(left_search != 0)
	        {
	            return temp;
	        }
	        else
	        {
	            return find_element(root->right,data);
	        }
	    }
    }
    return 0;
}

//searching an element in the binary tree without using the recursion  problem 4
void find_element_iteratively(tree *root,int data)
{
    if(root == NULL)
    {
        return NULL;
    }
    else
    {
        if(root->data == data)
        {
            return 1;
        }
        else
        {
            std::queue<tree*> levelorder;
            levelorder.push(root);
            tree *temp = NULL;
            while(!levelorder.empty())
            {
                
                temp = levelorder.front();
                levelorder.pop();
                if(temp->data == data)
                {
                    return 1;
                    break;
                }
                if(temp->left)
                levelorder.push(temp->left);
                
                if(temp->right)
                levelorder.push(temp->right);
                
            }
        }    
    }
    return 0;
}
//inserting an element in the binary tree problem 5

void insert_element_tree(tree *root,int data)
{
    tree *newnode = new tree;
    if(newnode)
    {
        newnode->data = data;
        newnode->left = newnode->right = NULL;
        if(root == NULL)
        {
            root = newnode;
        }
        else
        {
            std::queue<tree*> levelorder;
            levelorder.push(root);
            tree *temp = NULL;
            while(!levelorder.empty())
            {
                temp = levelorder.front();
                levelorder.pop();
               
                if(temp->left)
                levelorder.push(temp->left);
                else
                {
                     temp->left = newnode;
                     return;
                }
                
                if(temp->right)
                levelorder.push(temp->right);
                else
                {
                     temp->right = newnode;
                     return;
                }
            }
        }
    }
    else
    {
        cout<<"Memory error !!!"<<endl;
        exit(-1);
    }
}



//algo to find the size of the tree problem 6

unsigned int size_btree(tree *root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        return (size_btree(root->left)+size_btree(root->right)+1);
    }
}

//algo to find the size of the tree problem 7 iterative version
unsigned int size_btree(tree *root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        int size = 1;
        std::queue<tree*> levelorder;
        levelorder.push(root);
        tree *temp = NULL;
        while(!levelorder.empty())
        {
            temp = levelorder.front();
            levelorder.pop();
                   
            
            if(temp->left)
            {
                levelorder.push(temp->left);
                size++;
            }
            if(temp->right)
            {
                levelorder.push(temp->right);
                size++;
            }
        }
        
    }
    return size;
}



//printing the level order in the reverse order in the reverse order
void level_order_traversal(tree *root)
{
    if(root == NULL)
    {
        return NULL;
    }
    else
    {
        std::stack<tree *> S ;
        std::queue<tree*> levelorder;
        levelorder.push(root);
        tree *temp = NULL;
        while(!levelorder.empty())
        {
            temp = levelorder.front();
            levelorder.pop();
            S.push(temp);        
            if(temp->left)
            levelorder.push(temp->left);
            
            if(temp->right)
            levelorder.push(temp->right);
            
        }
        while(!S.empty())
        {
            std::cout << S.top()->data << std::endl;
            S.pop();
            
        }
    }
}



//algorithm to delete a tree using the post order traversal problem 9
void delete_tree(tree *root)
{
    if(root == NULL)
    return;
    else
    {
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
    }
}



//finding the height of the binary tree with using recursion problem 10

int Height_btree(tree *root)
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

//finding the height of the binary tree without recursion problem 11

int tree_height_iteratively(tree *root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        int level = 0;
        std::queue<tree*> levelorder;
        levelorder.push(root);
        levelorder.push(NULL);
        tree *temp = NULL;
        while(!levelorder.empty())
        {
            temp = levelorder.front();
            levelorder.pop();
            if(temp == NULL)
            {
                if(!levelorder.temp())
                {
                    levelorder.push(NULL);
                    level++;
                }
            }
            std::cout << temp->data << std::endl;        
            if(temp->left)
            levelorder.push(temp->left);
            
            if(temp->right)
            levelorder.push(temp->right);
            
        }
        
    }
    return level;
}


// algo to find the deepest node in the tree

tree *node find_deepest_node(tree* node)
{
    if(root == NULL)
    {
        return NULL;
    }
    else if(root->left == NULL && root->right == NULL)
    {
        return root;
    }
    else
    {
        std::queue<tree*> levelorder;
        levelorder.push(root);
        tree *temp = NULL;
        while(!levelorder.empty())
        {
            temp = levelorder.front();
            levelorder.pop();
            
            if(temp->left)
            levelorder.push(temp->left);
            
            if(temp->right)
            levelorder.push(temp->right);
            
        }
        
    }
    return temp;
}

//algo for deleting an elelment from the binary tree 

void delete_node(tree *root,int data)
{
    if(root == NULL)
    {
        cout<<"the given data do not exists in the tree ~~~!!!"<<endl;
        return;
    }
    else
    {
        node *temp = find_element_iteratively(root,data);
        if(temp != NULL)
        {
            node *deepestnode = find_deepest_node(root);
            temp->data = deepestnode->data;
             
            delete deepestnode; 
        }
    }
    
}


//algo to find the no of leaves in the tree

int noofleafnodes(tree *root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        int leaves=0;
        std::queue<tree*> levelorder;
        levelorder.push(root);
        tree *temp = NULL;
        while(!levelorder.empty())
        {
            
            temp = levelorder.front();
            levelorder.pop();
            if(temp->left == NULL && temp->right == NULL)
            leaves++;
            
            else
            {
                    if(temp->left)
                levelorder.push(temp->left);
                
                if(temp->right)
                levelorder.push(temp->right);
            }
        }
        
    }
}

//algo to find out the level that has maximun sum in the btree

//algo to create the mirror of the binary tree using the recursion 
void create_mirror(tree *root)
{
    if(root == NULL)
    {
        return NULL;
    }
    else
    {
        create_mirror(root->left);
        create_mirror(root->right);
        tree *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}



// function to check the whether two given tree are mirror of each other or not

int are_mirror(tree *root1,tree *root2)
{
    if(root1 == NULL && root2 == NULL)
    {
        return 1;
    }
    if(root1 == NULL || root2 == NULL)
    {
        return 0;
    }
    if(root1->data != root2->data)
    {
        return 0;
    }
    else
    {
        return (are_mirror(root1->left,root2->right) && are_mirror(root2->left,root1->left));
    }
}


//function to print all root to leaf nodes

void printarray(int *arr,int size)
{
    for(int i = 0;i<size;i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

void print_root_to_leaf(tree *root,int *arr,int size)
{
    static int len = 0;
    if(root == NULL)
    {
        return NULL;
    }
    else
    {
         arr[len++] = root->data;
        if(root->left == NULL && root->right == NULL)
        {
            printarray(arr,len);
            
        }
        else
        {
           
            print_root_to_leaf(root->left,arr,size);
            print_root_to_leaf(root->right,arr,size);
            
        }
    }
}

//printing all the ancestors of the given node in the binary tree
int print_ancestors(tree *root,tree *node)
{
    if(root == NULL)return 0;
    
    else
    {
        if(root->left == node || root>right == node || print_ancestors(root->left,node)
        || print_ancestors(root->right,node))
        {
            std::cout << root->data << std::endl;
            return 1;
                        
        }
    }

    return 0;
}