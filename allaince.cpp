#include <bits/stdc++.h>
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


int main() {
	long long N,k,Q1,i,j,u,v,x;
	
	cin>>N;
	priority_queue<pp, vector<pp > , Prioritize > Q;
    vector< pp > G[N+1];
    bool visit[N+1]={0};
    
	for(i=0;i<N-1;i++)
	{
	    cin>>u>>v;
	    G[u].push_back(pp(v,1));
	    G[v].push_back(pp(u,1));
	}
	cin>>k;
	vector< long long > Gang[k+1];
	long long c,V,t;
	for(i=1;i<=k;i++)
	{
	 cin>>c;
	 for(j=1;j<=c;j++)
	 {
	     cin>>x;
	     Gang[j].push_back(x);
	 }
	}
	
	cin>>Q1;
	for(i=0;i<Q1;i++)
	{
	    cin>>V;
	    long long int d[N+1]={100009},w;
	    d[V]=0;
	    Q.push(pp(V,d[V]));
	    while(!Q.empty())
        {
            
            u = Q.top().first;
            Q.pop();
            int size = G[u].size();
            for(int i1 = 0 ; i1 < size ; i1++)
            {
                v = G[u][i1].first;
                w = G[u][i1].second;
                cout<<u<<" "<<v<<" "<<w<<endl;
                if(d[v] > d[u] + w)
                {
                    d[v] = d[u] + w;
                    cout<<"new weight"<<d[v]<<"\n";
                    Q.push(pp(v,d[v]));
                }
            }
        }
        cin>>t;
        for(j=0;j<t;j++)
        {
            cin>>w;
            int size = G[u].size();
            for(int i1 = 0 ; i1 < size ; i1++)
            {
                 v = Gang[w][i1];
                 visit[v]=1;
            }
            
            
        }
        long long min=LONG_MAX;
        for(long i2=1;i2<=N;i2++)
        {
         if(visit[i2]==1 && min>d[i2])
         {
             min=d[i2];
         }
            
        }
        cout<<min<<"\n";
        
	    
	    
	}
	
	return 0;
}
