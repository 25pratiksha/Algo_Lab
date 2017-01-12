#include<bits/stdc++.h>
using namespace std;

int main() {
	int t=0;
	cin>>t;
	for(int i1=1;i1<=t;i1++)
	{
	    bool f1=0,f2=0;
	    double x1,x2,x3,y1,y2,y3,c1,c2,o1,o2,ci1,ci2,slope1=0,slope2=0,slope3,x=0,y=0,x4=0,y4=0;
	    cin>>x1>>y1>>x2>>y2>>x3>>y3;
	    cout<<"Case #"<<i1<<": \n";
	    c1= (x1+x2+x3)/3;
	    c2=(y1+y2+y3)/3;
	    printf("%0.07lf %0.07lf \n",c1,c2);
	    if(y1!=y2)
        {
            f1=1;
            slope1= (x2-x1)/(y1-y2);

        }
        else
        {
            x=x3;
            x4=(x1+x2)/2;
        }

	    if(y3!=y2)
        {
            f2=1;
             slope2= (x2-x3)/(y3-y2);

        }
        else
        {
            x=x1;
            x4=(x2+x3)/2;
        }

        if(f1 && f2)
        {
            
            o1=(slope1*x3 - slope2*x1 +y1 - y3)/(slope1-slope2);
            o2=slope1*(o1-x3) + y3;

            ci1=((slope1*((x1+x2)/2) - slope2*((x2+x3)/2) + (y2+y3)/2 - (y1+y2)/2))/(slope1-slope2);
            ci2=slope1*(ci1 - (x1+x2)/2) + (y1+y2)/2;
        }
        else
        {
            o1=x;
            ci1=x4;
            if(f1)
            {
                //cout<<"hi";
                o2=slope1*(o1-x3) + y3;
                ci2=slope1*(ci1 - (x1+x2)/2) + (y1+y2)/2;
            }
            else
            {
                //cout<<"hey";
                o2=slope2*(o1-x1) + y1;
                ci2=slope2*(ci1 - (x3+x2)/2) + (y3+y2)/2;
            }
        }

	    printf("%0.07lf %0.07lf \n",o1,o2);
	    printf("%0.07lf %0.07lf \n",ci1,ci2);

	}


	return 0;
}
