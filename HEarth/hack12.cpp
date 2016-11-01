#include <iostream>     // std::cout
#include <algorithm>    // std::stable_sort
#include <vector>       // std::vector
using namespace std;
unsigned long long int K;
bool compare_as_ints (unsigned long long int i,unsigned long long int j)
{
  return ((i % K < j % K));
}

int main () {
  int N;
  
  
  cin>>N>>K;
  unsigned long long int Array[N];
  for(int i=0;i<N;i++)
  {
  	cin>>Array[i];
  }

  

  std::vector<unsigned long long int> myvector (Array, Array + sizeof(Array) / sizeof(unsigned long long int) );

  
  std::stable_sort (myvector.begin(), myvector.end(),compare_as_ints);
  for (std::vector<unsigned long long int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  

  return 0;
}
