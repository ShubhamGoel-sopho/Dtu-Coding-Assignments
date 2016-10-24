

    #include <iostream>
    using namespace std;
     
    int main()
    {
    	int t,a[100000],n,s;
    	scanf("%d",&t);
    	for(int i=0;i<t;i++)
    	{
    		int m=1;
    		scanf("%d",&n);
    		for(int j=0;j<n;j++)
    		scanf("%d",&a[j]);
    		
    		for(int k=0;k<n-1;k++)
    		{
    			if(a[0]>a[k+1])
    			{
    				a[0]=a[k+1];
    				m=m+1;
    			}
    		}
    		printf("%d",m);cout<<endl;
    	}
        return 0;
    }



