#include <bits/stdc++.h>
using namespace std;
struct trie
{
    int total_wrd;
    int pre;
    struct trie* alpha[26];
};

void init(struct trie* node)
{
    node->total_wrd=0;
    node->pre=0;
    for(int i=0;i<26;i++)

    {
        node->alpha[i]= NULL;
    }
}

void fillTrie(struct trie* node,string stri)
{

    if (stri.size()==0)
    {
        node->total_wrd = node->total_wrd+1;
        return;
        
    }

    else {
         
        node->pre = node->pre+1;
       
        char k = stri[0];
       if (node->alpha[k-'A']==NULL) 
        {
            struct trie* temp=new trie();
            init(temp);
            node->alpha[k-'A'] =temp ;
                                

            if(stri.size()>1)
                fillTrie(node->alpha[k-'A'],stri.substr(1));
            else
                fillTrie(node->alpha[k-'A'],"");

        }
        else
        {   
            if(stri.size()>1)
                fillTrie(node->alpha[k-'A'],stri.substr(1));
            else
                fillTrie(node->alpha[k-'A'],"");
        }
        }

return;
}
int count_all_prefix(struct trie* node , string prefix) 
{
    if (prefix.size()==0)
    {
        
        return node->pre;
        
    }
    else 
    {
        char k = prefix[0];
        if (node->alpha[k-'A']==NULL)
            return 0;
        else 
        {
                
                if(prefix.size()>1)
                {
                    if(node->alpha[k-'A']->pre==1)
                    {
                       return 0;
                    }
                    return count_all_prefix(node->alpha[k-'A'],prefix.substr(1));
                    
                }
                else
                {
                    return count_all_prefix(node->alpha[k-'A'],"");
                }
        }
    }
}


int main() 
{
  int t=0,n;
  cin>>t;
    for(int i1=1;i1<=t;i1++)
    {
          string a[10009];
          int count=0;
          struct trie *root=new trie();
          init(root);
          cin>>n;
         
    
            for(int i=0;i<n;i++)
            {
                  cin>>a[i];
                  for (int j=0; j<a[i].length(); ++j)
                  {
                    a[i][j]=toupper(a[i][j]);
                      
                  }
                 fillTrie(root,a[i]);
              
            }
            cout<<"Case #"<<i1<<": ";
             
             for(int i=0;i<n;i++)
            {
               //counts the prefixes
              int r=count_all_prefix(root,a[i]);
              if(r>0)
              {
                  count++;
                  
              }
               
            }
               cout<<count;
                cout<<"\n";
    
    }
  return 0;
}