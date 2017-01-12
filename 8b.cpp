#include<bits/stdc++.h>
using namespace std;
long min1[10010],stor[2][10010],visit[10010];

long max(long a,long b)
{
    return(a>b?a:b);
}

void back_tr(long a1)
{
    cout<<"hi3";
    long a=stor[0][a1];
   long b=stor[1][a1];
   if(a==-1)
   {
       visit[b]++;
       return;
   }
    if(b==-1)
   {
       visit[a]++;
       return;
   }
   

        back_tr(a);
        back_tr(b);
        return;

}

long knapsack(long w,long wt[],long val[],long id[],long n)
{
    
    long i,j,flag;
    bool k;
    min1[0]=0;
    for(i=1;i<=w;i++)
    {
        long tmp=i;
        for(j=0;j<n;j++)
        {
            cout<<i<<" wt-->"<<wt[j]<<"val-->"<<val[j]<<" min-->"<<min1[i]<<" min1[i-wt[j]-->"<<min1[i-wt[j]]<<"\n";
            if ((wt[j] <= i||tmp>=wt[j]) && val[j]+min1[i-wt[j]] > min1[i])
            {
                    if(tmp<wt[j] && min1[i]< min1[i-wt[j]]+val[j])
                    {
                        tmp=i;
                        min1[i]=0;
                    }
                   min1[i]=val[j]+min1[i-wt[j]];
                   
                    if(wt[j]==i)
                    {
                        stor[0][i]=id[i];
                        stor[1][i]=-1;
                    }
                    else
                    {
                        stor[0][i]=id[i-wt[j]];
                        stor[1][i]=id[wt[j]];
                    }
                    tmp=i-wt[j];
                
            }
           
            
        }
        if(min1[i]<0)
        {
            min1[i]=0;
        }
        
    }
    for(i=1;i<=w;i++)
        {
            cout<<i<<" "<<stor[0][i]<<" "<<stor[1][i]<<"\n";
        }
        cout<<"\n";
}
void solve()
{
    
    long i,w,n,wt[100],qty[1000],val[1000],ans,weight[10090],value[10090],id[10090];
    scanf("%ld %ld",&w,&n);
    for(i=0;i<n;i++)
    scanf("%ld %ld %ld",&qty[i],&wt[i],&val[i]);
    long k=0;
    for(i=0;i<n;i++)
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
    
    knapsack(w,weight,value,id,k);
    back_tr(w);
   
    for(i=0;i<=w;i++)
    {
        while(visit[i])
        {
            cout<<i+1<<" ";
            visit[i]--;
        }
    }
    cout<<endl;
}
int main() 
{
    long t,i;
    scanf("%ld",&t);
    for(int i1=1;i1<=t;i1++)
    {
        //memset(solution,0,sizeof(solution));
        for(int i=0;i<10010;i++)
        {
            min1[i]=LONG_MIN;
            stor[0][i]=0;
            stor[1][i]=0;
            visit[i]=0;
        }
        cout<<"Case #"<<i1<<": ";
        solve();
    }
    return 0;
}
 