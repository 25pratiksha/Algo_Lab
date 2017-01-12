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
        cout<<path_flow<<"\n";
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        cout<<"here \n";
        max_flow += path_flow;
    }
    return max_flow;
}

    int main()
    {
      int t=0;
      cin>>t;
      for(int i1=1;i1<=t;i1++)
      {
          cout << "Case #" << i1 << ": ";

          int jobs,prin;
          cin>>prin>>jobs;
          n=prin+jobs;
         for(int i=0;i<=n+1;i++)
        {
            memset(graph[i],0,sizeof(int)*n+1);
            memset(rGraph[i],0,sizeof(int)*n+1);
        }


      char jo[1000];
      for(int i=1;i<=prin;i++)
      {
          cin>>jo;
          if(prin>=jobs){
          for(int j=0;j<strlen(jo);)
          {
              if(isdigit(jo[j]))
              {
                  if(jo[j+1]=='-')
                  {
                      int a1=jo[j]-'0';
                        int b1=jo[j+2]-'0';
                        for(int l=a1;l<=b1;l++)
                        {
                            int l1=l+prin;
                           // Add_edge(G,i,l1);
                           graph[i][l1]=1;
                           graph[l1][i]=1;
                          }
                          j=j+3;
                        }
                        else if(jo[j+1]==',')
                        {
                            int a1=jo[j]-'0';
                            a1=a1+prin;
                            //Add_edge(G,i,a1);
                            graph[i][a1]=1;
                           graph[a1][i]=1;
                            j=j+2;
                        }
                        else
                        {
                            int a1=jo[j]-'0';
                            a1=a1+prin;
                            graph[i][a1]=1;
                           graph[a1][i]=1;
                            j++;
                        }
                  }
                  else
                  {
                      j++;
                  }
              } }
          }
cout<<"nooo \n";
          if(jobs>prin)
          {
               cout<<"no \n";
               continue;
          }
          else
          {
          for(int i=1;i<=prin;i++)
          {
              //cout<<"here \n";
              graph[i][0]=1;
            graph[0][i]=1;

          }

          for(int i=prin+1;i<=n;i++)
          {
               graph[i][n+1]=1;
                graph[n+1][i]=1;
          }

          for(int i=0;i<=n+1;i++)
          {
              for(int j=0;j<=n+1;j++)
              {
                  cout<<graph[i][j]<<"\t";
              }
              cout<<"\n";
          }


         int max1;


        n=n+2;
       //  max1= max_flow(0,n,G);
       max1=fordFulkerson(0,n);
        cout<<"max1 "<<max1<<"\n";
        if(max1==jobs)
        {
            cout<<"yes \n";
        }
        else
        {
            cout<<"no \n";
        }
          }

      }

          return 0;
    }
