#include <bits/stdc++.h>

using namespace std;
 

#define ll long long int
#define l long int
 
inline void quickreadll(long long int &x)
{
	x=0;
	register int c=0;
	for(;c<48||c>57;c=getchar_unlocked());
	for(;c>47&&c<58;c=getchar_unlocked())
		x=(x<<1)+(x<<3)+c-48;
}
 
inline void quickreadl(long int &x)
{
	x=0;
	register int c=0;
	for(;c<48||c>57;c=getchar_unlocked());
	for(;c>47&&c<58;c=getchar_unlocked())
		x=(x<<1)+(x<<3)+c-48;
}
 
inline void quickread(int &x)
{
	x=0;
	register int c=0;
	for(;c<48||c>57;c=getchar_unlocked());
	for(;c>47&&c<58;c=getchar_unlocked())
		x=(x<<1)+(x<<3)+c-48;
}
 
int main()
{
	long int n, q;
	quickreadl(n);
	quickreadl(q);
	int num;
	vector<bool> arr;
	while(n--){
		quickread(num);
		arr.push_back(num);
	}
	long int fir, idx, le, r;
	while(q--){
		quickreadl(fir);
		if(fir){
			quickreadl(idx);
			if(arr[idx-1])
				arr[idx-1]=false;
			else
				arr[idx-1]=true;
		}
		else{
			quickreadl(le);
			quickreadl(r);
			if(arr[r-1])
				cout<<"ODD"<<endl;
			else
				cout<<"EVEN"<<endl;
		}
	}
    return 0;
}

