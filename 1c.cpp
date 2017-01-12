#include<bits/stdc++.h>
using namespace std;

struct team
{
    int a[5];
};

bool cmp1(int a,int b)
{
    return (a>b);
}

bool cmp(struct team q, struct team b)
{
    for(int i=0;i<5;i++)
    {
        if(q.a[i]>b.a[i])
        {
            return 1;
        }
        if(q.a[i]<b.a[i])
        {
            return 0;
        }
    }
}

int main()
{

    int t;
    int c=1;
    cin>>t;
   while(t--)
   {
    int n;
    struct team teams[1000];
    cin>>n;
    

        for(int j=0;j<n;j++)
        {

            for(int k=0;k<5;k++)
            {
                cin>>teams[j].a[k];
            }
            
        }



        for(int j=0;j<n;j++)
        {
            sort(teams[j].a,teams[j].a + 5,cmp1);
        }




        sort(teams,teams+n,cmp);



        cout<<"Case #"<<c<<":\n";
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<5;k++)
            {
                cout<<teams[j].a[k]<<" ";

            }
            cout<<"\n";
        }
        c++;

    
    
    }
return 0;
}



