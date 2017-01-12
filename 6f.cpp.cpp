#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;
int noofquesmarks,nofflowers;
 int h,w;
int a1[20];
int source1,source2;
 int a2[20],a3[20];
  int a4[20],a5[20];


 char a[5][5];
 int visited[5][5];
 int flag[5][5];
  int top=0;
 int count1;
 pair<int,int> s1[20];

void insert1(int a, int b)
{
    pair<int,int> p2;
   p2.first=a;
   p2.second=b;
   //cout<<"in insert1"<< p2.first<<p2.second<<endl;
   s1[top++]=p2;

}
pair<int,int> del()
{
    pair<int,int> p1;
    p1=s1[--top];
   // cout<<"in del"<< p1.first<<p1.second<<endl;
    return p1;
}
bool open()
{
    if(top<=0)
    {
        return 1;
    }
    else
        return 0;
}
void isvalid()
{


    int y1,y2;
  int flag1=0;
  char c3= w+'0';
//cout<<"no of flowers"<<noofquesmarks2<<endl;
 for(int i=1;i<=4;i++)
     {
         for(int j=1;j<=4;j++)
         {
             flag[i][j]=0;}
     }

  int v=0;
  while(v<nofflowers){
       for(int i=1;i<=4;i++)
     {
         for(int j=1;j<=4;j++)
         {
             visited[i][j]=0;}
     }
  y1=a4[v];
  y2=a5[v];
  //cout<<y1<<" "<<y2<<endl;
  int floi=y1;
  int floj=y2;
  insert1(y1,y2);
  while(!open()){
        pair<int,int> p ;
        p=del();
        //cout<<p.first<<p.second<<endl;
        y1=p.first;
        y2=p.second;
       // cout<<"from stack"<<y1<<y2<<endl;
        if(flag[y1][y2]==1)
        {
            flag1++;
            flag[floi][floj]=1;
            break;
        }
  if((y2+1<=4)&&(a[y1][y2+1]=='*')&&(a[y1][y2]<=c3))
  {
     // cout<<"hello"<<endl;
      flag[y1][y2]=1;
      flag[floi][floj]=1;
       flag1++;
      break;

   }
   if((y2+1<=4)&&(a[y1][y2+1]!='_')&&(a[y1][y2+1]>=a[y1][y2])&&(visited[y1][y2+1]==0))
   {

        visited[y1][y2+1]=1;
      insert1(y1,y2+1);
   }
   if((y2-1>=1)&&(a[y1][y2-1]=='*')&&(a[y1][y2]<=c3))
  {
         flag[floi][floj]=1;
         flag[y1][y2]=1;
        flag1++;
      break;

   }
   if((y2-1>=1)&&(a[y1][y2-1]!='_')&&(a[y1][y2-1]>=a[y1][y2])&&(visited[y1][y2-1]==0))
   {
       visited[y1][y2-1]=1;
      insert1(y1,y2-1);
   }
   if((y1+1<=4)&&(a[y1+1][y2]=='*')&&(a[y1][y2]<=c3))
  {
      flag[floi][floj]=1;
       flag[y1][y2]=1;
      flag1++;
      break;

   }
   if((y1+1<=4)&&(a[y1+1][y2]!='_')&&(a[y1+1][y2]>=a[y1][y2])&&(visited[y1+1][y2]==0))
   {

        visited[y1+1][y2]=1;
      insert1(y1+1,y2);

   }
   if((y1-1>=1)&&(a[y1-1][y2]=='*')&&(a[y1][y2]<=c3))
  {
      flag[floi][floj]=1;
       flag[y1][y2]=1;
      flag1++;
      break;

   }
   if((y1-1>=1)&&(a[y1-1][y2]!='_')&&(a[y1-1][y2]>=a[y1][y2])&&(visited[y1-1][y2]==0))
   {
       visited[y1-1][y2]=1;
      insert1(y1-1,y2);

   }
  }
 v++;
 while(!open())
 {
     pair<int,int> p1;
     p1=del();
     /*cout<<"hello";*/
 }
}
//cout<<endl;
//cout<<flag1;
//cout<<noofquesmarks2;
if(flag1==nofflowers)
{
    count1++;
    //cout<<"noofquesmarks now"<<count1;
}

}
void gernerate_combinations(int h, int e)
{
    if(e==noofquesmarks)
     {
         int p=0;
         for(int j=0;j<noofquesmarks;j++)
         {
            /* cout<<a1[j];*/
           int x1= a2[p];
            int x2 =a3[p];
            int x=a1[j];
       char c= x+'0';
         /*   cout<<c<<endl;*/
            a[x1][x2]=c;
             p++;
         }

         isvalid();

     return;
     }

    for(int i=0;i<=h;i++)
    {

       /* cout<<"hi";*/
        a1[e]=i;

        gernerate_combinations(h,e+1);
    }
}


int main()
{

    int temp=0;
    cin>>temp;

    for(int t=1;t<=temp;t++)
   {
       noofquesmarks=0;
       nofflowers=0;
       count1=0;
       int k,k1=0;
       k=0;
       int flag4=0;

     cin>>h>>w;
           memset(a1,0,sizeof(a1));
      memset(a2,0,sizeof(a2));
       memset(a3,0,sizeof(a3));
        memset(a4,0,sizeof(a4));
         memset(a5,0,sizeof(a5));

     for(int i=1;i<=4;i++)
     {
         for(int j=1;j<=4;j++)
         {

          cin>>a[i][j];

           char c2= w+'0';
           //cout<<c2<<" ";
           //cout<<a[i][j];

          if((a[i][j]>='0')&&(a[i][j]<='9')&&(a[i][j]>c2))
          {
              //cout<<"hello";
              flag4=1;}


         if(a[i][j]=='?')
             {
                 noofquesmarks++;
                 a2[k]=i;
                 a3[k++]=j;

             }

             if((a[i][j]>='0')&&(a[i][j]<='9'))
             {
                 nofflowers++;
                 a4[k1]=i;
                 a5[k1++]=j;

             }


         }
     }
     if(flag4==1)
     {
         cout<<"Case #"<<t<<":"<<" "<<"0";
     cout<<"\n";
         continue;
     }

    //cout<<noofquesmarks<<noofquesmarks2<<endl;
   /*if(noofquesmarks==0)
     { cout<<"Case #"<<t<<":"<<" "<<"1";
     cout<<"\n";
         continue;
     }
     */
gernerate_combinations(h,0);

     cout<<"Case #"<<t<<":"<<" "<<count1;
     cout<<"\n";


   }
   return 0;

}


