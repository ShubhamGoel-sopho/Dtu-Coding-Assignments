<<<<<<< HEAD
#include <list>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
int main()
{
    int a[] = {2,4,6,8,10,3,6,9};

    std::list<int> la(a, a+8);
    la.sort();
    la.unique();
    for(list<int>::iterator it = la.begin();it != la.end();it++)
    {
    	std::cout<<*it<<endl;
	}
    std::cout << la.size() << std::endl;

    return 0;
}
=======
#include <list>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
int main()
{
    int a[] = {2,4,6,8,10,3,6,9};

    std::list<int> la(a, a+8);
    la.sort();
    la.unique();
    for(list<int>::iterator it = la.begin();it != la.end();it++)
    {
    	std::cout<<*it<<endl;
	}
    std::cout << la.size() << std::endl;

    return 0;
}
>>>>>>> a3a9cc0590ad200d8e072f7eff31541cbda2e3a6
