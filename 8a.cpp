#include<bits/stdc++.h>
using namespace std;
int c;
long visit[100009];
long stor[2][100009];
void back_tr(long a)
{
    int val;
    for(int i=0;i<2;i++)
    {
        val=stor[i][a];
        if(val==a)
        {
            visit[a]=visit[a]+1;
             return;
        }
        back_tr(val);

    }
  
    return;

}

int main()
{
    int t=0;
    cin>>t;
    for(int i1=1;i1<=t;i1++)
    {
        int n,i,j;
        cin>>n>>c;
        long v[n+1], min[c+1];

        for(i=0;i<n;i++)
        {
            cin>>v[i];
        }
        for(i=0;i<=c;i++)
        {
            min[i]=LONG_MAX;
            stor[0][i]=0;
            stor[1][i]=0;
            visit[i]=0;
        }
      
        min[0]=0;
        for(i=1;i<=c;i++)
        {

            for(j=0;j<n;j++)
            {
                if(v[j]<=i && min[i-v[j]]+1<min[i])
                {

                    min[i]=min[i- v[j]]+1;
                    if(v[j]==i)
                    {
                        stor[0][i]=i;
                        stor[1][i]=0;
                    }
                    else
                    {

                        stor[0][i]=i-v[j];
                        stor[1][i]=v[j];
                    }

                }

            }
        }

          back_tr(c);
          cout<<"Case #"<<i1<<": ";
            for(i=0;i<n;i++)
            {
                cout<<visit[v[i]]<<" ";

            }
            cout<<"\n";

    }



    return 0;
}


