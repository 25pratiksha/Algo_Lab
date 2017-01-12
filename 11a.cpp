#include<bits/stdc++.h>
using namespace std;




int main() {
    
    int t=0;
    cin>>t;
    for(int i1=1;i1<=t;i1++)
    {
        
        double xl,yl,xs,ys,xw1,yw1,xw2,yw2,xe,ye,cw,cs,y;
        cin>>xl>>yl>>xs>>ys>>xw1>>yw1>>xw2>>yw2>>xe>>ye;
        cw=(xw1-xw2)/(yw2-yw1);
        cs=(ys-yl)/(xs-xl);
        double x= (ys-ye +cw*xe - cs*xs)/(cw-cs);
        y=cw*(x-xe) + ye;
        cout<<"Case #"<<i1<<": ";
        printf("%0.04lf %0.04lf \n",x,y);
        
        
        
    }

    return 0;
}
