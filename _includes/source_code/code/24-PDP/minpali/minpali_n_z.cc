//https://pdp-archive.github.io/24-PDP/c-minpali-statement
#include <bits/stdc++.h>
using namespace std;

const long MAXN = long(1e7);
long N, Z[2*MAXN+5];
char T[2*MAXN+5];

void fill_Z(const char *s, long *Z, long n) { 
	long L, R, k; 
	L = R = 1;
	Z[1] = n;
	
	for(long i = 2; i <= n; ++i) {
		long k = i-L+1;
		if(i > R || Z[k] >= R-i){ 
			L = i;
			R = max(R,i);
			while (R<=n && s[R-L+1]==s[R]) R++; 
			Z[i] = R-L; 
			R--; 
		} else { 
			Z[i] = Z[k]; 
		} 
	} 
} 

int main(){
#ifdef CONTEST
	freopen("minpali.in","r",stdin);
	freopen("minpali.out","w",stdout);
#endif
	scanf("%ld",&N);
	scanf(" %s",T+N+1);//read string from middle of string array
	//add reversed string in the yet unfilled first half
	for(long i=1;i<=N;i++)
		T[i] = T[2*N-i+1];
	fill_Z(T,Z,2*N);

	long maxPalindromicSuffix;
	for(long i=N+1; i<=2*N; ++i){
		if(Z[i] >= 2*N-i+1){
			maxPalindromicSuffix = 2*N-i+1;
			break;
		}
	}
	
	printf("%ld\n",2*N-maxPalindromicSuffix);
	return 0;
}

