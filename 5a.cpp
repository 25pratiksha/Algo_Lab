#include<bits/stdc++.h>
using namespace std;

long n,m,e[505],c[505][505],cf[505][505],f[505][505],h[505];
bool visited[505];

void push(long u,long v)
{

    long temp=min(e[u],cf[u][v]);
    f[u][v]=f[u][v]+temp;
    f[v][u]= -1*f[u][v];
    e[u]=e[u]-temp;
    e[v]=e[v]+temp;
    cf[u][v]=c[u][v]-f[u][v];
    cf[v][u]=c[v][u]-f[v][u];
}

using namespace std;

int main()
{
    long t,i,j,a,b,w;
    cin>>t;
    
    for(long i1=1;i1<=t;i1++)
    {
    
        cin>>n>>m;
        vector<long> G[n+1];
        for(i=1;i<=n;i++)
        {
            memset(c[i],0,sizeof(long)*n+1);
            memset(cf[i],0,sizeof(long)*n+1);
            memset(f[i],0,sizeof(long)*n+1);
        }
        memset(visited,0,sizeof(visited));
        memset(e,0,sizeof(e));
        memset(h,0,sizeof(h));
        
        for(i=1;i<=m;i++)
        {
            cin>>a>>b>>w;
        
        if(a!=b)
        {
            if(c[a][b]==0)
            {
            
                G[a].push_back(b);
                G[b].push_back(a);
            }
            c[a][b]=c[a][b]+w;
            c[b][a]=c[b][a]+w;
            cf[a][b]=cf[a][b]+w;
            cf[b][a]=cf[b][a]+w;
        }
 
        }
        
        h[1]=n;
        long size=G[1].size();
        for(long i=0;i<size;i++)
        {
            long v=G[1][i];
            f[1][v]=c[1][v];
            f[v][1]=-1*c[1][v];
            e[v]=c[1][v];
            e[1]=e[1]-c[1][v];
            cf[1][v]=c[1][v]-f[1][v];
            cf[v][1]=c[v][1]-f[v][1];
        }
        std::queue<long> q;
        
        for(i=0;i<G[1].size();i++)
        {
            if(G[1][i]!=n)
            {
                q.push(G[1][i]);
                visited[G[1][i]]=1;
            }
        }
        
        while(!q.empty())
        {
            long u=q.front();
            long m=-1;
            for(i=0;i<G[u].size() && e[u]>0;i++)
            {
                long v=G[u][i];
                if(cf[u][v]>0)
                {
                    if(h[u]>h[v])
                    {
                        push(u,v);
                        if(visited[v]==0 && v!=1 && v!=n)
                        {
                            visited[v]=1;
                            q.push(v);
                        }
                    }
                    else if(m==-1)
                    {
                        m=h[v];
                    }
                    else
                    {
                        m=min(m,h[v]);
                    }
                }
            }
            
            if(G[u].empty()) {q.pop(); continue;}
            if(e[u]!=0)
            {
                h[u]=1+m;
            }
            else
            {
                visited[u]=0;
                q.pop();
            }
            
        }
        
        if(e[n]==0)
        {
            cout<<"Case #"<<i1<<": impossible \n";
        }
        else
        {
            cout<<"Case #"<<i1<<": "<<e[n]<<"\n";
        }
        
    }
    
    return 0;
}