#include<iostream>
using namespace std;

void printspaces(int n)
{
	for(int i=0;i<n;i++)
	{
		printf(" ");
	}
}
int main()
{
	char X = 'A';
	int p=1;
	int q=0;
	char t;
	for(int i=5;i>=1;i--)
	{
		X = 'A';
		printspaces(i-1);
		for(int j=0;j<p;j++)
		{
			cout<<X;
			X++;
		}
		p++;
		t = X-2;
		for(int j=0;j<q;j++)
		{
			cout<<t;
			t--;
		}
		q++;
		printspaces(i-1);
		cout<<endl;
		
	}
}
