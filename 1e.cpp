#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t,n=1;
    scanf("%lld", &t);
    char str[1009];
    long long a[1000];
    while(t)
    {
        long long count=0,p=0;
        long long y=0;
        cin>>str;
        memset(a,0,sizeof(a));
long long b=0;
long long val=0;
     while(str[b]!='\0')
    {
        if((str[b]<='9' && str[b]>='0'))
        {
            val=0;
            while((str[b]!='\0') && (str[b]<='9') && (str[b]>='0'))
                {
                    val=((str[b]-'0')+(val*10));
                    b++;
                }
            a[p++]=val;
        }
        else
        b++;
     }
    y=a[count++];
        long long i1=0;
        while(i1<strlen(str))
         {
                 if(str[i1]=='p')
                 {
                   y=y+a[count++];
                   i1=i1+4;
                 }
                 else if(str[i1]=='m')
                 {
                   y=y-a[count++];
                   i1=i1+5;
                 }
                 else if((str[i1]=='t')&&(str[i1+1]=='o'))
                 {
                   y=pow(y,a[count++]);
                   i1=i1+12;
                 }
                 else if((str[i1]=='t')&&(str[i1+1]=='i'))
                 {
                   y=y*a[count++];
                   i1=i1+5;
                 }
                 else
                 i1++;
         }
        cout<<"Case #"<<n<<": "<<y<<"\n";
        n++;

        t--;
    }

    return 0;
}
