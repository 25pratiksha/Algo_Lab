#include<bits/stdc++.h>
#define PI 3.14159265358979323846
#define inf 0.0000000000001
using namespace std;


struct point
{
	double x;
	double y;
};


int main()
{
	int t=0;
	cin>>t;
	for(int i1=1;i1<=t;i1++)
	{
		int n;
		cin>>n;
		point node[n];
		double d1=10000000.0;double d2=10000000.0;
		for(int i=0;i<n;i++)
		{
			cin>>node[i].x>>node[i].y;
		}
		
		
		for(int i=1;i<n;i++)
		{
		    //smallest distance of first node from all the nodes
			point temp;
			temp.x=node[0].x-node[i].x;
			temp.y=node[0].y-node[i].y;
			double d=sqrt(pow(temp.x,2)+pow(temp.y,2));
			if(d<=d1)
			{
				d1=d;
			
			}
			for(int j=i+1;j<n;j++)
			{
			    // smallest distance between all the nodes
				point tmp;
				tmp.x=node[i].x-node[j].x;
				tmp.y=node[i].y-node[j].y;
				double d3=sqrt(pow(tmp.x,2)+pow(tmp.y,2));
				if(d3<=d2)
				{
					d2=d3;
					
				}
			}
		}
		if(n == 2)
			d2 = d1;
			//distance D , radius maximum possible between d1,d2
		double D=d1-(d2/2.0);
		if(D<0)
		{
			D=0.0;
		}
		
		
		///maxima we get by taking diffrenciation of difference of both the areas
		double maxima = (d1*(n-1))/n;
		
		
		double area;
		
		if((d1 + D)/2 > maxima)
		{
		        area = pow((d1 - inf),2) + pow(inf,2)*(n-1);
		}
		else
		{
		 area = pow(D,2) + pow((d1 - D),2)*(n-1);   
		}
			
	    
	    area = area*PI;
	    
		cout<<fixed<<setprecision(10)<<"";
		
		cout<<"Case #"<<i1<<": "<<area<<"\n";
	}
	
	return 0;
}
