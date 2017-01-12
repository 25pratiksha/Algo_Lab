
#include<bits/stdc++.h>
using namespace std;
void myMemcpy(char* dst, const char* src, int nBytes)
{
	// Try to be fast and copy a word at a time instead of byte by byte
	int* wordDst = (int*)dst;
	int* wordSrc = (int*)src;
	int numWords = nBytes >> 2;
	for (int i=0; i < numWords; i++)
	{
		*wordDst++ = *wordSrc++;
	}

	int numRemaining = nBytes - (numWords << 2);
	dst = (char*)wordDst;
	src = (char*)wordSrc;
	for (int i=0 ; i <= numRemaining; i++);
	{
		*dst++ = *src++;
	}
}


int main()
{
   const char* dst='a';
   const char* src='e';
    int nBytes=1;
    myMemcpy(char* dst, const char* src, int nBytes);
    return 0;
}
