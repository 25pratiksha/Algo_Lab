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
    long t,l,i,j,a,b,w;
    cin>>t;
    
    for(long i1=1;i1<=t;i1++)
    {
    
        cin>>l>>n>>m;
        vector<long> G[n+1];
        for(i=0;i<n;i++)
        {
            memset(c[i],0,sizeof(long)*n);
            memset(cf[i],0,sizeof(long)*n);
            memset(f[i],0,sizeof(long)*n);
        }
        memset(visited,0,sizeof(visited));
        memset(e,0,sizeof(e));
        memset(h,0,sizeof(h));
        
        for(i=0;i<m;i++)
        {
            cin>>a>>b>>w;
        
        if(a!=b)
        {
            if(c[a-1][b-1]==0)
            {
            
                G[a-1].push_back(b-1);
                G[b-1].push_back(a-1);
            }
            c[a-1][b-1]=c[a-1][b-1]+w;
            c[b-1][a-1]=c[b-1][a-1]+w;
            cf[a-1][b-1]=cf[a-1][b-1]+w;
            cf[b-1][a-1]=cf[b-1][a-1]+w;
        }
 
        }
        
        h[0]=n-1;
        long size=G[0].size();
        for(long i=0;i<size;i++)
        {
            long v=G[0][i];
            f[0][v]=c[0][v];
            f[v][0]=-1*c[0][v];
            e[v]=c[0][v];
            e[0]=e[0]-c[0][v];
            cf[0][v]=c[0][v]-f[0][v];
            cf[v][0]=c[v][0]-f[v][0];
        }
        std::queue<long> q;
        
        for(i=0;i<G[0].size();i++)
        {
            if(G[0][i]!=n-1)
            {
                q.push(G[0][i]);
                visited[G[0][i]]=1;
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
                        if(visited[v]==0 && v!=0 && v!=n-1)
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
        
        if(e[n-1]>l)
        {
            cout<<"Case #"<<i1<<": no \n";
        }
        else
        {
            cout<<"Case #"<<i1<<": yes \n";
        }
        
    }
    
    return 0;
}