#include <bits/stdc++.h>
using namespace std;
#define MAX 10099
int st,l, n, r;

struct Trie {
    int v, a[30];
    bool if_wrd;
    Trie () {
        v = 0;
        if_wrd = false;
        memset(a, 0, sizeof(a));
    }
};

char str[MAX];
int compute(Trie[], int ) ;
void update(Trie[], int, int);


int main () {
	int t=0;
	cin>>t;
	for(int i1=1;i1<=t;i1++){
		cin>>r>>n;
		Trie trie[300*MAX];
		st = 1;
		for (int i = 0; i < n; i++) {
		    cin>>str;
		    l = strlen(str);
		    update(trie, 0, 0);
		}
		compute(trie, 0);
		cout<<"Case #"<<i1<<": "<<"\n";
		int value = trie[0].v;

		//Scenario 1
		if(value>=2){
			cout<<"victory\n";
		}else if(value==1){
			if(r&1){
				cout<<"defeat\n";
			}else{
				cout<<"victory\n";
			}
		}else{
			cout<<"defeat\n";
		}

		//Scenario 2
		if (value < 2)
		    cout<<"defeat\n";
		else if (value == 2)
			if(r&1){
				cout<<"victory\n";
			}else{
				cout<<"defeat\n";
			}
		else
		    cout<<"victory\n";

		//Scenario 3
		if(value>=2){
			cout<<"defeat\n";
		}else if(value==1){
			if(r&1){
				cout<<"victory\n";
			}else{
				cout<<"defeat\n";
			}
		}else{
			cout<<"victory\n";
		}

		if (value < 2)
		    cout<<"victory\n";
		else if (value == 2)
		    if(r&1){
				cout<<"defeat\n";
			}else{
				cout<<"victory\n";
			}
		else
		    cout<<"defeat\n";

		
	}
    return 0;
}


void update(Trie trie[], int indx, int present) {

    if (present == l){
    	trie[indx].if_wrd = true;
        return;
    }

    int in = str[present] - 'a';
    if (trie[indx].a[in] == 0){
        trie[indx].a[in] = st++;
    }
    update(trie, trie[indx].a[in], present+1);
}

int compute(Trie trie[], int indx) {
    int& value = trie[indx].v;
    value = 0;

    if(trie[indx].if_wrd){
    	value = 2;
    	return 3-value;
    }

    bool flag = true;

    for (int i = 0; i < 26; i++) {
        if (trie[indx].a[i]) {
        		flag = false;
            	value =value| compute(trie,trie[indx].a[i]); 
        }
    }

   
    if (flag){
        value = 2;
    }
    return 3-value;
}