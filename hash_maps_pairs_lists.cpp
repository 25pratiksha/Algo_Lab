#include <bits/stdc++.h>
using namespace std;
#define repeat(i,n) for(int i=1;i<=n;i++)

// a^3 + b^3 = c^3 + d^3

void solve()
{
    map<long, list<pair<int,int> > > result;
    int n=10;
    repeat(i,n)
    {
        repeat(j,n)
        {
            long answer= pow(i,3) + pow(j,3);
            result[answer].push_back(make_pair(i,j) );
        }
    }
    
    for(std:: map<long, list<pair<int,int> > > :: iterator i=result.begin(); i!=result.end();++i)
    {
        for(std:: list<pair<int,int> > :: iterator pair1=(i->second).begin(); pair1!= (i->second).end(); pair1++)
        {
            for(std:: list<pair<int,int> > :: iterator pair2=(i->second).begin(); pair2!= (i->second).end(); pair2++)
            {
                cout<<pair1->first<<" "<<pair1->second<<" "<<pair2->first<<" "<<pair2->second<<"\n";
            }
            
        }
        
    }
}

int main() {
    solve();
	
	return 0;
}
