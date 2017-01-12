#include<bits/stdc++.h>
using namespace std;
#define SIZE 205

using namespace std;

 
struct node
{
	int x, y, dist,hop;
 
	void set(int x, int y, int dist,int hop)
	{
		this->x = x;
		this->y = y;
		this->dist = dist;
		this->hop=hop;
		
	}
}src,dest;


struct node countrr[3];

int m,n;

bool maze[SIZE][SIZE];
bool visited[SIZE][SIZE];
int px[205][205], py[205][205];
queue <struct node> q;

 
void init()
{
	int i, j;
 
	for(i = 1 ; i <= m ; i++){
		for(j = 1 ; j <= n ; j++)
		{	visited[i][j] = false;
			maze[i][j]=0;
		    px[i][j]=0;py[i][j]=0;
		    
		}
	    
	}
	
	if(!q.empty())
	{
	    while(!q.empty())
	    q.pop();
	}
			
}

bool is_allowed(int x,int y,int x1,int y1,int hop1)
{
    if(maze[x][y]) 
    {
        if(maze[x1][y1]==0 )
        {
                int xp=px[x1][y1];
                int yp= py[x1][y1];
                if( abs(x-xp)==1 && abs(y-yp)==1 )
                { 
                    return 0;
                            
                }
        }

        return 1;
    
    }
    else if (x==1 || y==1 || x==m ||y==n) {return 0;}
    
    else if(maze[x1][y1]==1 && hop1<3) {
                       
                            hop1++;
                            return 1;
                        }
    
        //cout<<hop<<"\n";}
    else return 0;
}

void Update_dist(int dist ,struct node b)
{

		px[dest.x][dest.y]=b.x;
	    py[dest.x][dest.y]=b.y;
	    dest.dist=dist;
	
}
 
int left(struct node b)
{
	int x, y, dist,hop;
 
	x = b.x - 1;
	y = b.y;
	dist = b.dist + 1;
	hop=b.hop;
	
	if(x == dest.x && y == dest.y)
	{
	    Update_dist(dist,b);    
	    return dest.dist;
	}

    
	else if(x >= 1 && is_allowed(x,y,b.x,b.y,b.hop) && !visited[x][y])
	{
	    struct node p;
	    p.set(x, y, dist,b.hop);
	    visited[x][y] = true;
		px[x][y]=b.x; py[x][y]=b.y;
		q.push(p);
	}
 
	return -1;
}
 
int right(struct node b)
{
	int x, y, dist,hop;
 
	x = b.x + 1;
	y = b.y;
	dist = b.dist + 1;
	hop=b.hop;
	
	if(x == dest.x && y == dest.y)
	{
	    Update_dist(dist,b); 
	    return dest.dist;
	}
	
	else if(x <= m && is_allowed(x,y,b.x,b.y,b.hop) && !visited[x][y])
	{
		visited[x][y] = true;
		struct node p;
		p.set(x, y, dist,b.hop);
		q.push(p);
		px[x][y]=b.x; py[x][y]=b.y;
	}
 
	return -1;
}
 
int up(struct node b)
{
	int x, y, dist;
 
	x = b.x;
	y = b.y - 1;
	dist = b.dist + 1;
	if(x == dest.x && y == dest.y)
	{
	    Update_dist(dist,b);  
	    return dest.dist;
	}
	
	else if(y >= 1 && is_allowed(x,y,b.x,b.y,b.hop) && !visited[x][y])
	{
		visited[x][y] = true;
		struct node p;
		p.set(x, y, dist,b.hop);
	//	 cout<<"Push---->"<<p.x<<p.y<<"\n";
		q.push(p);
		px[x][y]=b.x; py[x][y]=b.y;
	}
 
	return -1;
}
 
int down(struct node b)
{
	int x, y, dist;
 
	x = b.x;
	y = b.y + 1;
	dist = b.dist + 1;
	if(x == dest.x && y == dest.y)
	{
	    Update_dist(dist,b);  
	    return dest.dist;
	}

	else if(y <= n && is_allowed(x,y,b.x,b.y,b.hop) && !visited[x][y])
	{
		visited[x][y] = true;
		struct node p;
		p.set(x, y, dist,b.hop);
		q.push(p);
		px[x][y]=b.x; py[x][y]=b.y;
	}
 
	return -1;
}
 
int calculateShortestDist()
{
	struct node b;
	int val;
 
	b=src;
	px[src.x][src.y]=src.x;
	py[src.x][src.y]=src.y;
	q.push(b);
	visited[src.x][src.y] = true;
 
	while(!q.empty())
	{
	    b=q.front();
		q.pop();
		val = left(b);
		if(val != -1)
			return val;
		val = right(b);
		if(val != -1)
			return val;
		val = up(b);
		if(val != -1)
			return val;
		val = down(b);
		if(val != -1)
			return val;
		
	}
	
 
	return -1;
}


int main()
{
    int t=0;
    cin>>t;
    
    for(int i1=1;i1<=t;i1++)
    {
        int i,j;
        char ar;
        init();
	    scanf("%d %d", &n, &m);
	    for(i = 1 ; i <= m ; i++)
	    {
	    	for(j = 1 ; j <= n ; j++)
	    	{
			   cin>>ar;
			    
			    if(ar=='_')
			    {
			         maze[i][j]=1;
			    if(i==1 || i==m ||j==1 ||j==n) dest.set(i,j,9999,0);
			    }
			    else if(ar=='@')
			    {
			        maze[i][j]=0;
			    }
			    else if(ar=='*')
			    {
			        maze[i][j]=1;
			        src.set(i,j,0,0);

			    }
			    
			    
	    	}
	    }
	    
	    int val= calculateShortestDist();
	   int x1=dest.x;
	   int y1=dest.y;

	    int f=0;
	    
	 /* for(i=1;i<=m;i++)
	  {
	    for(j=1;j<=n;j++)
	    {
	        cout<<px[i][j]<<py[i][j]<<"\t";
	    }
	    cout<<"\n";
	  }*/
	//  cout<<"\n";
	  int w,g;
	  while((x1!=src.x || y1!=src.y))
	  {
	      w=px[x1][y1];
	        g=py[x1][y1];
	//   cout<<"next node-->"<<x1<<y1<<"\n";
	  
	   if(maze[x1][y1]==0)
	   {
	       countrr[f].x=x1;
	       countrr[f].y=y1;
	       f++;
	   }
	   
	   x1=px[x1][y1];
	   y1=py[x1][y1];
	  /// cout<<"w g "<<w<<g<<"\n";
        }
       // cout<<"next node-->"<<w<<g<<"\n";
        if(maze[w][g]==0)
	   {
	       countrr[f].x=x1;
	       countrr[f].y=y1;
	       f++;
	   }
        
        
	  cout<<"Case #"<<i1<<": "<<"\n";
	  int it=0;
	  for( it=0;it<f;it++ )
	  {
	      cout<<countrr[it].y<<" "<<countrr[it].x<<"\n";
	  }
	 
	  while(it<3)
	  {
	      cout<<"unused \n";
	      it++;
	  }
	  
	    
	 
    }
    
    
    
    return 0;
}