#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
    if (a == 0) 
       return b;
     
    return gcd(b%a, a);
}

int main()
{
	int t;
	cin>>t;

	for(int i1=1;i1<=t;i1++)
	{
		long long res=0;
		
		int n;
		cin>>n;
		long long a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		res=gcd(a[0],a[1]);
		//cout<<res;
		for(int i=2;i<n;i++)
		{
		    //cout<<res<<" ";
			res=gcd(a[i],res);
			
		}
        cout<<"Case #"<<i1<<": "<<res<<"\n";
	}

	return 0;
}