#include <bits/stdc++.h>
using namespace std;

bool cmp(long a,long b)
{
    if(a<b) {return 1;  } else {return 0;}
}


int main() {
	int t=0;
	cin>>t;
	bool val[50009];
	for(int i1=1;i1<=t;i1++)
	{
	    long l,n,d,l1,i,j,ctr=0;
	    cin>>l>>n>>d;
	    memset(val,0,sizeof(val));
	    long p[n+1];
	    for(i=0;i<n;i++)
	    {
	        cin>>p[i];
	        val[p[i]]=1;
	        
	    }
	    sort(p,p+n,cmp);
	    
	    bool flag1=1,flag2=1;
	    if(d==0||n==0)
	    {
	        cout<<"Case #"<<i1<<": "<<"impossible \n";
	        continue;
	    }
	    l1=0;
	    while(l1<l)
	    {
	       
	        if(l1==0 && ctr==0)
	        {
	            if(l1+d>=l && n>=1){ ctr=1; break;}
	            else if(val[l1+d]){l1=l1+d; ctr++; val[l1+d]=0;}
	            else
	            { 
	                flag1=0;
	                for(i=l1+d-1;i>=l1;i--)
	                {
	                    
	                    if(val[i]){ 
	                        ctr++;
	                        flag1=1;
    	                    l1=l1+i;
    	                    val[i]=0;
                            break;
	                    }
	                }
	                if(flag1==0){
	           
	                    break;
	                }
	            }
	            
	        }
	        else
	        {

	            if(l1+d>=l){ break;}
	            else if(val[l1+2*d]){
	                val[l1+2*d]=0;
	                l1=l1+2*d; 
	                ctr++; }
	            else
	            {   
	                flag1=0;
	                for(i=l1+2*d-1;i>l1;i--)
	                {
	                    if(val[i]){
	                        ctr++;
	                    l1=i;
	                    flag1=1;
	                    val[i]=0;
	                    break;

	                    }
	                }
	                if(flag1==0)
	                {
	                    
	                    break;
	                }
	                
	            }

	        }
	        
	         
	        if(( p[n-1]==l1 && l1+d<l))
	        {
	            
	            flag2=0;
	            break;
	        }
	       
	    }

	    if(flag1==0 || flag2==0)
	    {
	   
	        cout<<"Case #"<<i1<<": "<<"impossible \n";
	        continue;

	    }
	   
	        cout<<"Case #"<<i1<<": "<<ctr<<"\n";
	    

	}



	return 0;
}
