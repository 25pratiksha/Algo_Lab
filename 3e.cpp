#include<bits/stdc++.h>
using namespace std;
#define MAX 10005

struct edge
{
    long u;
    long v;
    long weight;
    struct edge *link;
}*front = NULL;

bool cmp(struct edge q, struct edge b)
{
   if(q.weight>b.weight)
   return 1;
   else
   return 0;
}

long father[MAX]; /*Holds father of each node */
struct edge tree[100005]; /* Will contain the edges of spanning tree */
long n,m,ctr=0;   /*Denotes total number of nodes in the graph */
long wt_tree=0; /*Weight of the spanning tree */

void make_tree()
{
    struct edge tmp;
    long node1,node2,root_n1,root_n2;
    long    count=0;

    while( count < m) /*Loop till n-1 edges included in the tree*/
    {
        tmp=tree[count];
        node1=tmp.u;
        node2=tmp.v;

        

        while( node1 > 0)
        {
            root_n1=node1;
            node1=father[node1];
        }
        while( node2 >0 )
        {
            root_n2=node2;
            node2=father[node2];
        }
        
        if(root_n1!=root_n2)
        {
              
              wt_tree=wt_tree+tmp.weight;
              father[root_n2]=root_n1;
        }
        count++;
    }/*End of while*/
}/*End of make_tree()*/


int main()
{
    long t;
    long a,b,c,i,j;
    cin>>t;
    
    for(long i1=1;i1<=t;i1++)
    {
        
        ctr=0; wt_tree=0;
        long count1=0,y=0;
        memset(father,0,sizeof(father));
        cin>>n>>m;
        
        for(i=0;i<m;i++)
        {
            cin>>a>>b>>c;
            y=y+c;
            tree[i].u=a;
            tree[i].v=b;
            tree[i].weight=c;
            
        }
        sort(tree,tree+m,cmp);
        
        
        
        make_tree();
        
        count1= y - wt_tree;
        
        
        
       cout<<"Case #"<<i1<<": "<<count1<<"\n"; 
        
    }
    
    
    return 0;
}

