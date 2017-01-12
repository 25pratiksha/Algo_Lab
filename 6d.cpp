#include<bits/stdc++.h>
using namespace std;

int min1=INT_MAX,countr;
int b[10],a[10],n;
int arr[10][10];
void swap(int &v , int &w)
{
    int tmp;
    tmp=v;
    v=w;
    w=tmp;
}
void permute(int a[10],int l,int r)
{
    int c,m;
    if(l==r)
    {
        countr=0;
        for(int i=0;i<n-1;i++)
        {
            m=a[i];
            c=a[i+1];
            //cout<<arr[m][c]<<"+ "<<countr<<"\n";
            countr =countr + arr[m][c];
           // cout<<arr[m][c]<<"\n";
        }
        countr=countr+arr[a[0]][a[n-1]];
        if(countr < min1)
        {
            min1=countr;
          // cout<<countr<<" ";
            for(int i=0;i<n;i++)
            {
                b[i]=a[i]+1;
               //cout<<b[i]<<" ";
            }
        }
        //cout<<"\n";
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(a[l],a[i]);
            permute(a, l+1,r);
            swap(a[l],a[i]);
        }
    }
    
}
int main()
{
    int t=0;
    cin>>t;
    for(int i1=1;i1<=t;i1++)
    {
        min1=INT_MAX;
        countr=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        cin>>n;
        
        for(int i=0;i<n;i++)
        {
            a[i]=i;
            for(int j=0;j<n;j++)
            {
                cin>>arr[i][j];
            }
        }
        
        permute(a,0,n-1);
        
        cout<<"Case #"<<i1<<": ";
        for(int i=0;i<n;i++)
        {
            cout<<b[i]<<" ";
        }
        cout<<"\n";
        
        
        
        
    }
    
    return 0;
}