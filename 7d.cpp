#include <bits/stdc++.h>
using namespace std;

int n,m;
struct node
{
    int a;
    int count;
    int value;
    
};

bool cmp(struct node a1, struct node b1)
{
    if(a1.count>b1.count)
    return 1;
    else return 0;
}

int main() {
	int t=0;
	cin>>t;

	for(int i1=1;i1<=t;i1++)
	{
	    int i,j,k;
	    char hum[205][105];
	    char mou[205][105];
	    cin>>n>>m;
	    for(i=0;i<n;i++)
	    {
	        cin>>hum[i];   
	    }
	    for(i=0;i<m;i++)
	    {
	        cin>>mou[i];
	    }
	    node ctr0[6],ctr1[4];
	    int len=strlen(hum[0]);
	    
	    char h,c;
	    for(i=0;i<6;i++)
	    {
	        ctr0[i].a=i;
    	    ctr0[i].count=0;
    	    ctr0[i].value=0;
	    }
	    for(i=0;i<4;i++)
	    {
	        ctr1[i].a=i;
    	    ctr1[i].count=0;
    	    ctr1[i].value=0;
	    }
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<m;j++)
	        {
	            k=0;
	            while(k!=len)
	            {
    	            h=hum[i][k];
    	            c=mou[j][k];
    	            
    	            if(h=='A' && c=='A')
    	            {
    	                ctr1[0].count++;
    	            }
    	            else if((h=='A' && c=='C') || (h=='C' && c=='A'))
    	            {
    	                ctr0[0].count++;
    	            }
    	            else if((h=='A' && c=='T') || (h=='T' && c=='A'))
    	            {
    	                ctr0[1].count++;
    	            }
    	            else if((h=='A' && c=='G') || (h=='G' && c=='A'))
    	            {
    	                ctr0[2].count++;
    	            }
    	            else if(h=='C' && c=='C')
    	            {
    	                ctr1[1].count++;
    	            }
    	            else if((h=='T' && c=='C') || (h=='C' && c=='T'))
    	            {
    	                ctr0[3].count++;
    	            }
    	            else if((h=='G' && c=='C') || (h=='C' && c=='G'))
    	            {
    	                ctr0[4].count++;
    	            }
    	            else if(h=='T' && c=='T')
    	            {
    	                ctr1[2].count++;
    	            }
    	            else if((h=='T' && c=='G') || (h=='G' && c=='T'))
    	            {
    	               ctr0[5].count++;
    	            }
    	            else if(h=='G' && c=='G')
    	            {
    	               ctr1[3].count++;
    	            }
    	            k++;
	            }
	            
	        }
	    }
	    
	    sort(ctr0,ctr+6,cmp);
	    sort(ctr1,ctr+4,cmp);
        int start=0;
	    int end0=5;
	    int start1=0;
	    int val=0;
	    
	    while(start<=end0)
	    {
	        if(start1<=2 && (ctr1[start1].count + ctr1[start1+1].count >=ctr0[start].count))
	        {
	        
	            ctr1[start1].value=10;
	            ctr1[start1+1].value=10;
	            ctr0[end0]=-10;
	            start1=start1+2;
	            end0--;
	        
	        }
	        else
	        {
	           ctr0[start].value=10;
	           ctr0[end0].value=-10;
	           start++;
	           end0--;
	            
	        }
	        
	        
	        
	        
	       /* if(start==end)
	        {
	           ctr[start].value=0;
	        }
	        else
	        {
	               ctr[start].value=10;
	               
    	            if(ctr[start].pos==1 && ctr[end].pos==0)
    	            {
    	                ctr[end].value=-1*5;
    	            }
    	            if(ctr[start].pos==0 && ctr[end].pos==0)
    	            {
    	                ctr[end].value=-1*10;
    	            }
    	            if(ctr[start].pos==1 && ctr[end].pos==1)
    	            {
    	                
    	                while(ctr[end].pos==1)
    	                {
    	                    ctr[end].value=0;
    	                    end--;
    	                }
    	                ctr[end].value=-1*5;
    	            }
    	            if(ctr[start].pos==0 && ctr[end].pos==1)
    	            {
    	                
    	                while(ctr[end].pos==1)
    	                {
    	                    ctr[end].value=0;
    	                    end--;
    	                }
    	                ctr[end].value=-1*10;
    	            }
	        }
	       
	        //val=val+ ctr[start].value*ctr[start].count + ctr[end].value*ctr[end].count;
	        start++;
	        end--; */
	    }
	    
	    for(i=0;i<10;i++)
	    {
    	    if(ctr[i].a==0 || ctr[i].a==4 || ctr[i].a==7 || ctr[i].a==9)
    	    {
    	        ctr[i].count=ctr[i].count/2;
    	    }
    	    val=val+ctr[i].value*ctr[i].count;
	    }
	     for(i=0;i<10;i++)
	    {
	        cout<<i<<"---->";
	        cout<<ctr[i].a<<" "<<ctr[i].count<<" "<<ctr[i].pos<<" "<<ctr[i].value<<"\n";
	    }
	    int countp=0;
	    
	   /* for(i=0;i<10;i++)
	    {
	        if(ctr[i].a==0 || ctr[i].a==4 || ctr[i].a==7 || ctr[i].a==9)
	        {
	            if(ctr[i].value<10)
	            {
	                countp=countp+ 20;
	            }
	        }
	        else
	        {
	            if(ctr[i].value==0)
	            {
	                countn=countn+ 10;
	            }
	            if(ctr[i].value==-5)
	            {
	                countn=countn+ 5;
	            }
	            
	        }
	        
	    } */
	    
	    
	    
	    
	    cout<<"Case #"<<i1<<": "<<val<<"\n";
	    
	    
	    
	    
	    
	    
	    
	    
	   
	}

	return 0;
}
