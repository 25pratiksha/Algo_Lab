#include<bits/stdc++.h>
using namespace std;


long long gcd(long long a, long long b)
{
    if (b == 0)
       return a;

    return gcd(b, a%b);
}

long long polygonArea(long long X[], long long Y[], long long n)
{
    // Initialze area
    long long area = 0;

    // Calculate value of shoelace formula
    long long j = n - 1;
    for (long long i = 0; i < n; i++)
    {
        area += (X[j] + X[i]) * (Y[j] - Y[i]);
        j = i;  // j is previous vertex to i
    }

    // Return absolute value
    return abs(area);
}


int main()
{
    long long t=0;
    cin>>t;
    for(long long i1=1;i1<=t;i1++)
    {
      long long area=0,A=0,n,m,a1,b;
        cin>>n>>m;
        long long x[n],y[n];
        for(long long i=0;i<n;i++)
        {
            cin>>a1>>b;
            x[i]=a1;
            y[i]=b;
        }

       long long ax[3],ay[3];

        A=polygonArea(x,y,n);
        //cout<<"bigger area"<<A<<"\n";

        for(long long i=0;i<n;i++)
        {
            ax[0] = x[i];
            ay[0] = y[i];

            if(i==0)
            {
                ax[1]=x[i+1];
                ay[1]=y[i+1];
                ax[2]=x[n-1];
                ay[2]=y[n-1];

            }
            else if(i==n-1)
            {
                ax[1]=x[0];
                ay[1]=y[0];
                ax[2]=x[i-1];
                ay[2]=y[i-1];

            }
            else
            {
                ax[1]=x[i+1];
                ay[1]=y[i+1];
                ax[2]=x[i-1];
                ay[2]=y[i-1];

            }

            long long val= polygonArea(ax,ay,3);
           // cout<<"sub area---"<<val<<"\n";
            area += val;
            //cout<<"Area now "<<area<<"\n";


        }



      // cout<<"Area now m2 "<<area<<"\n";

       A=m*m*A;

      // cout<<"new big area "<<A<<"\n";

        long long ratio = gcd(A,area);

       // cout<<"ratio "<<ratio<<"\n";
        A=A/ratio;
        area=area/ratio;

        cout<<"Case #"<<i1<<": "<<area<<"/"<<A<<"\n";
    }


    return 0;
}
