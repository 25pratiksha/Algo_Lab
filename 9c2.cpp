#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h> 

using namespace std;

//code referred from http://se7so.blogspot.de/2012/12/segment-trees-and-lazy-propagation.html
int N;
#define MAX 10000010
#define inf 0x7fffffff

int arr[10000000];
int tree[100000000];
int lazy[100000000];

void build_tree(long long int node, long long int a, long long int b) {
  if (a > b) return;

  if (a == b) { 
    tree[node] = arr[a];
    return;
  }

  build_tree(node * 2, a, (a + b) / 2);
  build_tree(node * 2 + 1, 1 + (a + b) / 2, b);

  tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

void update_tree(long long int node, long long int a, long long int b, int i, int j, int value) {
  if (lazy[node] != 0) { 
    tree[node] = lazy[node];

    if (a != b) {
      lazy[node * 2] = lazy[node]; 
      lazy[node * 2 + 1] = lazy[node];
    }

    lazy[node] = 0;
  }

  if (a > b || a > j || b < i)
    return;

  if (a >= i && b <= j) { 
    tree[node] = value;

    if (a != b) { 
      lazy[node * 2] = value;
      lazy[node * 2 + 1] = value;
    }

    return;
  }

  update_tree(node * 2, a, (a + b) / 2, i, j, value);
  update_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j, value);

  tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int query_tree(long long int node, long long int a, long long int b, int i, int j) {

  if (a > b || a > j || b < i) return -inf;

  if (lazy[node] != 0) { 
    tree[node] = lazy[node]; 

    if (a != b) {
      lazy[node * 2] = lazy[node];
      lazy[node * 2 + 1] = lazy[node];
    }

    lazy[node] = 0; 
  }

  if (a >= i && b <= j)
    return tree[node];

  
  int q1 = query_tree(node * 2, a, (a + b) / 2, i, j);
  int q2 = query_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j);

  int res = max(q1, q2);

  return res;
}
//referred code ends

int main() {
  int t,c=1;
  cin>>t;
  while(c<=t){
    int n; cin>>n; // width
    int k; cin>>k; // blocks
    for(int i = 0; i < n; i++) arr[i] = 0; // initial val
    build_tree(1,0,n-1);
    memset(lazy,0,sizeof lazy);
    memset(tree,0,sizeof tree);
    cout << "Case #" << c << ": ";
    for (int i = 0; i < k; i++){
      int width,height,offset;
      cin>>width>>height>>offset;
      int m=query_tree(1,0,n-1,offset,width+offset-1); // query the max
      update_tree(1,0,n-1,offset,width+offset-1, m+height); // update the max
      cout << query_tree(1,0,n-1,0,n-1) << " ";   // now query the max to get the max height over all blocks
    }
    cout << endl;
    c++;
  }
}