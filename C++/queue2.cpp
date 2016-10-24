#include <iostream>
#include <stack>
using namespace std;
void insert_at_bottom(std::stack<int>& pq,int data)
{
    if(pq.empty())
    {
        pq.push(data);
        return;
    }
    else
    {
        int temp = pq.top();
        pq.pop();
        insert_at_bottom(pq,data);
        pq.push(temp);
    }
    
    
}
void reverse_stack_recursively(std::stack<int>& pq)
{
    if(pq.empty())
    return;
    
    
        int temp = pq.top();
        pq.pop();
        reverse_stack_recursively(pq);
        insert_at_bottom(pq,temp);
    
    
    
}




int main()
{
    std::stack<int> p ;
    for(int i=1;i<51;i++)
    {
        p.push(i);
    }
    
    reverse_stack_recursively(p);
    
    for(int i=1;i<51;i++)
    {
        cout<<p.top()<<endl;
        p.pop();
    }
    return 0;
}