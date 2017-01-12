#include<bits/stdc++.h>
using namespace std;
bool visit[10001]={0};
bool mat[10001][10001]={0},flag=1;

void DFS(int v,int u,bool mat[10001][10001],int n,int count1)
{
    if(flag==0){return;}
    visit[u]=1;
    for(int i=1;i<=n;i++)
    {
        
        if(mat[u][i]==1)
        {

            if(v==i && visit[v]==1 && count1%2==1)
            {
                 flag=0;
                return;
            }
            if(!visit[i])
            {
            count1++;
            visit[i]=1;
            DFS(v,i,mat,n,count1);
            if(flag==0){return;}
            count1--;
            }
        }
    }
}

int main()
{
    int t,n,m,a,b;
    cin>>t;



    for(int i=1;i<=t;i++)
    {

        flag=1;
        cin>>n>>m;
        if(m==0)
        {
            cout<<"Case #"<<i<<": yes \n";
            continue;
        }
        
        for(int q=1;q<=n;q++)
        {
            for(int r=1;r<=n;r++)
            {mat[q][r]=0;}
        }

        for(int k=0;k<m;k++)
        {
            cin>>a>>b;
            mat[a][b]=1;
            mat[b][a]=1;
        }
        
      
        for(int k=1;k<=n;k++)
        {
            
            memset(visit,0,sizeof(visit));
            DFS(k,k,mat,n,1);
        }
        if(flag)
        {cout<<"Case #"<<i<<": yes \n";}
        else
        {cout<<"Case #"<<i<<": no \n";}

    }


    return 0;

}
