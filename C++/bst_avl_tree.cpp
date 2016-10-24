#include <iostream>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * here i have practised some functions related to binary search tree
 * and expression trees and about avl trees we will learn from this 
 * discussion and practise so lets get started
 * */
 
 
 struct binarytree
 {
     int data;
     binarytree *left;
     binarytree *right;
 }
 /**
  * question 1. function to check whether the tree are mirror to each other 
  * or not...
  * */
  bool ismirror(binarytree *root1, binarytree *root2)
  {
      if(root1 == NULL && root2 == NULL)
      {
          return true;
      }
      else if(root1 == NULL && root2 != NULL || root1 != NULL && root2 == NULL)
      {
          return false;
      }
      else if(root1->data != root2->data)
      {
          return false;
      }
      else
      return (ismirror(root1->left,root2->right) && ismirror(root1->right,root2->left));
    
  }
  
  
  /**
   * question 2 construction of binary tree from the inorder and
   * preorder traversals given as an array
   **/
   
   binarytree *buildtree(int inorder[],int preorder[],int inorderstart,int inorderend)
   {
        static int preorderindex = 0;
        int middle = inorderstart+inorderend/2;
        int value =  preorder[preorderindex];
        binarytree *temp = new binarytree;
        
        if(temp)
        {
            temp->data = value;
            preorderindex++;
            if(inorderstart == inorderend)
            return temp;
            
            int inorderindex =  search(inorder,value,inorderstart,inorderend);
            
            temp->left = buildtree(inorder,preorder,inorderstart,inorderindex-1);
            temp->right = buildtree(inorder,preorder,inorderindex+1,inorderend);
            return temp;
        }
        else
        return NULL;
    }
    
    
    
    /**
     * question 3 in this example we are going to get the zig zag traversal of 
     * the binary tree
     * */
     
    void zigzag_traversal(binarytree *root)
    {
        stack<*binarytree> store1;
        stack<*binarytree> store2;
        if(root == NULL)
        return NULL;
        else
        {
            int count = 1;
            binarytree *temp = NULL;
            store1.push(root);
            
            while(!store1.empty())
            {
                temp = store1.top();
                cout<<temp->data<<endl;
                store1.pop();
                if(temp)
                {
                    if(count)
                    {
                        if(temp->left)
                        store2.push(temp->left);
                    
                        if(temp->right)
                        store2.push(temp->right);
                        
                    }
                    else
                    {
                        if(temp->right)
                        store2.push(temp->right);
                        if(temp->left)
                        store2.push(temp->left);
                    }
                }
                if(store1.empty())
                {
                    count = 1 - count;
                    swap(store1,store2);
                }
            }
        }
    }
     
     
     
/**
 * question 4 to check whether the given tree isomorphic or not
 * */
 
 bool is_isomorphic(binarytree *root1,binarytree *root2)
 {
     //here the values do not matters but the structure have to be same (must)
     
     if(root1 == NULL && root2 == NULL)
     {
         return true;
     }
     else if(!root1 && root2 || !root2 && root1 )
     {
         return false;
         
     }
     else
     {
         return (is_isomorphic(root1->left,root2->left) && is_isomorphic(root1->right,root2->right));
     }
 }
 
 /**
  * question 5 to check wheher the trees are quasi isopmorphic or not
  * */
  
bool is_quasiisomorphic(binarytree *root1,binarytree *root2)
 {
     //here the values do not matters but the structure have to be same (must)
     
     if(root1 == NULL && root2 == NULL)
     {
         return true;
     }
     else if(!root1 && root2 || !root2 && root1 )
     {
         return false;
         
     }
     else
     {
         return (is_quasiisomorphic(root1->left,root2->left) && is_quasiisomorphic(root1->right,root2->right)
                || is_quasiisomorphic(root1->left,root2->right) && is_quasiisomorphic(root1->right,root2->left));
                
         
     }
 }
  
 /**
  * code to build the expression tree from the postfix expression of the 
  * given expression using the simple approach of stacks lets get started
  * */
  
  
  binarytree *buildtreefrompostfix(char *expression[],int size)
  {
      std::stack<binarytree*> expr;
      
      for(int i=0;i<size;i++)
      {
          if(isoperand(expression[i]))
          {
              binarytree *temp = new binarytree;
              temp->data = expression[i];
              temp->left = temp->right = NULL;
              expr.push(temp);
          }
          else if(isoperator(expression[i]))
          {
              binarytree *temp1,*temp2;
              
              temp1 = temp2 = NULL;
              
              temp1 = expr.top();
              expr.pop();
              temp1 = expr.top();
              expr.pop();
              binarytree *temp3 = new binarytree;
              temp3->data = expression[i];
              temp3->left =temp2; 
              temp3->right = temp1;
              expr.push(temp3);
              
          }
      }
      return expr.top();
  }
   
   
/**
 * question 6 to find the inorder successor of the binary search tree 
 * assuming the tree is height balanced we are going to get the worst 
 * case time complexity in this case is only log(n)
 * */
 
binarytree *inorder_successor(binarytree *root,binarytree *node)
{
    if(root == NULL)
    {
        return NULL;
    }
    else
    {
        if(node->right != NULL)
        {
            binarytree *temp = findmin(node->right);
            return temp;
        }
        else
        {
            binarytree *temp = root;
            binarytree *succ = root;
            while(temp != node)
            {
                if(temp->left > node->value)
                {
                    succ = temp->left;
                    temp = temp->left;
                }
                else if(temp->right < node->value )
                temp = temp->right;
            }
            return succ;
        }
    }
}
 
 
/**
  * question 7 here we find the inorder predcessor of binary search 
  * tree logic is same as above
  * */
  
binarytree *inorder_predecessor(binarytree *root,binarytree *node)
{
    if(root == NULL)
    {
        return NULL;
    }
    else
    {
        if(node->left != NULL)
        {
            binarytree *temp = findmax(node->left);
            return temp;
        }
        else
        {
            binarytree *temp = root;
            binarytree *pred = root;
            int count = 0;
            while(temp != node)
            {
                if(temp->left > node->value)
                {
                    count++;
                    pred = temp->left;
                    if(count==1)
                    return pred;
                    temp = temp->left;
                }
                else
                temp = temp->right;
            }
            return succ;
        }
    }
}
