#include <cstring>
#include <algorithm>
#include <iostream>
#include <bitset>
using namespace std;

const unsigned int MAX = 10005;

struct TrieNode {
    int v, a[30];
    bool isWord;
    TrieNode () {
        v = 0;
        isWord = false;
        memset(a, 0, sizeof(a));
    }
};

int st,l, n, r;
char str[MAX];

inline int get_TrieNode () {
    return st++;
}

void insert(TrieNode trie[], int state, int curr) {

    if (curr == l){
    	trie[state].isWord = true;
        return;
    }

    int in = str[curr] - 'a';
    if (trie[state].a[in] == 0){
        trie[state].a[in] = get_TrieNode();
    }
    insert(trie, trie[state].a[in], curr+1);
}

int solve(TrieNode trie[], int state) {
	//store the ref
    int& ans = trie[state].v;
    ans = 0;

    if(trie[state].isWord){
    	ans = 2;
    	return 3-ans;
    }

    bool flag = true;

    for (int i = 0; i < 26; i++) {
        if (trie[state].a[i]) {
        		flag = false; // not a leaf
            	ans |= solve(trie,trie[state].a[i]); // take the highest state possible using OR
        }
    }

    //Leaf TrieNode check
    if (flag){
        ans = 2;
    }
    return 3-ans;
}

int main () {
	int tc,c=1;
	cin>>tc;
	while(c<=tc){
		cin>>r>>n;
		TrieNode trie[300*MAX];
		st = 1;
		for (int i = 0; i < n; i++) {
		    cin>>str;
		    l = strlen(str);
		    insert(trie, 0, 0);
		}
		solve(trie, 0);
		cout<<"Case #"<<c<<": "<<endl;
		int ans = trie[0].v;

		//Scenario 1
		if(ans>=2){
			cout<<"victory\n";
		}else if(ans==1){
			if(r&1){
				cout<<"defeat\n";
			}else{
				cout<<"victory\n";
			}
		}else{
			cout<<"defeat\n";
		}

		//Scenario 2
		if (ans < 2)
		    cout<<"defeat\n";
		else if (ans == 2)
			if(r&1){
				cout<<"victory\n";
			}else{
				cout<<"defeat\n";
			}
		else
		    cout<<"victory\n";

		//Scenario 3
		if(ans>=2){
			cout<<"defeat\n";
		}else if(ans==1){
			if(r&1){
				cout<<"victory\n";
			}else{
				cout<<"defeat\n";
			}
		}else{
			cout<<"victory\n";
		}

		if (ans < 2)
		    cout<<"victory\n";
		else if (ans == 2)
		    if(r&1){
				cout<<"defeat\n";
			}else{
				cout<<"victory\n";
			}
		else
		    cout<<"defeat\n";

		c++;
	}
    return 0;
}