#include <bits/stdc++.h>
using namespace std;

//if permutation of given string is a palindrome or not

void ispermute()
{
    int countOdd=0,countLen=0;
    string palin;
    getline(cin,palin);
    bool bitset[256];
    memset(bitset,0,sizeof(bitset));
    for(int i=0;i<palin.length();i++)
    {
        if(palin[i]>='a' && palin[i]<='z')
        {
            bitset[palin[i]]=!bitset[palin[i]];
           // cout<<palin[i]<<" "<<bitset[palin[i]]<<"\n";
            countLen++;
        }
        if(palin[i]>='A' && palin[i]<='Z')
        {
            bitset[palin[i]+32]=!bitset[palin[i]+32];
           // cout<<palin[i]<<" "<<bitset[palin[i]+32]<<"\n";
            countLen++;
        }
        
    }
    
    for(int i=0;i<256;i++)
    {
        if(bitset[i])
        countOdd++;
        if(countOdd>1)
        {
            cout<<"No \n";
            return;
        }
    }
    
    
    
    if((countLen%2==0 && countOdd==0)||(countLen%2==1 && countOdd==1))
    cout<<"Yes \n";
    else
    cout<<"No \n";
}

int main() {
	// your code goes here
	ispermute();
	return 0;
}
