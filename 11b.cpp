#include<bits/stdc++.h>
using namespace std;

//http://stackoverflow.com/questions/11716268/point-in-polygon-algorithm
 
struct Point
{
    float x,y;
};
 

 
int pnpoly(int nvert, struct Point vert[], struct Point test)
{
  int i, j;
    float c = 0;
  for (i = 0, j = nvert-1; i < nvert; j = i++) {
    if ( ((vert[i].y>test.y) != (vert[j].y>test.y)) &&
     (test.x < (vert[j].x-vert[i].x) * (test.y-vert[i].y) / (vert[j].y-vert[i].y) + vert[i].x) )
       c = !c;
  }
  return c;
}


int main() {
    
    int t=0;
    cin>>t;
    for(int i1=1;i1<=t;i1++)
    {
        Point pin;
        int n;
    float x,y;
        cin>>pin.x>>pin.y>>n;
        Point parr[n];
        int arr[n][4];
    
        for(int i=0;i<n;i++)
        {
         cin>>arr[i][0]>>arr[i][1]>>arr[i][2]>>arr[i][3];
         
        }
        int k=0,i=0;
        while(k<n)
        {
            parr[k].x=arr[i][0];
            parr[k].y=arr[i][1];
            
            k++;
            
            for(int j=0;j<n;j++)
            {
                if(arr[i][2]==arr[j][0] && arr[i][3]==arr[j][1])
                {
                    i=j;
                    break;
                }
            }
            
        }
        
        
        
        cout<<"Case #"<<i1<<": ";
        pnpoly(n,parr, pin)? cout << "jackpot \n": cout << "too bad \n";
    
    }

    return 0;
}
