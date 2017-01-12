#include<bits/stdc++.h>
using namespace std;

unsigned long long num[1009],rem[1009],k;

// code referred from   geeksforgeeks

void findMinX()
{
    unsigned long long x =num[0],val1,val2; 
    bool flag1=0,flag2=0;
    
    while (true)
    {
        
        unsigned long long j,t;
        if(!flag1)
        {
             for (j=0; j<k; j++ )
            {
                if (x%num[j] != rem[j])
                   break;
                   
            }  
            if (j == k)
            {
                val1=x;
                flag1=1;
            }
        }
        
        if(!flag2)
        {
           for (t=0; t<k; t++ )
            {
                if (x%num[t] != 0)
                {
                    
                   break;
                }
                
            } 
            if(t==k)
            {
                val2=x;
                flag2=1;
            }
        }
        
        if(flag1 && flag2)
        {
            cout<<val1<<" "<<val2<<"\n";
            return;
        }
        
        x=x+num[0];
        
        //cout<<"x---"<<x<<"\n";
    }
 
}
 
//referred code ends 

int main()
{
    int t=0,i;
    cin>>t;
    for(int i1=1;i1<=t;i1++)
    {
        cin>>k;
        for(int i=0;i<k;i++)
        {
            cin>>num[i];
            if(i%num[i]==0)
            {
                rem[i]=0;
            }
            else
            {
                rem[i]= num[i]- i%num[i];
            }
        }
        
        
        cout<<"Case #"<<i1<<": ";
        
        findMinX();
        
        

    }
    return 0;

}
