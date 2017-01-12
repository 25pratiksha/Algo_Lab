#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node
{
    int chartr;
    int chaptr;
}com[15];
int dep[20][4],count1,valid;
bool pass1,pass2,pass3;

void init()
{
    int i,j;
    valid=0
    pass1=1;
    pass2=1;
    pass3=1;
    for(i=0;i<15;i++)
    {
        com[i].chaptr=0;
        com[i].chartr=0;
    }
    count1=0;
     for(i=0;i<20;i++)
     {
         for(j=0;j<4;j++)
         {
             dep[i][j]=0;
         }
     }
    
}

void swap(struct node &v , struct node &w)
{
    struct node tmp;
    tmp=v;
    v=w;
    w=tmp;
}

void permute(int l,int r)
{
    int i,j,k;
   
    if(l==r)
    {
        for(int t1=0;t1<=count1;t1++)
        {
            
            cout<<com[t1].chartr<<com[t1].chaptr<<" ";
        }
        cout<<"\n";
        
        //  /sequence
       
       for(j=0;j<=count1-1;j++)
       {
           if(com[j].chartr == com[j+1].chartr)
           {
               cout<<"pass2 faild "<<"\n";
               pass2=0;
               return;
           }
       }
        
      // /order
       for(k=1;k<=n;k++)
       {
           int tmp=-1;
           for(j=0;j<=count1;j++)
           {
               if(com[j].chartr == k)
               {
                   
            
                   if(com[j].chaptr<com[tmp].chaptr && tmp!= -1)
                   {
                       cout<<"pass1 faild "<<"\n";
                       pass1=0;
                       return;
                   }
                   
                   tmp=j;
               }
           }
       }
       
     
       
      // /dependencies
       
       for(k=1;k<=m;k++)
       {
           for(j=0;j<=count1;j++)
           {
               if(com[j].chartr==dep[k][0] && com[j].chaptr==dep[k][1]) break;
               
                if(com[j].chartr==dep[k][2] && com[j].chaptr==dep[k][3]) {cout<<"pass3 faild "<<"\n"; 
                pass3=0; return;}
           }
       }
       
       
           cout<<"valid----"<<"\n";
           valid++;
       
       return;
       
       
       
    }
    else
    { 
        for(int i=l;i<=r;i++)
        {
            
            swap(com[l],com[i]);
            if(com[l].chaptr!=com[l+1].chaptr)
            {
            permute(l+1,r);
            }
            swap(com[l],com[i]);
            
        }
    }
    
}

int main()
{
    int t=0,i,j,k,l;
    cin>>t;
    for(int i1=1;i1<=t;i1++)
    {
        count1=0;
        init();
        cin>>n>>m;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            for(j=1;j<=l;j++)
            {
                
                com[count1].chartr=i;
                com[count1].chaptr=j;
                count1++;
            }
        }
        
        for(i=1;i<=m;i++)
        {
            cin>>dep[i][0]>>dep[i][1]>>dep[i][2]>>dep[i][3];
        }
        count1--;
        permute(0,count1);
        cout<<"Case #"<<i1<<": "<<valid<<"\n";
        
        
        
    }
    
    
    return 0;
}