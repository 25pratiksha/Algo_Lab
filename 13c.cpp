#include<bits/stdc++.h>
using namespace std;

#define infinity 999
int n;
int cap[505][505];
int flow[505][505];
int cf[505][505];
int excess[505];
int height[505];
int w=1;

void Add_edge(vector<int> G[505],int a,int b)
{
                           
                            if(cap[a][b]!=0)
                              {
                                  cap[a][b]+=w;
                                  cap[b][a]+=w;
                                  cf[a][b]+=w;
                                  cf[b][a]+=w;
                              }
                              else{
                                    G[a].push_back(b);
                                     G[b].push_back(a);
                                    cap[a][b]=w;
                              cap[b][a]=w;
                              cf[a][b]=w;
                              cf[b][a]=w;
}

}

void initialize_preflow(int source,vector<int> G[505])
      {
         int i, v;
         height[source] = n;

         for(i=0;i<G[source].size();i++)
         {
            v = G[source][i];
            flow[source][v] = cap[source][v];
            flow[v][source] = -cap[source][v];
            excess[v] = cap[source][v];
            excess[source] -=cap[source][v];
            cf[source][v] = cap[source][v]-flow[source][v];
            cf[v][source] = cap[v][source]-flow[v][source];
         }
      }

void push(int u, int v)
      {
         int push_val = min(cf[u][v], excess[u]);
         flow[u][v] += push_val;
         flow[v][u] = -flow[u][v];
         excess[u] -=push_val;
         excess[v] +=push_val;
         cf[u][v] = cap[u][v]-flow[u][v];
         cf[v][u] = cap[v][u]-flow[v][u];

      }
   int max_flow(int source, int sink,vector<int> G[505])
      {
         initialize_preflow(source,G);
         queue<int> q;
         bool considered[n+1];
         int u, v, m, i;
         memset(considered, false, sizeof(considered));
        for(i=0;i<G[source].size();++i)
         {
           v=G[source][i];

            if(v!=sink)
            {
               q.push(v);
               considered[v] = true;
            }
         }
         bool flag;
         u = -1;
         while(!q.empty())
         {

            u = q.front();
            m = -1;
            for(i=0;i<G[u].size() && excess[u]>0; i++)
            {

               v = G[u][i];
               if(cf[u][v]>0)
               {
                  if(height[u]>height[v])
                  {
                     push(u,v);
                     if(!considered[v] && v!=sink && v!=source)
                     {
                        considered[v] = true;
                        q.push(v);
                     }
                  }
                  else if(m==-1) m = height[v];
                  else   m = min(m, height[v]);
               }
            }

            if(G[u].empty()) {q.pop();continue;}
            if(excess[u]!=0) height[u] = m+1;
            else
            {
               q.pop();
               considered[u] = false;
            }
         }
         return excess[sink];
      }

    int main()
    {
      int t=0;
      cin>>t;
      for(int i1=1;i1<=t;i1++)
      {
          cout << "Case #" << i1 << ": ";
          w=1;
          int jobs,prin;
          cin>>prin>>jobs;
          n=prin+jobs+1;
          vector<int> G[1000];
          memset(excess,0,sizeof(excess));
          memset(height,0,sizeof(height));
        for(int i=0;i<=n+2;i++)
          {
              for(int j=0;j<=n+2;j++)
              {
                  cap[i][j]=0;
                  flow[i][j]=0;
                  cf[i][j]=0;
              }
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
                            Add_edge(G,i+1,l1+1);
                          }
                          j=j+3;
                        }
                        else if(jo[j+1]==',')
                        {
                            int a1=jo[j]-'0';
                            a1=a1+prin;
                            Add_edge(G,i+1,a1+1);
                            j=j+2;
                        }
                        else
                        {
                            int a1=jo[j]-'0';
                            a1=a1+prin;
                            Add_edge(G,i+1,a1+1);
                            j++;
                        }
                  }
                  else
                  {
                      j++;
                  }
              } }
          }

          if(jobs>prin)
          {
               cout<<"no \n";
               continue;
          }
          else
          {
          for(int i=2;i<=prin+1;i++)
          {
              //cout<<"here \n";
              Add_edge(G,1,i);
               
          }
          
          for(int i=prin+2;i<=n+1;i++)
          {
               Add_edge(G,n+2,i);
          }
          
         /* for(int i=0;i<=n+1;i++)
          {
             // cout<<"i--"<<i<<"\n";
              int size=G[i].size();
              ///cout<<"size "<<size<<"\n";
              for(int j=0;j<size;j++)
              {
                  cout<<G[i][j]<<"\t";
              }
              cout<<"\n";
          }*/

            n=n+2;
         int max1;
        // cout<<"max1 "<<max1<<"\n";
         max1= max_flow(1,n,G);
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
