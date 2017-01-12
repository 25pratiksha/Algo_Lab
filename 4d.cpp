#include<bits/stdc++.h>
using namespace std;
#define pp pair<long,long>
class Prioritize
{
public:
    long operator() ( const pair<long, long>& p1, const pair<long, long>& p2 )
    {
        return p1.second < p2.second;
    }
};

int main()
{
    long t;
   long n,x,m,b,arr,u,v,w,i,j,a[3001],am;
   
    cin>>t;
    
    for(long i1=1;i1<=t;i1++)
    {
        memset(a,0,sizeof(a));
     priority_queue<pp, vector<pp > , Prioritize > Q;
     
     vector< pp > G[3001];
     cin>>n>>x>>m;
     
     for(i=1;i<=n;i++) {cin>>a[i];}
     
     
     
     for(i=1;i<=n;i++)
     {
         
         cin>>b;
         
         for(j=1;j<=b;j++)
         {
             cin>>arr;
             G[arr].push_back(pp(i,a[i]));
             //G[arr].push_back(pp(i,0));
         }
     }
     long way[m+1]; way[0]=1;
     long h=0;
     for(i=1;i<=m;i++)
     {
        h++;
        long l;
         cin>>l;
         way[h]=l;
         if(l == 0)
         {
             if(h>=2)
             {
             h=h-2;
             }
             else
             {
                 h=0;
             }
         }
     }

     
    long d[n+1];
   bool flag=0;
    for(i=0;i<=h;i++)
    {
        if(way[i]==x)
        {
            cout<<"Case #"<<i1<<": "<<a[x]<<"\n";
            flag=1;
            break;
        }
    }
    
    if(flag){continue;}
    
    for(int c=1;c<=n;c++)
        {
            d[c]=2147483647;

        }

        d[x]=0;
        Q.push(pp(x,d[x]));
        while(!Q.empty())
        {
                    
                    u = Q.top().first;
                    Q.pop();
                    long size = G[u].size();
                    for(i = 0 ; i < size ; i++)
                    {
                        v = G[u][i].first;
                        w = G[u][i].second;
                        if(d[v] > d[u] + w)
                        
                        {
                            d[v] = d[u] + w;
                            Q.push(pp(v,d[v]));
                        }
                    }
        }

        long min=2147483647;
        for(i=0;i<=h;i++)
        {
            if(min> d[way[i]])
            {
                min=d[way[i]];
            }

        }
       
        
        if(min==2147483647)
        {
            cout<<"Case #"<<i1<<": "<<"impossible"<<"\n";
        }
        else
        {
             min=min+a[x];
        cout<<"Case #"<<i1<<": "<<min<<"\n";
        }
    }
    
    
    return 0;
}

