#include<bits/stdc++.h>
using namespace std;

 bool cost[10001][10001];
int main()
{
    long t,i,j,m,a,b,indegree[10001],n;
   
    int p[10001];
    cin>>t;
    
    for(int i1=1;i1<=t;i1++)
    {   
        long v,count=0,val=0;
        queue<long> q;
        memset(indegree,0,sizeof(indegree));
        
        
        cin>>n>>m;
       
        for(i=1;i<=n;i++)cin>>p[i];
        
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                cost[i][j]=0;
            }
        }
        
        for(i=1;i<=m;i++)
        {
            cin>>a>>b;
            if(cost[a][b]==0)
            {indegree[b]++;}
            cost[a][b]=1;
        }
        
        for(i=1;i<=n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i); val++;
                
            }
        }
        
        if(val==n)
        {
            for(i=1;i<=n;i++)
            {count=count+p[v];}
            cout<<"Case #"<<i1<<": "<<count<<"\n";
            continue;
        }
        
        while(!q.empty())
        {
            v=q.front();
            count=count+p[v];
            q.pop();
            
            for(i=1;i<=n;i++)
            {
                if(cost[v][i]==1)
                {
                    cost[v][i]=0;
                    indegree[i]--;
                    if(indegree[i]==0)
                    {
                        q.push(i);
                    }
                    
                }
            }
            
        }
        
        cout<<"Case #"<<i1<<": "<<count<<"\n";
        
        
        
       
        
    }
    return 0;
}