#include<bits/stdc++.h>
using namespace std;
#define N 1000009
#define MAX 2097155
#define inf 0x7fffffff
#define mod 1000000007

int arr[N];
int tree[MAX];
int lazy[MAX];

/**
 * Build and init tree
 */
void build_tree(int node, int a, int b) {
    if(a > b) return; // Out of range
    
    if(a == b) { // Leaf node
            tree[node] = arr[a]; // Init value
        return;
    }
    
    build_tree(node*2, a, (a+b)/2); // Init left child
    build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
    
    tree[node] = max(tree[node*2], tree[node*2+1]); // Init root value
}

/**
 * Increment elements within range [i, j] with value value
 */

void update_tree(int node, int a, int b, int i, int j, int value) {
  
  // cout<<" in update \n";
   //cout<<"a b "<<a<<" "<<b<<"\n";
   //cout<<"lazy--"<<lazy[node]<<" node--"<<node<<"\n";
   //cout<<tree[1]<<"\n";
  /*    if(lazy[node] != 0) { // This node needs to be updated
        tree[node] =(tree[node]%mod + lazy[node]%mod)%mod; // Update it

        if(a != b) {
            lazy[node*2] =(lazy[node*2]%mod + lazy[node]%mod)%mod; // Mark child as lazy
                lazy[node*2+1] =(lazy[node*2+1]%mod+ lazy[node]%mod)%mod; // Mark child as lazy
        }

        lazy[node] = 0; // Reset it
    } */
  
    if(a > b || a > j || b < i) // Current segment is not within range [i, j]
        return;
    
    if(a >= i && b <= j) { // Segment is fully within range
            tree[node] = (tree[node]%mod +value%mod)%mod;
            
        //  cout<<"a-"<<a<<" b-"<<b<<" tree--"<<tree[node]<<"node--"<<node<<"\n";

        if(a != b) { 
            lazy[node*2] =(lazy[node*2]%mod + value%mod)%mod; 
            lazy[node*2+1] =(lazy[node*2+1]%mod+ value%mod)%mod; 
        }

            return;
    }

    update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
    update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child
    
    
//  tree[node] = max(tree[node*2], tree[node*2+1]); // Updating root with max value
    
}

/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree(int node, int a, int b, int i) {
    
    //cout<<" in querry \n";
    
    if(a > b || a > i || b < i) return -inf; // Out of range

   // cout<<"node-->"<<node<<" a->"<<a<<" b->"<<b<<" lazy[node]->"<<lazy[node]<<"tree->"<<tree[node]<<"\n";
    if(lazy[node] != 0) { // This node needs to be updated
        tree[node] = (tree[node]%mod +lazy[node]%mod)%mod; // Update it

        if(a != b) {
            lazy[node*2] =(lazy[node*2]%mod + lazy[node]%mod)%mod; // Mark child as lazy
                lazy[node*2+1] =(lazy[node*2+1]%mod+ lazy[node]%mod)%mod; // Mark child as lazy
        }

        lazy[node] = 0; // Reset it
    }

    if(a == i && b == i) // Current segment is totally within range [i, j]
        return tree[node];

    int q1 = query_tree(node*2, a, (a+b)/2, i); // Query left child
    int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i); // Query right child
    int res=0;
    if(q1!=-inf && q2!=-inf)
    {
     res = q1+q2; // Return final result
    }
    else if(q1==-inf && q2==-inf)
    {
        res=-inf;
    }
    else if(q2==-inf)
    {
        res=q1;
    }
    else if(q1==-inf)
    {
        res=q2;
    }
//  cout<<" res "<<res<<"\n";
    return res;
}
int main() {
    
    int t=0;
    cin>>t;
    for(int i1=1;i1<=t;i1++)
    {
        long ans=0;
        char c;
        long n,k,l,r,v;
        cin>>n>>k;
        memset(lazy, 0, sizeof lazy);
        
        for(int i = 0; i < n; i++) arr[i] = 0;
    
        build_tree(1, 0, n-1);
        for(int i=0;i<k;i++)
        {
            cin>>c;
            if(c=='i')
            {
                cin>>l>>r>>v;
                update_tree(1, 0, n-1, l-1, r-1, v);
                
            }
            if(c=='q')
            {
                cin>>v;
                ans = (ans%mod + query_tree(1, 0, n-1, v-1))%mod;
            }
         //   cout<<"ans --->"<<ans<<"\n";
            
            
        }
        
    /*  for(int i=0;i<pow(2,n-1)-1;i++)
        {
            cout<<tree[i]<<" ";
        }
        cout<<"\n"; */
        
        cout<<"Case #"<<i1<<": "<<ans<<"\n";
    
        
    
    
    //  cout << query_tree(1, 0, N-1, 0, N-1) << endl; // Get max element in range [0, N-1]
    }
}