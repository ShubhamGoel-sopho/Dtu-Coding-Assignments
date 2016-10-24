#include<iostream>
#include<queue>
using namespace std;
long int expo(int i)
{if(i==0)
{
    return 1;

}
long int y=1;
else {
    for(int k =1;k<=i;k++)
    {
        y *=10;
    }
    return y;
}}
int main()
{
    queue<int> s[10];
    cout<<"enter the elements in the array"<<endl;
    int a[10];
    for(int i=0;i<10;i++)
    {
        cin>>a[i];
        cout<<endl;
    }
    cout<<"algorithm works on the basis of radix sort"<<endl;
    cout<< "enter how manydigits are there"<<endl;
    int x;
    cin >> x;
    int l,b,c;
    for(int i=1;i<=x;i++)
    {long int u=expo(i);
        for(int j=0;j<10;j++)
        {
            int l=(a[j]/u)%10;
            s[l].push(a[j]);
        }
        int z=0
  for(int j=0;j<10;j++)
        {
        while(!s[j].empty())
        {
            a[z]=s[j].front;
            s[j].pop();
            z++;
        }
        }

    }

cout<<"your array is: "<<endl;
  for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" "<<endl;

    }
















    return 0 ;

}
