#include<bits/stdc++.h>
using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
    if (a == 0)
       return b;

    return gcd(b%a, a);
}

long polygonArea(unsigned long long X[], unsigned long long Y[], int n)
{
    // Initialze area
    unsigned long long area = 0;

    // Calculate value of shoelace formula
    unsigned long long j = n - 1;
    for (unsigned long long i = 0; i < n; i++)
    {
        area += (X[j] + X[i]) * (Y[j] - Y[i]);
        j = i;  // j is previous vertex to i
    }

    // Return absolute value
    return abs(area);
}

int main()
{
    int t=0;
    cin>>t;
    for(int i1=1;i1<=t;i1++)
    {

        int n,m;
        cin>>n>>m;
	    unsigned long long x[n],y[n],tri_x[n][2],tri_y[n][2];
	    unsigned long long A=0,area=0;
	    for(int i=0;i<n;i++)
	    {
	     cin>>x[i]>>y[i];
	     x[i]=m*x[i];
	     y[i]=m*y[i];
	    }
	    A=polygonArea(x,y,n);
	    cout<<"Area--"<<A<<"\n";


    }
    return 0;

}
