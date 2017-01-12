#include<bits/stdc++.h>
using namespace std;

//http://www.geeksforgeeks.org/area-of-a-polygon-with-given-n-ordered-vertices/

double polygonArea(double X[], double Y[], int n)
{
    // Initialze area
    double area = 0.0;
 
    // Calculate value of shoelace formula
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        area += (X[j] + X[i]) * (Y[j] - Y[i]);
        j = i;  // j is previous vertex to i
    }
 
    // Return absolute value
    return abs(area / 2.0);
}

int main() {
	int t=0;
	cin>>t;
	for(int i1=1;i1<=t;i1++)
	{
	    int n;
	    cin>>n;
	    double X[n],Y[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>X[i]>>Y[i];
	    }
	    
	    double area=polygonArea(X, Y, n);
	    cout<<"Case #"<<i1<<": ";
	    printf("%0.07lf \n",area);

	}


	return 0;
}
