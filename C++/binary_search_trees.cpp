#include<iostream>
#include<stdio.h>
#include<string>
#include<stddef.h>
#include<process.h>
#include<queue>
////add more header files here//////
//implementing tree data structure///////////////
using namespace std;



struct bstnode
{
  string name;
  char gender;   // 'M' or 'F'
  int data;   //key
  bstnode *left;   //left pointer
  bstnode *right;   //right pointer

};
class binarysearchtree
{
  private:

      bstnode *root;  // root pointer or head pointer to to store the tree initially NULL

    bstnode *private_min();
    bstnode *retroot()    //done
    {
        return root;
    }

  public :

  binarysearchtree()   //done
     {
      root = NULL;
     }
 void insertintree(string name , char gen , int value) ;  //done
 bstnode *findthenode(bstnode *ro,int value) ;  //done
 bstnode  *deletefromtree(bstnode *ro,int value) ;//done;
 bstnode *givemax_to_me(bstnode *ro) ; //done
 bstnode *givemin_to_me(bstnode *ro) ; //done
 bstnode *creator_of_node()
     {
               bstnode *temp = new bstnode ;
               if(temp != NULL)
               {
                   temp->left = NULL;
                   temp->right = NULL;
                   return temp;
               }
               else
               {
                   cout << "new node can't be created sorry unavailable memory exiting...."<<endl;
                   return NULL;
               }
     }
  void print_inorder_traversal(bstnode *ro) const;   //done
  void print_preorder_traversal(bstnode *ro) const;  //done
  void print_postorder_traversal(bstnode *ro) const;  //done
  void print_levelorder_traversal(bstnode *ro) ;   //done
 void print_tree() ;  //done
 bstnode *give_inorder_successor(int value) const;
 ~binarysearchtree();

};

/////////////class functions definations starts here //////////////////
 void binarysearchtree::print_tree()
 {
     bstnode *temp = retroot();
     cout << "Enter which kind of traversal did you want : "<<endl;
     cout<<"Enter 1 for Inorder traversal "<<endl;
     cout<<"Enter 2 for preorder traversal "<<endl;
     cout<<"Enter 3 for postorder traversal "<<endl;
     cout<<"Enter 4 for Levelorder traversal "<<endl;
     int num;
     cin >> num;
     switch(num)
     {
         case 1 : cout<<"OK here is the Inorder Traversal"<<endl;
                       print_inorder_traversal(temp);
                       break;
        case 2 : cout<<"OK here is the Inorder Traversal"<<endl;
                       print_preorder_traversal(temp);
                       break;
        case 3 : cout<<"OK here is the Inorder Traversal"<<endl;
                       print_postorder_traversal(temp);
                       break;
       case 4 : cout<<"OK here is the Inorder Traversal"<<endl;
                       print_levelorder_traversal(temp);
                       break;
       default : cout<<"wrong choice entered Nothing to print"<<endl;
                       break;
     }}
     //////////////function for inorder traversal/////////////
 void binarysearchtree ::print_inorder_traversal(bstnode *ro) const
 {
     if (ro == NULL)
     {
         return;
     }
     else
     {
         print_inorder_traversal(ro->left);
         cout<<"------------------------------------------"<<endl;
         cout<<"DATA IS AS FOLLOWS : "<<endl;
         cout<<"NAME : "<<ro->name<<endl;
         cout<<"GENDER : "<<ro->gender<<endl;
         cout<<"KEY : "<<ro->data<<endl;
         cout<<"------------------------------------------"<<endl;
         print_inorder_traversal(ro->right);


     }
 }
 //////////pre order traversal///////////////
void binarysearchtree ::print_preorder_traversal(bstnode *ro) const
 {
     if (ro == NULL)
     {
         return ;
     }
     else
     {

         cout<<"------------------------------------------"<<endl;
         cout<<"DATA IS AS FOLLOWS : "<<endl;
         cout<<"NAME : "<<ro->name<<endl;
         cout<<"GENDER : "<<ro->gender<<endl;
         cout<<"KEY : "<<ro->data<<endl;
         cout<<"------------------------------------------"<<endl;
         print_preorder_traversal(ro->left);
         print_preorder_traversal(ro->right);


     }
 }
 //////////post order traversal///////////////
 void binarysearchtree ::print_postorder_traversal(bstnode *ro) const
 {
     if (ro == NULL)
     {
         return ;
     }
     else
     {


         print_postorder_traversal(ro->left);
         print_postorder_traversal(ro->right);
           cout<<"------------------------------------------"<<endl;
         cout<<"DATA IS AS FOLLOWS : "<<endl;
         cout<<"NAME : "<<ro->name<<endl;
         cout<<"GENDER : "<<ro->gender<<endl;
         cout<<"KEY : "<<ro->data<<endl;
         cout<<"------------------------------------------"<<endl;

     }
 }

//////////level order traversal///////////////


void binarysearchtree ::print_levelorder_traversal(bstnode *ro)
{
    if(ro == NULL)
    return ;

    else
    {
        queue<bstnode*> q;
        q.push(ro);
        while(q.empty() == false)
        {
           bstnode *temp= q.front();
        cout<<"------------------------------------------"<<endl;
         cout<<"DATA IS AS FOLLOWS : "<<endl;
         cout<<"NAME : "<<temp->name<<endl;
         cout<<"GENDER : "<<temp->gender<<endl;
         cout<<"KEY : "<<temp->data<<endl;
         cout<<"------------------------------------------"<<endl;
         if(temp->left !=NULL)
         {
             q.push(temp->left);

         }
        if(temp->right !=NULL)
         {
             q.push(temp->right);
         }
        q.pop();
        }}}

        ///////////////function to find the given value node return address of the parent node if not found the node /////
         bstnode *binarysearchtree::findthenode(bstnode *ro,int value)    //since not modify anything
         {
             if(ro == NULL)
             {
                 return NULL;
             }
             else if(ro->data == value)
             {
                 return ro;
             }
             else
             {
                 bstnode *temp = ro;
                if(temp->data > value)
           {       if(temp->left !=NULL)
            return (findthenode( temp->left,value)) ;
                else
               return temp;
            }

                else
            {
                if(temp->right !=NULL)
            return (findthenode(temp->right, value));
            else
            return temp;

            }}}



        void binarysearchtree ::insertintree(string name , char gen , int value)
        {
            bstnode *create = creator_of_node();
            create->name = name;
            create->gender=gen;
            create->data=value;
            if(root == NULL)
            {
                root = create;

            }
          else
          {


         bstnode *temp = findthenode(root,value);


         if(temp->data !=value)
         {

            if(temp->data > value)
            {
                temp->left = create;

            }
            else
             {if(temp->data < value)
               temp->right=create;
             }
         }
         else
         {
             cout<<"Duplicates are not allowed"<<endl;
        }
}}


bstnode *binarysearchtree::givemax_to_me(bstnode *ro)
{
    bstnode *temp= retroot();
    if(temp == NULL)
    return NULL;
else
     return  givemax_to_me(temp->right);
}

bstnode *binarysearchtree::givemin_to_me(bstnode *ro)
{
    bstnode *temp= retroot();
    if(temp == NULL)
    return NULL;
else
     return  givemin_to_me(temp->left);
}


bstnode  *binarysearchtree::deletefromtree(bstnode*ro,int value)
{
if(ro= NULL) return NULL;
else
{
    if(ro->data > value)
    {
        ro->left=deletefromtree(ro->left,value);
    }
    else if(ro->data < value)
    {
        ro->right=deletefromtree(ro->right,value);
    }

    else
    {
        if(ro->left ==NULL && ro->right==NULL)
        {
            delete ro;
            ro=NULL;
            return ro;
        }
        else if(ro->right == NULL)
        {
            bstnode *t = ro->left;
            delete ro;
            return t;
        }
        else if(ro->left == NULL)
        {
            bstnode *t = ro->right;
            delete ro;
            return t;

        }
        else
        {
            bstnode *to = givemin_to_me(ro->right);
            ro->data = to->data;
            ro->right = deletefromtree(ro->right,ro->data);
            return ro;
}}}}

binarysearchtree ::~binarysearchtree()
{
    bstnode *temp = NULL;
    queue<bstnode*> q;
        q.push(root);
        while(q.empty() == false)
        {
        temp= q.front();

       if(temp->left !=NULL)
         {
             q.push(temp->left);

         }
        if(temp->right !=NULL)
         {
             q.push(temp->right);
         }
         delete temp;
        q.pop();

}
}
int main()
{

    cout<<"hello man"<<endl;
    return 0;

}







