#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    int i=1;
    const long long c=299792458;
    long long E;
    cin>>n;
    while(n--)
    {
        cin>>m;
        E= m*c*c;
        cout<<"Case #"<<i<<": "<<E<<"\n";
        i++;
    }
    
}
