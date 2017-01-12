#include <bits/stdc++.h>
using namespace std;
int max(int a, int b);

int lcs( char *X, char *Y, int m, int ns, int n )
{
   int L[m+1][n+1];
   int i, j;
  
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[ns+j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
   return L[m][n];
}
int max(int a, int b)
{
    return (a > b)? a : b;
}
int main() {
    
    int t=0;
    cin>>t;
    
    for(int i1=1;i1<=t;i1++)
    {
        char X[255],Y1[255],Y[510],temp;
        cin>>X;
        cin>>Y1;
        int m = strlen(X);
        int n = strlen(Y1);
        strcpy(Y,Y1);
        strcat(Y,Y);
        int val1,min1=INT_MIN;
        int val2,min2=INT_MIN;
        for(int i=0;i<n;i++)
        {
            val1=lcs( X, Y, m, i,n );
            if(min1<val1)
            {
                min1=val1;
            }
        }
        int i=0,j=2*n-1;
        while (i < j) {
                      temp = Y[i];
                      Y[i] = Y[j];
                      Y[j] = temp;
                      i++;
                      j--;
                   }
                   
        for(int i=0;i<n;i++)
        {
            val2=lcs( X, Y, m, i,n );
            if(min2<val2)
            {
                min2=val2;
            }
        }
        int val=max(min1, min2);
        cout<<"Case #"<<i1<<": "<<val<<"\n";
    }
	
	return 0;
}
