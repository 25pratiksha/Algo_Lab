#include<bits/stdc++.h>
using namespace std;



int num[] ={2,3,5,7,11,13,17,19,23};
int rem[9];

// code referred from https://comeoncodeon.wordpress.com/category/algorithm/

/* This function calculates (a^b)%MOD */
long long pow(int a, int b, int MOD)
{
    long long x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD; 
        b /= 2;
    }
    return x;
}
 
/*  Modular Multiplicative Inverse
    Using Euler's Theorem
    a^(phi(m)) = 1 (mod m)
    a^(-1) = a^(m-2) (mod m) */
long long InverseEuler(int n, int MOD)
{
    return pow(n,MOD-2,MOD);
}

long long C(int n, int r, int MOD)
{
    vector<long long> f(n + 1,1);
    for (int i=2; i<=n;i++)
        f[i]= (f[i-1]*i) % MOD;
    return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}

long long Lucas(int n, int m, int p)
{
    if (n==0 && m==0) return 1;
    int ni = n % p;
    int mi = m % p;
    if (mi>ni) return 0;
    return Lucas(n/p, m/p, p) * C(ni, mi, p);
}
 
 
long long findMinX()
{
    // Compute product of all numbers
    long k=9;
    long long prod = 1;
    for (long long i = 0; i < k; i++)
        prod *= num[i];
 
    // Initialize result
    long long result = 0;
 
    // Apply above formula
    for (long long i = 0; i < k; i++)
    {
        long long pp = prod / num[i];
        result += rem[i] * InverseEuler(pp, num[i]) * pp;
    }
 
    return result % prod;
} 
 
//referred code ends 



int main()
{
    int t=0,i;
    cin>>t;
    for(int i1=1;i1<=t;i1++)
    {
        long long n,m;
        cin>>n>>m;
        memset(rem,0,sizeof(rem));
        for(int i=0;i<9;i++)
        {
            rem[i]=Lucas(n,m,num[i]);
        }
        long long val=findMinX();
        cout<<"Case #"<<i1<<": "<<val<<"\n";

    }
    return 0;

}
