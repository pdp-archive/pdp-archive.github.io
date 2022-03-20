#include <stdio.h>

#define MAXN 1000000

typedef long long int num;
num A[MAXN+1];

int main ()
{
#ifdef CONTEST
  freopen("maxksum.in", "rt", stdin);
  freopen("maxksum.out", "wt", stdout);
#endif

  int N, K, i, pmin, pmax;
  num best;

  A[0] = 0;
  scanf("%d %d", &N, &K);
  for (i=1; i<=N; i++) {
    int x;
    scanf("%d", &x);
    A[i] = A[i-1] + x;
  }        
  best = pmin = pmax = 0;
  for (i=1; i<=N; i++) {
    if (i > pmin+K) {
      pmin++;
      if (A[pmax]-A[pmin] > best)
        best = A[pmax] - A[pmin];
    }
    if (A[i] <= A[pmin])
      pmin = pmax = i;
    else if (A[i] >= A[pmax]) {
      pmax = i;
      if (A[pmax]-A[pmin] > best)
        best = A[pmax] - A[pmin];
    }
  }
  printf("%llu\n", best);
  return 0;
}
