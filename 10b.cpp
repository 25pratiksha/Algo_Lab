#include<bits/stdc++.h>
using namespace std;
bool prime[100000009];
long list1[100000000];
long ctr=0;

//code referred from https://www.topcoder.com/community/data-science/data-science-tutorials/mathematics-for-topcoders/
void sieve(long n)
{
   prime[0]=0;
   prime[1]=0;
   //int m=Math.sqrt(n);

   for (long i=2; i<=n; i++)
   {
       if (prime[i]==1)
       {
           for (long k=i*i; k<=n; k+=i)
           {
               prime[k]=0;
           }

       }


   }
   long k=0;
   for(long i=2; i<=n; i++)
   {

       if(prime[i]==1)
       {
           list1[k++]=i;
       }
   }
   ctr=k-1;
}

//referred code ends

void even_prime(long n)
{
    long i=0;
    while(i<ctr)
    {
        long num=list1[i];

        if(num*2 == n)
        {
            cout<<num<<" "<<num<<"\n";
            return;
        }
        else if(prime[n-num]==1)
        {
            cout<<num<<" "<<n-num<<"\n";
            return;
        }
        i++;
    }

}

void odd_prime(long n)
{
    long i=0;
    if(prime[n-4]==1)
    {
        cout<<2<<" "<<2<<" "<<n-4<<"\n";
        return;
    }
    else
    {
        cout<<3<<" ";
        even_prime(n-3);
    }
}




int main()
{
    int t=0,i;
    cin>>t;
    memset(prime,1,sizeof(prime));
    sieve(100000006);
    //sieve(150);
    for(int i1=1;i1<=t;i1++)
    {
        long n;
        cin>>n;
        cout<<"Case #"<<i1<<": ";
        if(n%2==0)
        {

            even_prime(n);
        }
        else
        {

            odd_prime(n);
        }



    }
    return 0;

}
