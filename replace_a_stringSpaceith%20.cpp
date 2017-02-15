#include<bits/stdc++.h>
using namespace std;

//replace space in a string with %20 
void change(char *arr,int n)
{
    int spaceCount=0,newLength;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==' ')
        spaceCount++;
    }
   
    newLength=spaceCount*2 +n;
    
    int j=n-1;
    for(int i=newLength-1;i>=0;i--)
    {
        
        if(arr[j]!=' ')
        {
            arr[i]=arr[j];
        }
        else
        {
            arr[i]='0';
            arr[i-1]='2';
            arr[i-2]='%';
            i=i-2;
            
        }
        j--;
        
    }
    for(int i=0;i<newLength;i++)
    cout<<arr[i];
   
}


int main()
{
    
    char arr[100];
    gets(arr);
    int n=strlen(arr);
   
    change(arr,n);
    return 0;
}