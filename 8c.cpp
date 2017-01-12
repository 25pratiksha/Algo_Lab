#include <bits/stdc++.h>
using namespace std;

//snippet taken from geeks for geeks
struct Job
{
    long start, finish, profit;
};

bool Comparataor(Job s1, Job s2)
{
    return (s1.finish < s2.finish);
}

long latestNonConflict(Job arr[], long i)
{
    for (long j=i-1; j>=0; j--)
    {
        if (arr[j].finish < arr[i].start)
            return j;
    }
    return -1;
}

long findMaxProfit(Job arr[], long n)
{
    sort(arr, arr+n, Comparataor);
 
    
    long *table = new long[n];
    table[0] = arr[0].profit;
 
    
    for (long i=1; i<n; i++)
    {
        long inclProf = arr[i].profit;
        long l = latestNonConflict(arr, i);
        if (l != -1)
            inclProf += table[l];
        table[i] = max(inclProf, table[i-1]);
    }
    long result = table[n-1];
    delete[] table;
 
    return result;
}



int main() {
    
    int t=0;
    cin>>t;
    
    for(int i1=1;i1<=t;i1++)
    {
        
        long n;
        cin>>n;
        Job arr[n];
        for(long i=0;i<n;i++)
        {
            cin>>arr[i].start>>arr[i].finish>>arr[i].profit;
        }
        
        long val=findMaxProfit(arr, n);
        cout<<"Case #"<<i1<<": "<<val<<"\n";
    }
    
    return 0;
}
