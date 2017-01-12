#include<bits/stdc++.h>
using namespace std;
#define pp pair<long,long>

class Prioritize
{
public:
    int operator() ( const pair<long, long>& p1, const pair<long, long>& p2 )
    {
        return p1.second < p2.second;
    }
};

long n,m;   
bool visit[10999]={0};
long node[10999],ctr[10999];

int main()
{
    int t=0;
    cin>>t;
    for(int i1=1;i1<=t;i1++)
    {
       long i,j,k,l,a,b,c;
       cin>>n>>m>>k>>l;
       memset(visit,0,sizeof(visit));
       memset(node,0,sizeof(node));
       
       for(i=0;i<=n;i++)
       {
           ctr[i]=-1;
           
       }
       vector< pp > G[n+1];
       bool added[n+5];
       memset(added,0,sizeof(added));
        for(i=0;i<m;i++)
        {
            cin>>a>>b>>c;
            G[a].push_back(pp(b,c));
            G[b].push_back(pp(a,c));
        }
        
        for(i=0;i<k;i++)
        {
            cin>>a>>b;
            ctr[a]=b;
        }
        if(n==1)
        {
            cout<<"Case #"<<i1<<": "<<l<<"\n";
            continue;
        }
        
        priority_queue<pp, vector<pp > , Prioritize > Q;
        added[1]=1;
        Q.push(pp(1,l));
        bool inactive[n+5]={0};
       
        long u1,v1,w1,arr[n+9];
        j=0;
        bool flag=1;
        while(!Q.empty())
        {
            u1=Q.top().first;
            v1=Q.top().second;
           // cout<<"popped--> v1--> "<<u1<<" "<<v1<<"\n";
            if(inactive[u1] && v1==node[u1])
            {
                inactive[u1]=0;
            }
            Q.pop();
            long size = G[u1].size();
            if(!visit[u1] && !inactive[u1])
            {
                if(v1>=l)
                {
                    visit[u1]=1;
                   // cout<<"j "<<j<<"\n";
                    if(ctr[u1]!=-1)
                    {
                        
                        arr[j++]=ctr[u1];
                       
                    }
                }
                else
                {
                   
                  for(i=0;i<j;i++)
                  {
                     
                      if(v1>=arr[i])
                      {
                          visit[u1]=1;
                          l=v1;
                          break;
                      }
                  }
                }
            
                  
                if(ctr[u1]!=-1 && visit[u1]==1)
                    {
                        
                        arr[j]=ctr[u1];
                        j++;
                    }
            
            
                if(visit[u1]==0 && inactive[u1]==0)
                {
                    flag=0;
                    break;
                }
                long v2,w2;
                for(int i = 0 ; i < size ; i++)
                {
                    v2 = G[u1][i].first;
                    w2 = G[u1][i].second;
                   // cout<<"child weight "<<v2<<" "<<w2<<"\n";
                    if((!added[v2] || w2>node[v2]) && visit[v2]==0)
                    {
                        added[v2]=1;
                        Q.push(pp(v2,w2));
                      //  cout<<"pushed ---> "<<v2<<"\n";
                        node[v2]=w2;
                        if(w2>node[v2])
                        {
                            inactive[v2]=1;
                        }
                    }
                
                }
            }
            
        }
       
        
        if(flag==0)
        {
            cout<<"Case #"<<i1<<": impossible \n";
        }
        else
        {
            cout<<"Case #"<<i1<<": "<<l<<"\n";
        }
        
        
    }
    return 0;
    
}