#include<bits/stdc++.h>
using namespace std;
 int n,m,g,graph[505][505],dist[505][505],o[505],max1=INT_MIN,block[505];
 #define pp pair<int,int>
class Prioritize
{
public:
    int operator() ( const pair<int, int>& p1, const pair<int, int>& p2 )
    {
        return p1.second > p2.second;
    }
};

long max(long a,long b)
{
    return(a>b?a:b);
}

void printAllPathsUtil(int u, int d, bool visited[],
                              int path[], int &path_index,int distance)
{
    visited[u] = true;
    path[path_index] = u;
    path_index++;
    if(u!=n)
    {
        distance=distance+dist[u][path[path_index-2]];
        
    }
    cout<<u<<" "<<path[path_index-2]<<"\n";
    //cout<<dist[u][path[path_index-2]]<<"\n";
    cout<<"u distance "<<u<<" "<<distance<<"\n";
    if(dist[g][u]<=distance)
    {
        path_index--;
        visited[u] = false;
        return;
    }
    
    if (u == d)
    {
        long count=0;
        for (int i = 0; i<path_index; i++)
            {
                cout<<"path "<<path[i]<<" ";
                count+=o[path[i]];
            }
            cout<<"\n";
            if(max1<count)
            max1=count;
    }
    else
    {
        
        for (int i = u-1; i >=0 ; i--)
            if (graph[u][i]<INT_MAX && !visited[i] && !block[i])
                printAllPathsUtil(i, d, visited, path, path_index,distance);
        
        
    }
 
    
    path_index--;
    visited[u] = false;
}


int main()
{
    long t,i,j,a,b,c,k,u,v,w;
    scanf("%ld",&t);
    for(int i1=1;i1<=t;i1++)
    {
       cin>>n>>m>>g;
       priority_queue<pp, vector<pp > , Prioritize > Q[n+1];
     vector< pp > G[1001];
       o[0]=0;
       for(i=1;i<=n;i++)
       {
           cin>>o[i];
           
       }
       memset(block,0,sizeof(block));
       for(i=0;i<=n;i++)
       {
           for(j=0;j<=n;j++)
           {
               dist[i][j]=2147483647;
               if(i==j)
               dist[i][j]=0;
           }
       }
       
                
       for(i=0;i<m;i++)
       {
            cin>>a>>b>>c;
            
            G[a].push_back(pp(b,c));
            G[b].push_back(pp(a,c));
            
       }
       
       for(int i2=0;i2<=n;i2++)
       {
            Q[i2].push(pp(i2,dist[i2][i2]));
    
    
             while(!Q[i2].empty())
            {
                
                u = Q[i2].top().first;
                Q[i2].pop();
                int size = G[u].size();
                for(int i = 0 ; i < size ; i++)
                {
                    v = G[u][i].first;
                    w = G[u][i].second;
                   // cout<<"i--"<<i<<" u--"<<u<<" v--"<<v<<" "<<w<<endl;
                    if(dist[i2][v] > dist[i2][u] + w)
                    {
                        //cout<<"old weight"<<dist[i][v]<<"\n";
                        dist[i2][v] = dist[i2][u] + w;
                        dist[v][i2] = dist[i2][u] + w;
                       //cout<<"new weight"<<dist[i][v]<<"\n";
                        Q[i2].push(pp(v,dist[i2][v]));
                    }
                }
            }
           
           
       }
       
       for(i=0;i<=n;i++)
       {
           for(j=0;j<=n;j++)
           {
               cout<<dist[i][j]<<" ";
           }
           cout<<"\n";
       }
       
            
        
        
        if(dist[g][0]<=dist[n][0])
        {
            cout<<"Case #"<<i1<<": impossible \n";
            continue;
        }
        
        for(i=0;i<=n;i++)
        {
            if(dist[g][i]<=dist[n][i])
            block[i]=1;
            if(dist[n][i]==INT_MAX)
            block[i]=1;
        }
        
        bool *visited = new bool[n+1];
        int *path = new int[n+1];
        int path_index = 0;
        memset(visited,0,sizeof(visited));
        printAllPathsUtil(n, 0, visited, path, path_index,0);
        cout<<"Case #"<<i1<<": ";
        if(max1==INT_MIN)
        {
            cout<<"impossible \n";
        }
        else
        {
            cout<<max1<<"\n";
        }
    }
	return 0;
}
