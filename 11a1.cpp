#include<bits/stdc++.h>
using namespace std;




int main() {
    
    int t=0;
    cin>>t;
    for(int i1=1;i1<=t;i1++)
    {
        
        double xl,yl,xs,ys,xw1,yw1,xw2,yw2,xe,ye,cw,cs,x,y,k,dist;
        cin>>xl>>yl>>xs>>ys>>xw1>>yw1>>xw2>>yw2>>xe>>ye;
        if(xw1!=xw2)
        {
            cw=(yw2-yw1)/(xw2-xw1);
            k=yw1-cw*xw1;
            dist=(xe + (ye -k)*cw)/(1+ pow(cw,2));
            x=2*dist-xe;
            y=2*dist*cw- ye+ 2*k;
        }
        else
        {
            double tmp=xe-xw1;
            x=xw1-tmp;
            y=ye;
        }
        
        cout<<"Case #"<<i1<<": ";
        printf("%0.04lf %0.04lf \n",x,y);
        
        
        
    }

    return 0;
}
