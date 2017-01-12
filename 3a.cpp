#include<bits/stdc++.h>
using namespace std;

int n;

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
   int t;
   cin>>t;

   for(int i1=1;i1<=t;i1++)
   {
      struct node state[1005];
    int i,k,current,m,u1,v1,j;
    long cost[1005][1005],newdist, x[1005],y[1005],z[1005],min_cost=0;
        cin>>n;

       for( i=1;i<=n;i++)cin>>x[i]>>y[i]>>z[i];

        
     for(i=1;i<=n;i++)
      {
          for(j=1;j<=n;j++)
          {
              
                  cost[i][j]= abs(x[i]-x[j]) + abs(y[i]-y[j]) + abs(z[i]-z[j]);
              
           }

      }


      for(i=1;i<=n;i++)
  {
    state[i].parent=0;
    state[i].dist = 1000010;
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
        if(cost[current][i] < state[i].dist)
        {
          state[i].parent = current;
          state[i].dist = cost[current][i];
        }
      }
    }


        long min1=1000010;
    for(int k=1;k<=n;k++)
    {
      if(state[k].val == 0 && state[k].dist < min1)
      {
        min1 = state[k].dist;
        current=k;
      }
    }

    state[current].val=1;
    u1=state[current].parent;
    v1=current;
    min_cost=min_cost+cost[u1][v1];
  //  cout<<min_cost<<"\n";
  }




    cout<<"Case #"<<i1<<":"<<" "<<min_cost<<"\n";

   }
return(0);
}
