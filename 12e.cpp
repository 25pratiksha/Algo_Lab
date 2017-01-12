#include<bits/stdc++.h>
using namespace std;

//http://www.geeksforgeeks.org/area-of-a-polygon-with-given-n-ordered-vertices/



int main() {
	int t=0;
	cin>>t;
	for(int i1=1;i1<=t;i1++)
	{
	    char wrd[1000000],s[1000000],str[256][100],ar,b,c;
	    int n,d,a;
	    cin>>n>>d>>a>>s;
	    for(int i=0;i<n;i++)
	    {
	        cin>>ar>>b>>c;
	        cin>>str[ar];
	        
	        
	    }
	    int k;
	    for(int i=0;i<d;i++)
	    {
	        strcpy(wrd,s);
	        memset(s,0,sizeof(s));
	        int len=strlen(wrd);
	         k=0;
	        for(int j=0;j<len;j++)
	        {
	          char c=wrd[j];
	 
	          if(c=='+'||c=='-')
	          {
	              s[k]=c;
	              k++;
	              continue;
	          }
	          int l=0;
	          while(str[c][l]!='\0')
	          {
	              s[k]=str[c][l];
	             // cout<<"here \n";
	              //cout<<str[c][l];
	              l++;
	              k++;
	          }
	        }
	        
	    }
	    
	//    cout<<k;
	    
	   // for(int i=0;s[i]!='\0';i++)
	    //cout<<s[i];
	    double pi=3.141592653589793;
	    double rad= (pi*a)/180,w1;
	    int w=90,mod=360;
	    double y=0,x=0;
	     cout<<"Case #"<<i1<<": \n";
	    for(int i=0;i<k;i++)
	    {
	        
	        ar=s[i];
	      // cout<<ar<<"\n";
	        if(ar=='+')
	        {

	            w=(w%mod - a%mod)%mod;
	            continue;
	        }
	        if(ar=='-')
	        {
	            w=(w%mod + a%mod)%mod;
	            continue;
	        }
	        else
	        {
	            printf("%0.07lf %0.07lf \n",x,y);
	            double w1=(pi*w)/180;
	            x=x+sin(w1);
	            y=y+cos(w1);
	        }
	    }
	    
	   printf("%0.07lf %0.07lf \n",x,y);
	   // printf("%0.07lf \n",area);

	}


	return 0;
}
