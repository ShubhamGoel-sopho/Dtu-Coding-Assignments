//arranging queues in the alternating fashion
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void rearrange_queue(std::queue<int>& fq)
{
    std::stack<int> fs;
    for(int i=0;i<5;i++)
    {
        fs.push(fq.front());
        fq.pop();
    }
    std::queue<int> fq1;
    while(!fs.empty())
    {
        fq1.push(fs.top());
        fs.pop();
    }
    while(!fq1.empty())
    {
        fs.push(fq1.front());
        fq1.pop();
        
    }
    
    while(!fs.empty())
    {
        fq.push(fs.top());
        fs.pop();
        fq.push(fq.front());
        fq.pop();
    }
    
    
}
int main()
{
    std::queue<int> fq ;
    for(int i=1;i<=10;i++)
    {
        fq.push(i);
    }
    rearrange_queue(fq);
    
    while(!fq.empty())
    {
        std::cout << fq.front() << std::endl;
        fq.pop();
    }
    return 0;
}