#include<bits/stdc++.h>
using namespace std;
#define N 1000009
#define MAX 10000090
#define inf 0x7fffffff

long long arr[N];
long long tree[MAX],maxm[MAX];
long long lazy[MAX];

/**
 * Build and init tree
 */
void build_tree(long long node, long long a, long long b) {
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
 * Increment elements within range [i, j] with value 
 */

void update_tree(long long node, long long a, long long b, long long i, long long j, long long value,long long max1) {
  
  //cout<<" in update \n";
 //  cout<<"a b "<<a<<" "<<b<<" tree--"<<tree[node]<<"\n";
   long long tmp=max1+value;
    if(lazy[node] != 0) 
    { // This node needs to be updated
      tree[node] += lazy[node]; // Update it

    if(a != b)
    {
      lazy[node*2] += lazy[node]; // Mark child as lazy
        lazy[node*2+1] += lazy[node]; // Mark child as lazy
    }

      lazy[node] = 0; // Reset it
    }
  
  if(a > b || a > j || b < i) // Current segment is not within range [i, j]
    return;
    
    if(a >= i && b <= j) { // Segment is fully within range
            tree[node]=tmp;
            if(a!=b)
            {
                
                lazy[node*2]=tmp-tree[node*2];
                lazy[node*2+1]=tmp-tree[node*2+1];
                
            }
            
                maxm[node]=tree[node];
            
    
  //  cout<<"a b "<<a<<" "<<b<<" tree--"<<tree[node]<<" lazy[node]->"<<lazy[node]<<"\n";
// cout<<" lazy child--node child---"<<node<<" "<<lazy[node*2]<<lazy[node*2+1]<<"\n";
//cout<<"a-"<<a<<" b-"<<b<<" tree--"<<tree[node]<<"node--"<<node<<" lazy[node]->"<<lazy[node]<<"\n";

        return;
  }

  update_tree(node*2, a, (a+b)/2, i, j, value,max1); // Updating left child
  update_tree(1+node*2, 1+(a+b)/2, b, i, j, value,max1); // Updating right child
    
    
  maxm[node] = max(maxm[node*2], maxm[node*2+1]); // Updating root with max value
//  cout<<"a-"<<a<<" b-"<<b<<" maxm--"<<maxm[node]<<"\n";
}

/**
 * Query tree to get max element value within range [i, j]
 */
long long query_tree(long long node, long long a, long long b, long long i, long long j) {
//  cout<<" in querry ab--"<<a<<" "<<b<<"\n";
  if(a > b || a > j || b < i) return -inf; // Out of range
//cout<<"node-->"<<node<<" a->"<<a<<" b->"<<b<<" lazy[node]->"<<lazy[node]<<"tree->"<<tree[node]<<"\n";

  if(lazy[node] != 0) { // This node needs to be updated
    tree[node] += lazy[node]; // Update it
    maxm[node]=tree[node];

    if(a != b) {
      lazy[node*2] += lazy[node]; // Mark child as lazy
      lazy[node*2+1] += lazy[node]; // Mark child as lazy
    }

    lazy[node] = 0; // Reset it
  }

  if(a >= i && b <= j) // Current segment is totally within range [i, j]
    return maxm[node];

  long long q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
  long long q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

  long long res = max(q1, q2); // Return final result
  
  return res;
}

int main() {
    
    long long t=0;
    cin>>t;
    for(long long i1=1;i1<=t;i1++)
    {
        long long ans=0;
        long long n,k,w,h,p,max1=0;
        cin>>n>>k;
        memset(lazy, 0, sizeof lazy);
        memset(maxm, 0, sizeof maxm);
        
      for(long long i = 0; i < n; i++) arr[i] = 0;
    
      build_tree(1, 0, n);
      cout<<"Case #"<<i1<<": ";
      for(long long i=0;i<k;i++)
      {
          cin>>w>>h>>p;
         // cout<<"calling queery \n";
          max1=query_tree(1, 0, n, p, p+w-1) ;
         // cout<<"max --->"<<max1<<"\n";
         // cout<<"calling update \n";
          update_tree(1, 0, n,p ,p+w-1 , h,max1); 
       //   cout<<"ans --->"<<ans<<"\n";
         // ans=query_tree(1, 0, n, 0, n) ;
          cout<<maxm[1]<<" ";
          
      }
      cout<<"\n";
      
      
      
      
    //  cout<<"Case #"<<i1<<": "<<ans<<"\n";
    
      
    
    
    //  cout << query_tree(1, 0, N-1, 0, N-1) << endl; // Get max element in range [0, N-1]
    }
    return 0;
}