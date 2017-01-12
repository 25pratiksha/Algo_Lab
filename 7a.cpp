#include <bits/stdc++.h>
using namespace std;

struct node1
{
    char str[35];
    long fun;
    long len;
};

bool cmp(struct node1 a, struct node1 b)
{
    if(a.fun>b.fun)
    {
        return 1;
    }
    else
    {
    return 0;
    }
}

int main() {
	int t=0;
	cin>>t;
	for(int i1=1;i1<=t;i1++)
	{
	    long n,m;
	    cin>>n>>m;
	    struct node1 node[n+1];
	    long mins=m*60;
	    char str[35];
	    long fun,len;
	    long C_fun=0;
	    for(int i=0;i<n;i++)
	    {
	        cin>>str>>fun>>len;
	        strcpy(node[i].str,str);
	        node[i].fun=fun;
	        node[i].len=len;
	    }
	    
	    sort(node,node+n,cmp);
	    
	    
	    int i=0;
	    while(mins>=0 && i<n)
	    {
	        node1 temp=node[i];
	        if(mins>=temp.len)
	        {
	            C_fun=C_fun+ temp.fun*temp.len ;
	            mins = mins - temp.len;
	        }
	        else
	        {
	            C_fun=C_fun + temp.fun*mins;
	            mins=0;
	        }
	        
	       // cout<<"Fun---->"<<C_fun<<"\n";
	        i++;
	        
	        
	    }
	    
	    
	    cout<<"Case #"<<i1<<": "<<C_fun<<"\n";
	    
	}
	
	
	
	return 0;
}
