#include <bits/stdc++.h>
using namespace std;
int n;
struct node
{
  int parent;
  long dist;
  int val;
};

bool givestate(struct node state[200] )
{
  int i;
  for(i=0;i<n;i++)
     {if( state[i].val == 0 )
         return 0;}
  return 1;
}



int main() {
  int t=0;
  cin>>t;

  for(int i1=1;i1<=t;i1++)
  {
      int i,j,current,u1,v1;
      cin>>n;
      long m[n][n],arr[n]={-1};
      struct node state[200];
      for(i=0;i<n;i++)
      {
          for(j=0;j<n;j++)
          {
              cin>>m[i][j];
          }
      }
      for(i=0;i<n;i++)
              {
                state[i].parent=0;
                state[i].dist = 1000010;
                state[i].val = 0;
              }

        state[0].parent=0;
        state[0].dist = 0;
        state[0].val = 1;


      current=0;

        while( givestate(state) != 1 )
          {
            for(i=0;i<n;i++)
            {
              if ( m[current][i] > 0 && state[i].val == 0 )
              {
                if(m[current][i] < state[i].dist)
                {
                  state[i].parent = current;
                  state[i].dist = m[current][i];
                }
              }
            }


            long min1=1000010;
            for(int k=0;k<n;k++)
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

          }

          current=n-1;
          int count=0;

          while(current!=0)
          {

              arr[count]=current;
              current=state[current].parent;
              count++;
          }
          arr[count]=0;
          cout<<"Case #"<<i1<<": ";
          for(i=count;i>=0;i--)
          {
              cout<<arr[i]+1<<" ";
          }
          cout<<"\n";


  }

  return 0;
}
