#include<bits/stdc++.h>
using namespace std;
bool prime[100000009];
long list1[100000000];
long ctr=0,nmbr=0,c=0;
long a[9];
bool flag=0,gen[100000009],flag1=1;
void permute(int, int, double& ,double);

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

void swap(int& x, int& y)
{
    long temp;
    temp = x;
    x = y;
    y = temp;
}

long convert()
{
    long N=0;
    for(long i=0;i<=c;i++)
    {
        N=N*10 + a[i];
    }
    return N;

   // cout<<"a---";
    for(long i=0;i<=c;i++) cout<<a[i];
    //cout<<" N----"<<N<<"\n";
}

void generate(long n)
{

     c=0;
     nmbr=0;
     long val=n;
    while(val!=0)
    {

        val=val/10;
        nmbr=nmbr*10 + 9;
       
    }

// cout<<"nmbr of 9--"<<nmbr<<"\n";

    long k,i,j;
    for( k=0;list1[k]<=n;k++);

    for(i=k;list1[i]<=nmbr;i++)
    {
        val=list1[i];
        double nbrx = log10(val);

       // cout<<"val---"<<val<<"\n";
       // cout<<"nbrx---"<<nbrx<<"\n";
        c=0;
        while(val!=0)
        {
            a[c++]=val%10;
            val=val/10;
        }
        c--;
        for(long y=0,j=c;y<=j;y++,j--)
        {
            swap(a[y],a[j]);
        }
        //call permute
       /* cout<<"a---";
        for(long i=0;i<=c;i++) cout<<a[i];
        cout<<"\n";*/

        double ctrx=0;
        permute(0,c,ctrx,nbrx);
        if(flag==1 || flag1==1)
        {
            cout<<list1[i]<<"\n";
            return;
        }

    }

}

void permute(int l, int r, double& ctrx,double nmrx )
{
    if(flag==1) return;
    long N=convert();
    
    if(gen[N]==1)
    {
        return;
    }
    
   int i;
   if (l == r)
     {
        // cout<<"in permute N----"<<N<<"\n";
          N=convert();
          gen[N]=1;
         if(prime[N]==1)
         {
             ctrx++;
             if(ctrx>nmrx)
             {
                 flag=1;
                 return;
             }
         }
         else
         {
             flag1=0;
         }

     }
   else
   {
       for (i = l; i <= r; i++)
       {
          swap(a[l], a[i]);
          long N=convert();
          permute(l+1, r , ctrx, nmrx);
          swap(a[l], a[i]); //backtrack
          if(flag==1) return;
       }
   }
}

int main()
{
    int t=0,i;
    cin>>t;
    memset(prime,1,sizeof(prime));
    sieve(100000006);
  // sieve(1000);
    for(int i1=1;i1<=t;i1++)
    {
        flag=0;
        flag1=1;
        memset(gen,0,sizeof(gen));
        long n;
        cin>>n;
        cout<<"Case #"<<i1<<": ";

        generate(n);




    }
    return 0;

}
