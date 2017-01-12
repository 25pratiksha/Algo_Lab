#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	char str[100];
	cin>>t;
	int i=1;
	while(t--)
	{
	    cin>>str;
	    cout<<"Case #"<<i<<": Hello "<<str<<"!\n";
	    i++;
	}
	return 0;
}
