//https://pdp-archive.github.io/24-PDP/c-minpali-statement
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>

using namespace std;

const long MAXN = long(1e7);
long N, Z[2*MAXN+1];
char S[2*MAXN+1];


void fill_Z(const char *s, long *Z, long n) { 
	int L, R, k; 

	L = R = 0; 
	for(long i = 1; i < n; ++i) { 
		if(i > R){ 
			L = R = i; 
			while (R<n && s[R-L]==s[R]) R++; 
			Z[i] = R-L; 
			R--; 
		} else { 
			k = i - L; 
			if(Z[k]<R-i+1) {
				Z[i] = Z[k]; 
			} else {
				L = i; 
				while (R<n && s[R-L]==s[R]) R++; 
				Z[i] = R-L; 
				R--; 
			} 
		} 
	} 
} 

int main(){
#ifdef CONTEST
	freopen("minpali.in","r",stdin);
	freopen("minpali.out","w",stdout);
#endif
	scanf("%ld",&N);
	scanf(" %s",S+N);//read string from middle of string array
	//add reversed string in the yet unfilled first half
	for(long i=0,rev=2*N-1;i<N;i++,rev--)
		S[i] = S[rev];

	fill_Z(S,Z,2*N);
	
	long ans = 2*N-1;//worst case
	for(long i=N,k=2*N-1; i<k; ++i){
		if(Z[i] >= k-i){
			ans = k-i + 2 * (N - (k-i)) - 1;
			break;
		}
	}
	
	printf("%ld\n",ans);
	return 0;
}

