#include <bits/stdc++.h>
using namespace std;

int a[30],arr[30][30],n,m;
bool bits[30],flag=1,f=0;


void combinationUtil(int arr1[],int start, int end,
                     int index, int r)
{
    flag=1;
    if(f)
    {
        return;
    }
    int i,j;
    if (index-1 == r)
    {
        memset(bits,0,sizeof(bits));
         for(i=1;i<=r;i++)
	        {
	          
	            bits[a[i]]=1;
	        }
	       
	        for(i=1;i<=n  ;i++)
	        {
	            if(!bits[i]) {continue;}
	            for(j=1;j<=n ;j++)
	            {
	                if(!bits[j]) {continue;}
	                  if(!arr[i][j])
	                    {
	                       
	                        flag=0;
	                        break;
	                    }
	                
	            }
	            if(!flag)
	            break;
	        }
	        
	   
	        if (flag)
	        {
	            f=1;
	            for(i=1;i<=r;i++)
	            {
	                cout<<a[i]<<" ";
	            }
	            cout<<"\n";
	        }
	        return;
        
        
        
    }
 
    for (int i=start; i<=end && end-i+1 >= r-index+1; i++)
    {
       
        a[index] = arr1[i];
       
        combinationUtil(arr1, i+1, end, index+1, r);
    }
}

int main() {
	int t=0,a1,b,i,j,k;
	cin>>t;
	for(int i1=1;i1<=t;i1++)
	{
	    flag=1;f=0;
	    cin>>n>>m;
	    
	    for(i=1;i<=n;i++)
	    {
	        for(j=1;j<=n;j++)
	        {
	            arr[i][j]=0;
	            if(i==j)
	            {
	                arr[i][j]=1;
	            }
	        }
	    }
	    for(i=1;i<=m;i++)
	    {
	        cin>>a1>>b;
	        arr[a1][b]=1;
	        arr[b][a1]=1;
	    }
	    
	    if(m==0|| n==1)
	    {
	        cout<<"Case #"<<i1<<": 1"<<"\n";
	        continue;
	    }
	    int arr1[n+1];
	    for(k=1;k<=n;k++)
	    arr1[k]=k;
	    cout<<"Case #"<<i1<<": ";
	    int nmbr;
	    for(nmbr=n;nmbr>=2;nmbr--)
	    {
	        memset(a,0,sizeof(a));
	        memset(bits,0,sizeof(bits));
	        
	        combinationUtil(arr1,1,n,1,nmbr);
	        
	        if(f)
	        {
	            break;
	        }
	        
	    }
	}
	
	
	return 0;
}
