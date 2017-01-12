#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    int n1=1;
    unsigned long long n,p,q,r,s,a[1000099],i,min=0,u,v,val=0,max,mid; 
    
    cin>>t;
   
    while(t--)
    {
        memset(a,0,sizeof(a));
        cin>>n>>p>>q>>r>>s;
        if(n==1)
        {
            cout<<"Case #"<<n1<<": "<<0<<"\n";
            n1++;
            continue;
        }
        
        max=0;min=0;
        for(i=0;i<n;i++)
        {
            a[i]=((i+1)*p +q)%r +s;
          
            max = max +a[i];
            if(min < a[i])
            {
                min=a[i];
            }
        }
        
       
        while(min < max)
        {
            mid= (min + max)/2;
            unsigned long long reqd=1,curr=0;
            
            for(i=0;i<n;i++)
            {
                if(curr+a[i] <= mid)
                {
                    curr =curr + a[i];
                }
                else
                {
                    ++reqd;
                    curr=a[i];
                    
                }
                
            }
            if(reqd <=3)
            {
                max=mid;
            }
            else
            {
                min=mid+1;
            }
            
        }
        
        
        unsigned long long count1 =0,count2=0,count3=0;
        u=0;v=0;i=0;
          
                while(count1+a[i] <= min)
                {
                    count1 = count1 + a[i];
                    i++;
                }
                u=i;
                while(count2+a[i] <= min)
                {
                    count2 =count2 +a[i];
                    i++;
                }
                v=i;
                while(i<n)
                {
                    count3 =count3 +a[i];
                    i++;
                }
                
                
                if(count1 >= count2 && count1 >= count3) { val=count2+count3;}
                else if (count2 >= count1 && count2 >= count3) { val=count1+count3;}
                else { val=count1+count2;}
            
         cout<<"Case #"<<n1<<": "<<val<<"\n";

        n1++;
    }


    return 0;
}
