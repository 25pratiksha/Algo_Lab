#include<bits/stdc++.h>
using namespace std;

int main()
{

    long t,r=1;
    scanf("%ld\n",&t);
    char str[1000],c;
    while(t)
    {
        int k;
        scanf("%d#",&k);
        gets(str);
        
        cout<<"Case #"<<r<<": ";

        for(int i=k;str[i]!='\0';i++)
        {
            cout<<str[i];
        }
        for(int i=0;i<k;i++)
        {
            cout<<str[i];
        }
        cout<<"\n";
        r++;





        t--;
    }
    return 0;
}
