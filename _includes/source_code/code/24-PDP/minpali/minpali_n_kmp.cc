#include <bits/stdc++.h>
using namespace std;
const long MAXC = 10000000;

long N, F[2*MAXC+5];
char T[2*MAXC+5];

void Prefix () {
  long i, j;
  F[0] = F[1] = 0;
  for ( i=2; i<=2*N; ++i ) {
    j = F[i-1];
    while ( 1 ) {
      if ( T[i] == T[j+1] ) {
	F[i] = j+1;
	break;
      }
      else if ( j==0 ) {
	F[i] = j;
	break;
      }
      else {
	j = F[j];
      }
    }
  }
}

int main () {
#ifdef CONTEST
  freopen ("minpali.in","r",stdin);
  freopen ("minpali.out", "w", stdout );
#endif
  scanf ("%ld", &N);
  scanf (" %s", T+N+1); //put the word in the second half of T
  //reverse the word
  for ( long i=1; i<=N; ++i )
    T[i] = T[2*N-i+1];
  Prefix();
  printf("%ld\n", 2*N-min(N,F[2*N]));
  return 0;
}
