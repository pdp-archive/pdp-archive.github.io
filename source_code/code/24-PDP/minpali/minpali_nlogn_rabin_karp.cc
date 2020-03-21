//https://pdp-archive.github.io/24-PDP/c-minpali-statement
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <map>
#include <cmath>
#include <cstring>
#include <cassert>

using namespace std;

const long 	MAXN = long(1e7);
long 		N;
char 		S[MAXN+1];
long 		C;	//factor for rabin karp poly. Has to be > number of chars

typedef unsigned long long hasht;
const hasht	MOD = hasht(1e9)+7;	//It is imperative that MOD*MOD fit hasht typedef

void readS(){//read and compress S[]
	scanf("%ld %s",&N,S);
	//compress input chars. Note: If all 256 chars were introduced, the S[i] values
	//would overflow (because we start counting from 1 instead of 0).
	//However this is not the case as there are symbols and special chars
	//line ESC,EOF,'\a','\n',\r' that cannot be part of the input string
	C = 1;
	long V[256];
	memset(V,0,sizeof(V));
	for(long i=0;i<N;++i){//compress values
		long& cv = V[long(S[i])];
		if(cv == 0)
			cv = C++;
		S[i] = cv;
	}
}

int main(){
#ifdef CONTEST
	freopen("minpali.in", "r",stdin);
	freopen("minpali.out","w",stdout);
#endif
	readS();
	
	long ans, expC=1;
	hasht left_right = 0, right_left = 0;
	for(long i=N-1;i>=0;i--){
		left_right = ( left_right + ((S[i]*expC)%MOD) ) % MOD;
		right_left = (((right_left*C)%MOD) + S[i] ) % MOD;
		expC = (expC * C) % MOD;
		if(left_right == right_left){
			//this is a palindrome with lengh = N-i
			//outside palindrome are i characters
			//so a total of i (prefix) + N-i (palindrome) + i(tail need to add)
			ans = N + i;
		}
	}
	printf("%ld\n",ans);
}
