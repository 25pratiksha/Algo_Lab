#include<bits/stdc++.h>
using namespace std;

long double inf=1.0/0.0;

int bellmanFord(
                    vector< list< pair<int,long double> > > adjacencyList, 
                    int vertices,
                    int startVertex,
                    vector< pair<long double, int> > & shortestDistances
               )
{
    list< pair<int,long double> >::iterator traverse;
    int i, j, k;
     
    // Initialisation
    for (i = 0; i <= vertices; ++i) {
        shortestDistances[i].first = LDBL_MAX;
        shortestDistances[i].second = -1;
    }
     
    // Setting distance to source = 0
    shortestDistances[startVertex].first = 0;
    shortestDistances[startVertex].second = 0;
     
    // The Algorithm that computes Shortest Distances
    for (int i = 1; i <= vertices-1; ++i) {    // Runs 'vertices ' times = O(|V|)
        for (int j = 1; j <= vertices; ++j) {    // Runs as many times as the edges = O(|E|)
            // The code ahead basically explores the whole of Adjcency List,
            // covering one edge once, so the runtime of the code in this 
            // block is O(|E|)
             
            traverse = adjacencyList[j].begin();
             
            while (traverse != adjacencyList[j].end()) {
                if (shortestDistances[j].first == LDBL_MAX) {
                    // Important...!
                    //traverse = traverse->next;
                    ++traverse;
                    continue;
                }
                 
                // Checking for Relaxation
                if ((*traverse).second + shortestDistances[j].first -
                                        shortestDistances[(*traverse).first].first  <0) {
                    // Relaxation
                    shortestDistances[(*traverse).first].first = (*traverse).second
                                        + shortestDistances[j].first;
                    shortestDistances[(*traverse).first].second = j;
                }
                 
                ++traverse;
            }
        }
    }
     
    // Checking for Negative Cycles
    for (j = 1; j <= vertices; ++j) {
        traverse = adjacencyList[j].begin();
         
        while (traverse != adjacencyList[j].end()) {
           long double val=(*traverse).second + shortestDistances[j].first-shortestDistances[(*traverse).first].first;
            // Checking for further relaxation
            if (val <0.000000 ) {
                // Negative Cycle found as further relaxation is possible
                return j;
            }
             
            ++traverse;
        }
    }
     
    return -1;
}

int main()
{
    int t,n,m,i,j,a,b;
    long double c;
    
    cin>>t;
    
    
    for(int i1=1;i1<=t;i1++)
    {
        cin>>n>>m;
        vector< list< pair<int,long double> > > adjacencyList(n + 1);
        //vector< list< pair<int, double> > > adjacencyList1(n + 1);
        for(i=1;i<=m;i++)
        {
            cin>>a>>b;
            scanf("%llf",&c);
           
          //  printf("%.10lf\n",c);
            adjacencyList[a].push_back(make_pair(b, log(c)));
            
        }
        
        vector< pair<long double, int> > shortestDistances(n + 1);
        int returnValue = bellmanFord(adjacencyList, n, 1, shortestDistances);
       // cout<<returnValue;
       
        if(returnValue != -1) 
        {
            
            cout<<"Case #"<<i1<<": Jackpot \n";
            continue;
        }
        
                
                
                 long double  wt= exp(shortestDistances[n].first);
                 
                 if(wt==inf)
                 {
                     cout<<"Case #"<<i1<<": impossible \n";
                 }
                  else
                  {
                    cout<<"Case #"<<i1<<": ";
                    printf("%.06llf\n",wt);
                  }
        
        
    }
    
    
    return 0;
}