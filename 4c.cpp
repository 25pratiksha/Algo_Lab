#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
class Prioritize
{
public:
    int operator() ( const pair<int, int>& p1, const pair<int, int>& p2 )
    {
        return p1.second > p2.second;
    }
};

int main()
{
    long t;
   int p,s,n,i,j,a,u,v,w;
   
    cin>>t;
    
    for(long i1=1;i1<=t;i1++)
    {
     priority_queue<pp, vector<pp > , Prioritize > Q;
     vector< pp > G[1001];
     cin>>n;
     
     for(i=1;i<=n;i++)
     {
         
         cin>>p;
         cin>>s;
         for(j=0;j<s;j++)
         {
             cin>>a;
             G[i].push_back(pp(a,p));
             
         }
     }
     
    int d[n+1];
    for(int i=1;i<=n;i++)
    {
        d[i] = 0;
    }
    
    d[1] = 0;
    Q.push(pp(1,d[1]));
    
    
     while(!Q.empty())
    {
        
        u = Q.top().first;
        Q.pop();
        int size = G[u].size();
        for(int i = 0 ; i < size ; i++)
        {
            v = G[u][i].first;
            w = G[u][i].second;
            //cout<<u<<" "<<v<<" "<<w<<endl;
            if(d[v] < d[u] + w)
            {
                d[v] = d[u] + w;
              //  cout<<"new weight"<<d[v]<<"\n";
                Q.push(pp(v,d[v]));
            }
        }
    }
     
     d[n]=d[n]+p;
     //for(int i=1; i<=n; i++) printf("Node %d, min weight = %d\n", i, d[i]);
     cout<<"Case #"<<i1<<": "<<d[n]<<"\n";
     
    
    }
    
    
    return 0;
}

