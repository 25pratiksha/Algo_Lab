#include<bits/stdc++.h>
using namespace std;
#define V 505

int graph[V][V],n,m;
int rGraph[V][V];
bool bfs( int s, int t, int parent[])
{
    bool visited[n];
    memset(visited, 0, sizeof(visited));
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    // Standard BFS Loop
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v=0; v<n; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return (visited[t] == true);
}

int fordFulkerson(int s, int t)
{
    int u, v;

    for (u = 0; u < n; u++)
        for (v = 0; v < n; v++)
             rGraph[u][v] = graph[u][v];

    int parent[n];
    int max_flow = 0;

    while (bfs(s, t, parent))
    {
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}


int main()
{
    int cases;
    cin>>cases;
    for(int i1=1;i1<=cases;i1++)
    {
        int a,b,c,val=0;
        cin>>n>>m;

        for(int i=0;i<n;i++)
        {
            memset(graph[i],0,sizeof(int)*n);
            memset(rGraph[i],0,sizeof(int)*n);
        }

        for(int i=0;i<m;i++)
        {

                cin>>a>>b>>c;
                graph[a-1][b-1]=graph[a-1][b-1]+c;
                graph[b-1][a-1]=graph[b-1][a-1]+c;

        }

        val=fordFulkerson(0,n-1);
        if(val==0)
        {
            cout<<"Case #"<<i1<<": impossible \n";
        }
        else
        {
            cout<<"Case #"<<i1<<": "<<val<<"\n";
        }



    }


    return 0;
}
