#include<bits/stdc++.h>
using namespace std;
long lenght,Food;
long grid[10009][10009];
set<pair<int, int>> cord;
deque<pair<int, int>> q;
int n;
int move(int dir)
{
    int row = q.back().first;
    int col = q.back().second;
	pair<int, int> d = q.front(); 
	q.pop_front();
	cord.erase(d);
	if(dir==1)
	{
	    col++;
	}
	else if(dir ==2)
	{
	    col--;
	}
	else if(dir ==3)
	{
	    row--;
	}
	else if(dir ==4)
	{
	    row++;
	}
	if(row<0)
	{
	    row=n-1;
	}
	if(row>=n)
	{
	    row=0;
	}
	if(col<0)
	{
	    col=n-1;
	}
	if(col>=n)
	{
	    col=0;
	}
	
	if(cord.count(make_pair(row, col)))
			return -1;
	
	cord.insert(make_pair(row, col));
	q.push_back(make_pair(row, col));
	
	if(grid[row][col])
	{
	    grid[row][col]=0;
	    q.push_front(d);
	    cord.insert(d);
	}

	
	return q.size() - 1;
}

int main()
{
    int t=0;
    cin>>t;
    for(int i1=1;i1<=t;i1++)
    {
        lenght=0;
        Food=0;
        int m, cs, rs,cf,rf,wf,hf,l;
		cin >> n >> m >> cs >> rs;
		memset(grid,0,10009*10009);
		
		for (int i = 0; i < m; i++)
		{
			
			cin>>cf>>rf>>wf>>hf;

			for (int j = 0; j <hf; j++)
			{
				for (int k = 0; k <wf; k++)
				{
				    grid[rf - 1 + j][cf - 1 + k] =1;
					
				}
			}

		}
		rs--;
		cs--;
		grid[rs][cs]=0;
		cin>>l;
		string str;
		cin>>str;
	/*	if(n==1 || m==0)
		{
		    cout<<"Case #"<<i1<<": "<<l<<" "<<Food<<"\n";
		    continue;
		}*/
		
		q.push_back(make_pair(rs, cs));
		//1 --Right, 2--Left , 3---Top, 4--down
		int dir=1;
		for(int i=0;i<l;i++)
		{
		    if(str[i]=='F')
		    {
		       int val=move(dir);
		       //cout<<"val "<<val<<"\n";
		       if(val==-1)
		       {
		           break;
		       }
		       else
		       {
		           Food=val;
		       }
		       
		      // continue; 
		    }
		    else if(str[i]=='R')
		    {
		        if(dir==1)
		        {
		            dir=4;
		        }
		        else if(dir==2)
		        {
		            dir=3;
		        }
		        else if(dir==3)
		        {
		            dir=1;
		        }
		        else if(dir==4)
		        {
		            dir=2;
		        }
		        int val=move(dir);
		        //cout<<"val "<<val<<"\n";
		       if(val==-1)
		       {
		           break;
		       }
		       else
		       {
		           Food=val;
		       }
		        
		      //  continue;
		    }
		    else if(str[i]=='L')
		    {
		        if(dir==1)
		        {
		            dir=3;
		        }
		        else if(dir==2)
		        {
		            dir=4;
		        }
		        else if(dir==3)
		        {
		            dir=2;
		        }
		        else if(dir==4)
		        {
		            dir=1;
		        }
		        int val=move(dir);
		        //cout<<"val "<<val<<"\n";
		       if(val==-1)
		       {
		           break;
		       }
		       else
		       {
		           Food=val;
		       }

		       // continue;
		    }
		    lenght++;
		}
		
        //memry deallocate
        cord.clear();
        q.clear();
        
        
        
        cout<<"Case #"<<i1<<": "<<lenght<<" "<<Food<<"\n";
    }
    
    
}