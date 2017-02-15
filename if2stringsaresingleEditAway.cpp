#include <bits/stdc++.h>
using namespace std;

//if 2 strings are single edit away

void singlereplace(string str1,string str2)
{
    int count=0;
    int len=str1.length();
    
    for(int i=0;i<len;i++)
    {
        if(str1[i]!=str2[i])
        count++;
        if(count >1)
        {
            cout<<"No \n";
            return;
        }
    }
    
    cout<<"Yes \n";
    
}

void singleinsert(string str1,string str2)
{
    bool flag=0;
    int i2=0;
    int len=str1.length();
    for(int i=0;i<len;)
    {
       if(str1[i]==str2[i2])
       {
           i++;
           i2++;
       }
       else
       {
           if(!flag){
           i++;
           flag=1;
           }
           else
           {
               cout<<"No \n";
               return;
           }
           
       }
    }
    
    cout<<"Yes \n";
    
}


void singleEdit()
{
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);
    
    if(str1.length()==str2.length())
    {
        singlereplace(str1,str2);
        return;
    }
    
    if(str1.length()==str2.length()+1)
    {
        singleinsert(str1,str2);
        return;
    }
    //single delete
    if(str1.length()+1==str2.length())
    {
        singleinsert(str2,str1);
        return;
    }
    
    cout<<"No \n";
    
    
    
}

int main() {
	// your code goes here
	singleEdit();
	return 0;
}
