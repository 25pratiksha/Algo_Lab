#include<bits/stdc++.h>
using namespace std;

//permutations of  a string O(n*n!)

void swap(char *a,char *b)
{
    
    char tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
   
}

void permute(char *arr,int left,int right)
{
    
    if(left==right)
    {
        cout<<arr<<"\n";
        return;
    }
    else
    {
        for(int i=left;i<=right;i++)
        {
            
            swap((arr+left),(arr+i));
            permute(arr,left+1,right);
            swap((arr+left),(arr+i));
        }
        
    }
    
}
int main()
{
    
    char arr[100];
    cin>>arr;
    int n=strlen(arr);
    permute(arr,0,n-1);
    return 0;
}