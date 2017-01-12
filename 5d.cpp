#include<bits/stdc++.h>
using namespace std;

long n,m,e[40],c[40][40],cf[40][40],f[40][40],h[40],cf1[40][40];
bool visited[40];

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
    
        cin>>n>>m;
        vector<long> G[n+5];
        
        for(i=0;i<=n;i++)
        {
            memset(c[i],0,sizeof(long)*n+1);
            memset(cf[i],0,sizeof(long)*n+1);
            memset(f[i],0,sizeof(long)*n+1);
        }
        memset(visited,0,sizeof(visited));
        memset(e,0,sizeof(e));
        memset(h,0,sizeof(h));
        
        for(i=1;i<=n;i++)
        {
            cin>>w;
            G[0].push_back(i);
            G[i].push_back(0);
            c[0][i]=c[0][i]+w;
            c[i][0]=c[i][0]+w;
            cf1[i][0]=cf1[0][i]+w;
            cf1[0][i]=cf1[i][0]+w;
            
        }
        
        for(i=0;i<m;i++)
        {
            cin>>a>>b;
        w=1;
        if(a!=b)
        {
            if(c[a][b]==0)
            {
            
                G[a].push_back(b);
                G[b].push_back(a);
            }
            c[a][b]=c[a][b]+w;
            c[b][a]=c[b][a]+w;
            cf1[a][b]=cf1[a][b]+w;
            cf1[b][a]=cf1[b][a]+w;
        }
 
        }
        
        int arr[n+1];
        
        for(int p=1;p<=n;p++)
        {
            
            memset(visited,0,sizeof(visited));
            memset(e,0,sizeof(e));
            memset(h,0,sizeof(h));
            for(int d=0;d<=n;d++)
            {
                for(int z=0;z<=n;z++)
                {
                    cf[d][z]=cf1[d][z];
                }
            }
            
            h[0]=n;
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
                if(G[0][i]!=p)
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
                            if(visited[v]==0 && v!=0 && v!=p)
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
            arr[p]=e[p];
        }
        
        int max=-1;
        
        for(int i=1;i<=n;i++)
        {
            if(max<arr[i])
            {
                max=arr[i];
            }
        }
        cout<<"Case #"<<i1<<": ";
        for(int i=1;i<=n;i++)
        {
            if(arr[i]==max)
            {
                cout<<"yes ";
            }
            else
            {
                cout<<"no ";
            }
        }
        cout<<"\n";
    }
    
    return 0;
}