#include <bits/stdc++.h>
using namespace std;
const long MAXC = 10000000;
const char AKIRO = '#';

long P[2*MAXC+5], N;
char str[2*MAXC+5];

void CreateManacherTable() {
  long center=0, mirror, right, j;

  for ( long i=1; i<=2*N+1; ++i ) {
    mirror = center - (i-center);
    if ( mirror > 0 && (mirror - P[mirror] > center - P[center]) ) {
      P[i] = P[mirror];
    }
    else {
      //extend i
      
      //Take the above inequality and make it an equality
      right = max(mirror-center+P[center],(long)1);
      //Since right may be negative ( if i is out of range from center ),
      //we may need to set it to 1
      
      for (j=right; i+j <= 2*N+1 && i-j > 0 && str[i+j] == str[i-j]; ++j );
      --j;

      P[i] = j;
      center = i;
    }
  }
}

int main() {
#ifdef CONTEST
  freopen ("minpali.in","r",stdin);
  freopen ("minpali.out", "w", stdout );
#endif
  scanf ( "%ld %s", &N, str+1 );
  str[2*N+1] = AKIRO;
  for (long i=N; i>=1; --i ) {
    str[2*i] = str[i];
    str[2*i-1] = AKIRO;
  }

  CreateManacherTable();

  long maxPalindromicSuffix;
  for(long i=1; i<=2*N; ++i) {
    //The palindrome is centered at position i/2 (due to our stretching)
    //Its size is P[i], so it extends P[i]/2 positions to the right and P[i]/2 to the left
    //If this palindrome is a suffix, we need i/2+P[i]/2 == N
    if ( i/2 + P[i]/2 == N) {
      maxPalindromicSuffix = P[i];
      break;
    }
  }
  printf("%ld\n", 2*N-maxPalindromicSuffix);
}
