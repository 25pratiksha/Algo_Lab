#include <bits/stdc++.h>
using namespace std;



int main() {
	int t;
	cin>>t;
	

	unsigned long long k,j,val,i;
	int s,f;
    unsigned long long u[1000],v[1000],r[1000];
    unsigned long long low=ULLONG_MAX,high=0,lo,hi;
 
	
	for(int i1=1;i1<=t;i1++)
	{
	  
	   memset(u,0,sizeof(u));
	   memset(v,0,sizeof(v));
	   memset(r,0,sizeof(r));
	   
	    lo=ULLONG_MAX;
	    hi=0;
	    cin>>s>>f;
	    for(k=0;k<s;k++)
	    {
	        cin>>u[k]>>v[k];
	        if(low>u[k]) low=u[k];
	        if(high<v[k]) high=v[k];
	        
	        
	    }
	    
	    
	    for(k=0;k<f;k++)
	    cin>>r[k];
	       
	    cout<<"Case #"<<i1<<": \n";
	    for(k=0;k<f;k++)
	    {
	       
	        lo=low;
	        hi=high;
	     // cout<<"lo"<<lo<<"\n";
             //  cout<<"hi"<<hi<<"\n";
	        unsigned long long y=r[k];
	        
	        unsigned long long mid,count=0;
     
            while(count!=y && lo<=hi)
            {
                mid=(hi+lo)/2;
           //   cout<<"mid"<<mid<<"\n";
             //   cout<<"lo"<<lo<<"\n";
             // cout<<"hi"<<hi<<"\n";
                if(hi==lo)
                {
                    cout<<mid<<"\n";
                    break;
                    
                }
                
                    
                
                for(i=0;i<s;i++)
                {
                    if(mid >=u[i] && mid<= v[i])
                    {
                        count=count+ mid - u[i]+1;
                    }
                    if(mid >=u[i] && mid>v[i])
                    {
                        count=count+v[i]-u[i]+1;
                    }
                     
                    //cout<<"count"<<count<<"\n";
                }
              //  cout<<"count"<<count<<"\n";
                if(count ==y)
                {
                    cout<<mid<<"\n";
                    break;
                }
                if(lo+1==hi)
                {
                    if(count<y)
                    {
                     cout<<hi<<"\n";break;   
                    }
                    else
                    {
                     cout<<lo<<"\n";break;    
                    }
                }
                
                
                if(count<y)
                {
                    lo=mid;
                }
                else
                {
                    hi=mid;
                }
                count=0;
               
            }
             
	        
	       
	    }
	    
	}
	
	
	
	
	return 0;
}
