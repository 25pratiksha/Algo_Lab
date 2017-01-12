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

	    sort(ctr0,ctr0+6,cmp);
	    sort(ctr1,ctr1+4,cmp);
	    for(i=0;i<6;i++)
	    {
	        ctr0[i].count=ctr0[i].count*10;
	        //cout<<"ctr0---"<<i<<" "<<ctr0[i].count<<"\n";
	    }
	    for(i=0;i<4;i++)
	    {
	        ctr1[i].count=ctr1[i].count*10;
	       // cout<<"ctr1---"<<i<<" "<<ctr1[i].count<<"\n";
	    }
        int start=0,val=0;
	    int end0=5;
	    int start1=0;
	    bool visit[6]={0};

	    while(start<=end0 && start1<4)
	    {
	    	if(ctr0[start].count==0 && ctr1[start1].count==0)
	    		break;


	        if(start==end0 && start1>=4)
	        {
	            //cout<<start<<" "<<start1<<" "<<end0<<"\n";
	            break;
	        }
	        if(start==end0 && start1<4)
	        {
	            if(visit[end0]==1 && ctr1[start1].count-ctr0[end0].count<=0)
	            {
	                start1=4;
	               // cout<<start<<" "<<start1<<" "<<end0<<"\n";
	                break;
	            }
	            if(visit[end0]==0 && ctr1[start1].count-ctr0[end0].count/2 <=0)
	            {
	                start1=4;
	                //cout<<start<<" "<<start1<<" "<<end0<<"\n";
	                break;
	            }
	            if(visit[end0]==1 && ctr1[start1].count-ctr0[end0].count>0)
	            {
	                val=val+ctr1[start1].count-ctr0[end0].count;
	               // cout<<"val-->"<<val<<"start0"<<start<<"start1--"<<start1<<"end0--"<<end0<<"\n";
	                end0--;
	                start1++;
	               // cout<<"val-->"<<val<<"start0"<<start<<"start1--"<<start1<<"end0--"<<end0<<"\n";
	                continue;
	            }
	            if(visit[end0]==0 && ctr1[start1].count-ctr0[end0].count/2 >0)
	            {
	                val=val+ctr1[start1].count-ctr0[end0].count/2;
	                //cout<<"val-->"<<val<<"start0"<<start<<"start1--"<<start1<<"end0--"<<end0<<"\n";
	                ctr0[end0].count=ctr0[end0].count/2;
	                visit[end0]=1;
	                start1++;
	                //cout<<"val-->"<<val<<"start0"<<start<<"start1--"<<start1<<"end0--"<<end0<<"\n";
	                continue;
	            }
	        }
	        else if(start1>=4)
	        {
	        	if(visit[start]==0)
	        	{
		            if(visit[end0]==0 && ctr0[start].count-ctr0[end0].count>0)
		            {
		                val=val+ctr0[start].count-ctr0[end0].count;
		                //cout<<"val-->"<<val<<"start0"<<start<<"start1--"<<start1<<"end0--"<<end0<<"\n";
		                start++;
		                end0--;
		                //cout<<"val-->"<<val<<"start0"<<start<<"start1--"<<start1<<"end0--"<<end0<<"\n";

		            }
		            if(visit[end0]==1 && ctr0[start].count/2-ctr0[end0].count>0)
		            {
		                val=val+ctr0[start].count/2-ctr0[end0].count;
		                //cout<<"val-->"<<val<<"start0"<<start<<"start1--"<<start1<<"end0--"<<end0<<"\n";
		                ctr0[start].count=ctr0[start].count/2;
		                end0--;
		                visit[start]=1;
		                //cout<<"val-->"<<val<<"start0"<<start<<"start1--"<<start1<<"end0--"<<end0<<"\n";

		            }
		            else
		            {
		                //cout<<"val-->"<<val<<"start0"<<start<<"start1--"<<start1<<"end0--"<<end0<<"\n";
		                break;
		            }
	            }
	            else
	            {
	            	if(visit[end0]==0 && ctr0[start].count-ctr0[end0].count/2>0)
		            {
		                val=val+ctr0[start].count-ctr0[end0].count/2;
		                
		                start++;
		                visit[end0]=1;
		                //cout<<"val-->"<<val<<"start0"<<start<<"start1--"<<start1<<"end0--"<<end0<<"\n";
		            }
		            if(visit[end0]==1 && ctr0[start].count-ctr0[end0].count>0)
		            {
		                val=val+ctr0[start].count-ctr0[end0].count;
		                //cout<<"val-->"<<val<<"start0"<<start<<"start1--"<<start1<<"end0--"<<end0<<"\n";
		                ctr0[start].count=0;
		                end0--;
		                start++;
		                //cout<<"val-->"<<val<<"start0"<<start<<"start1--"<<start1<<"end0--"<<end0<<"\n";
		            }
		            else
		            {
		               // cout<<"val-->"<<val<<"start0"<<start<<"start1--"<<start1<<"end0--"<<end0<<"\n";
		                break;
		            }

	            }
	        }
	        else
	        {
	           

	            if(visit[end0]==0 && (ctr0[start].count-ctr0[end0].count <= ctr1[start1].count-ctr0[end0].count/2))
	            {
	                val=val+ctr1[start1].count-ctr0[end0].count/2;
	               // cout<<"val-->"<<val<<"start0"<<start<<"start1--"<<start1<<"end0--"<<end0<<"\n";
	                start1++;
	                ctr0[end0].count=ctr0[end0].count/2;
	                visit[end0]=1;
	               // cout<<"val-->"<<val<<"start0--"<<start<<"start1--"<<start1<<"end0--"<<end0<<"\n";

	            }
	            else if(visit[end0]==0 && (ctr0[start].count-ctr0[end0].count > ctr1[start1].count-ctr0[end0].count/2))
	            {
	                val=val+ctr0[start].count-ctr0[end0].count;
	                //cout<<"val-->"<<val<<"start0"<<start<<"start1--"<<start1<<"end0--"<<end0<<"\n";
	                start++;
	                end0--;
	                //cout<<"val-->"<<val<<"start0"<<start<<"start1--"<<start1<<"end0--"<<end0<<"\n";
	            }
	            else if(visit[end0]==1 && (ctr0[start].count-ctr0[end0].count -(ctr0[end0-1].count/2) <= ctr1[start1].count-ctr0[end0].count))
	            {
	                val=val+ctr1[start1].count-ctr0[end0].count;
	                //cout<<"val-->"<<val<<"start0"<<start<<"start1--"<<start1<<"end0--"<<end0<<"\n";
	                start1++;
	                ctr0[end0].count=0;
	                end0--;
	               // cout<<"val-->"<<val<<"start0"<<start<<"start1--"<<start1<<"end0--"<<end0<<"\n";

	            }
	            else if(visit[end0]==1 && ((ctr0[start].count-ctr0[end0].count -(ctr0[end0-1].count/2)) > ctr1[start1].count-ctr0[end0].count))
	            {
	               //cout<<ctr0[end0].count;
	                val=val+ctr0[start].count-ctr0[end0].count -(ctr0[end0-1].count/2);
	               // cout<<"val-->"<<val<<"start0"<<start<<"start1--"<<start1<<"end0--"<<end0<<"\n";
	                ctr0[end0-1].count=ctr0[end0-1].count/2;
	                end0--;
	                start++;
	                visit[end0]=1;
	                //cout<<"val-->"<<val<<"start0"<<start<<"start1--"<<start1<<"end0--"<<end0<<"\n";
	            }

	        }
	    }
	    cout<<"Case #"<<i1<<": "<<val<<"\n";
	}

	return 0;
}
