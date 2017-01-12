#include<bits/stdc++.h>
using namespace std;
long solution[10010],dp[10010][10010],keep[10010][10010];
long max(long a,long b)
{
    return(a>b?a:b);
}
long knapsack(long W,long wt[],long val[],long id[],long n)
{
    for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=W;j++)
            {
                keep[i][j]=0;
                dp[i][j]=0;
            }
        }
    long i,w,flag;

    for(w=0;w<=W;w++)
    {
        dp[0][w]=0;
    }

    for(i=1;i<=n;i++)
    {

            for(w=0;w<=W;w++)
        {
            if(wt[i]<=w && val[i]+dp[i-1][w-wt[i]]> dp[i-1][w])
            {
                dp[i][w]=val[i]+dp[i-1][w-wt[i]];
                keep[i][w]=1;
            }
            else
            {
                dp[i][w]=dp[i-1][w];
                keep[i][w]=0;
            }
           // cout<<"dp-->"<<dp[i][w]<<" i=="<<i<<" w=="<<w<<" keep"<<keep[i][w]<<" id "<<id[i]<<"\n";
        }

    }
    long k=W;
    for(i=n;i>=0;i--)
    {
        if(keep[i][k])
        {
            //cout<<"i--"<<i<<"\n";
            solution[id[i]]++;
            k=k-wt[i];

        }
    }



    return dp[n][w];
}
void solve()
{
    long i,w,n,wt[1000],qty[1000],val[1000],ans,weight[10010],value[10010],id[10010];
    scanf("%ld %ld",&w,&n);
    for(i=1;i<=n;i++)
    scanf("%ld %ld %ld",&qty[i],&wt[i],&val[i]);
    long k=1;
    for(i=1;i<=n;i++)
    {
     while(qty[i])
     {
        weight[k]=wt[i];
        value[k]=val[i];
        id[k]=i;
        k++;
        qty[i]--;
     }
    }
    /*for(i=1;i<=k;i++)
    {

        cout<<"i-->"<<i<<" id--"<<id[i]<<"\n";
    }*/
    ans=knapsack(w,weight,value,id,k-1);
    //cout<<ans<<endl;
    long sum=0;
    /*for(i=n;i>=1;i--)
    {
        sum+=wt[i-1]*solution[i];
        if(sum>w)
        break;
    }*/

    for(i=1;i<=n;i++)
    {
        while(solution[i])
        {
            cout<<i<<" ";
            solution[i]--;
        }
    }
    cout<<endl;
}
int main()
{
    long t,i;
    scanf("%ld",&t);
    for(i=1;i<=t;i++)
    {
        memset(solution,0,sizeof(solution));
        
        cout<<"Case #"<<i<<": ";
        solve();
    }
	return 0;
}
