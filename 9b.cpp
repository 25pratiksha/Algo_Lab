#include <bits/stdc++.h>
using namespace std;

int main() {
    int t=0;
    cin>>t;
    unsigned long long a= 1000000007,n,k,l,r,v,a1,arr[1000099],i,j;
    for(int i1=1;i1<=t;i1++)
    {
        char c;
        memset(arr,0,sizeof(arr));
        unsigned long long ans=0;
        
        cin>>n>>k;
        for(i=0;i<k;i++)
        {
                cin>>c;
                if(c=='i')
                {
                    cin>>l>>r>>v;
                    for(j=l;j<=r;j++)
                    {
                        arr[j]=(arr[j]%a + v%a)%a;
                    }
                    
                }
                if(c=='q')
                {
                    cin>>a1;
                    ans = (ans%a + arr[a1]%a)%a;
                }
            
            
        }
        cout<<"Case #"<<i1<<": "<<ans<<"\n";
        
    }

	return 0;
}
