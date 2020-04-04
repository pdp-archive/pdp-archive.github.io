//https://pdp-archive.github.io/24-PDP/c-minpali-statement
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long hasht;
const long  MAXN = long(1e7);
const long  C = long(256+13); //number of characters in C++, plus something to confuse the testcases
long        N;
char 	    S[MAXN+5];

int main(){
#ifdef CONTEST
	freopen("minpali.in", "r",stdin);
	freopen("minpali.out","w",stdout);
#endif
	scanf("%ld %s",&N,S+1); //S+1 makes our string start from 1 instead of 0
	
	long maxPalindromicSuffix;
	hasht left_right = 0, right_left = 0, expC=1;
	for(long i=N;i>=1;i--){
		left_right = left_right + expC*S[i];
		right_left = right_left*C + S[i];
		expC = expC * C;
		if(left_right == right_left){
			maxPalindromicSuffix = N-i+1;
		}
	}
	printf("%ld\n",2*N-maxPalindromicSuffix);
}
