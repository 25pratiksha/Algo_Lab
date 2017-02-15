#include <bits/stdc++.h>
using namespace std;
#define repeat(i,n) for(int i=1;i<=n;i++)

// given a long string , count the number of words appearing in the string

void solve(string str)
{
    
     map<string, int> wordcount;
     map<string, int> :: iterator itr;
     stringstream stream(str);
     while(stream)
     {
         string word;
         stream >> word;
         transform(word.begin(), word.end(), word.begin(), ::tolower);
         word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
         if(wordcount.find(word)==wordcount.end() && word.compare("\0")!=0)
         {
             wordcount.insert(make_pair(word,1));
         }
         else
         {
             (wordcount.find(word)->second)++;
         }
         
     }
     
     for(itr=wordcount.begin();itr!=wordcount.end();++itr)
     {
         //cout<<"next word \n";
         cout<<itr->first<<" "<<itr->second<<"\n";
     }
}

int main() {
    string str;
    getline(cin,str);
    solve(str);
	
	return 0;
}
