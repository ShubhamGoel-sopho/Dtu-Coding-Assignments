#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	short K;
	string s;
	cin>>s>>K;
	int len = s.length();
	vector<string> foo;
	string temp;
	for(int i=0;i<len;i++)
	{
		temp.assign(s.begin()+i,s.end());
		foo.push_back(temp);
	}
	
	sort(foo.begin(),foo.end());
	
	cout<<foo[K-1]<<endl;
	
	
}