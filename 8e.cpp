#include<bits/stdc++.h>
using namespace std;
 int n,m,g,graph[505][505],dist[505][505],o[505],max1=INT_MIN,block[505];
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
    //cout<<u<<" "<<path[path_index-2]<<"\n";
    //cout<<dist[u][path[path_index-2]]<<"\n";
    //cout<<"u distance "<<u<<" "<<distance<<"\n";
    if(dist[g][u]<=distance)
    {
        path_index--;
        return;
    }
    
    if (u == d)
    {
        long count=0;
        for (int i = 0; i<path_index; i++)
            {
                //cout<<"path "<<path[i]<<" ";
                count+=o[path[i]];
            }
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
    long t,i,j,a,b,c,k;
    scanf("%ld",&t);
    for(int i1=1;i1<=t;i1++)
    {
       cin>>n>>m>>g;
       o[0]=0;
       for(i=1;i<=n;i++)
       {
           cin>>o[i];
       }
       memset(block,0,sizeof(block));
       for (i = 0; i <= n; i++)
        for (j = 0; j <= n; j++)
                graph[i][j]=INT_MAX;
                
       for(i=0;i<m;i++)
       {
            cin>>a>>b>>c;
            graph[a][b]=c;
            graph[b][a]=c;
       }
       
       for (i = 0; i <= n; i++)
        for (j = 0; j <= n; j++)
            dist[i][j] = graph[i][j];
            
        for (k = 0; k <= n; k++)
        {
            for (i = 0; i <= n; i++)
            {
                for (j = 0; j <= n; j++)
                {
                    if(i==j)
                    {
                        dist[i][j]=0;
                    }
                    
                    else if (dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        
        /*for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            cout<<dist[i][j]<<" ";
            //cout<<graph[i][j]<<" ";
        cout<<"\n";
        }*/
        
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
