#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,int>

class Prioritize
{
public:
    int operator() ( const pair<int, int>& p1, const pair<int, int>& p2 )
    {
        return p1.second < p2.second;
    }
};


int main() {
	int t=0,u,v,w;
	cin>>t;
	for(int i1=1;i1<=t;i1++)
	{
	    int n;
	    cin>>n;
	    int cost[n][n];
	    priority_queue<pp, vector<pp > , Prioritize > Q;
        vector< pp > G[1001];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin>>cost[i][j];
	            if(cost[i][j]!=0)
	            G[j].push_back(pp(i,cost[i][j]));
	        }
	    }
	    
	    int d[n+1];
    for(int i=0;i<n;i++)
    {
        d[i] = 1000000000;
    }
    
    d[0] = 0;
    Q.push(pp(0,d[0]));
    
    
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
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
              //  cout<<"new weight"<<d[v]<<"\n";
                Q.push(pp(v,d[v]));
            }
        }
    }
    
    
    long long sum = 0;
        for (int i = 1; i < n; i++) {
            int m = 0;
            for (int j = 0; j < n; j++) {
                if (cost[i][j] > m && d[j] != 1000000000) {
                    m = cost[i][j];
                }
            }
            sum += m;
     }
     
     cout<<"Case #"<<i1<<": "<<sum<<"\n";
	    

	   // printf("%0.07lf \n",area);

	}


	return 0;
}