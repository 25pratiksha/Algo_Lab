#include <bits/stdc++.h>
using namespace std;

bool cmp(unsigned long long a,unsigned long long b)
{
    if(a>b) {return 1;  } else {return 0;}
}

bool cmp1(unsigned long long a,unsigned long long b)
{
    if(a<b) {return 1;  } else {return 0;}
}

int main() {
	int t=0;
	cin>>t;
	unsigned long long n,m,i,l[200099],j;
	for(int i1=1;i1<=t;i1++)
	{
	    memset(l,0,sizeof(l));
	    cin>>n>>m;
	    for(i=0;i<n;i++)
	    {
	        cin>>l[i];
	    }
	    sort(l,l+n,cmp);
	    if(m>=n)
	    {
	        cout<<"Case #"<<i1<<": "<<l[0]<<"\n";
	        continue;
	    }
	    unsigned long long arr[m]={0};
	    j=0;
	    while(j<n)
	    {
    	    for(i=0;i<m;i++)
    	    {
    	     arr[i]=arr[i]+l[j];
    	     j++;
    	     if(j==n)
    	     break;
    	    }
    	    sort(arr,arr+m,cmp1);
    	    
	    }
	    
	    cout<<"Case #"<<i1<<": "<<arr[m-1]<<"\n";
	 
	    
	    

	}



	return 0;
}
