#include<bits/stdc++.h>
using namespace std;

long n;
bool visit[1001]={0};
void DFS(long u,long cost[1001][1001])
{
       
        for(long i=1;i<=n;i++)
        {
            if(cost[u][i]>0)
            {
                if(visit[i]==0)
                {
                    
                    visit[i]=1;
                    DFS(i,cost);
                   
                }
            }
        }
         return;
}

struct node
{
  int parent;
  long dist;
  int val;
};

bool givestate(struct node state[1005] )
{
  int i;
  for(i=1;i<=n;i++)
     {if( state[i].val == 0 )
         return 0;}
  return 1;
}

int main()
{
    long t,a,b,x,l,i,j,m,c;
    long cost[1001][1001];
    cin>>t;
    
    for(int i1=1;i1<=t;i1++)
    {   
        bool flag=1;
        struct node state[1005];
        long max_cost=0,count=0,u1,v1,current;
        cin>>n>>m;
        
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {cost[i][j]=0;}
        }
        
        for(i=1;i<=m;i++)
        {
            cin>>a>>b>>x>>l;
            c=x*l;
            if(cost[a][b] <  c)
            { 
            cost[a][b]= c;
            cost[b][a]= c;
            }
            count=count+ c;
        }
        
       
        memset(visit,0,sizeof(visit));
        visit[1]=1;
        
        DFS(1,cost);
        for(int k=1;k<=n;k++)
        {
            if(visit[k]==0)
            {
                 cout<<"Case #"<<i1<<":"<<" "<<"impossible"<<"\n";   
                 flag=0;
                 break;
            }
        }
        if(!flag)
        {
            continue;
        }
        
        
        
        
        for(i=1;i<=n;i++)
      {
        state[i].parent=0;
        state[i].dist = 0;
        state[i].val = 0;
      }

  state[1].parent=0;
  state[1].dist = 0;
  state[1].val = 1;


  current=1;

  while( givestate(state) != 1 )
    {
        for(i=1;i<=n;i++)
        {
          if ( cost[current][i] > 0 && state[i].val == 0 )
          {
            if(cost[current][i] > state[i].dist)
            {
              state[i].parent = current;
              state[i].dist = cost[current][i];
            }
          }
        }
    
    
            long max1=0;
        for(int k=1;k<=n;k++)
        {
          if(state[k].val == 0 && state[k].dist > max1)
          {
            max1 = state[k].dist;
            current=k;
          }
        }
    
        state[current].val=1;
        u1=state[current].parent;
        v1=current;
        max_cost=max_cost+cost[u1][v1];

    }
        
        long y=count-max_cost;
        
       
            cout<<"Case #"<<i1<<":"<<" "<<y<<"\n";
        
    }
    return 0;
}