#include <cstdio>
#include <algorithm>

using namespace std;

#if 0
#define EXPLAIN printf
#else
#define EXPLAIN(...) do {} while(0)
#endif

#define MAX 1000000
int W[MAX];

int main ()
{
#ifdef CONTEST
  freopen("elev2.in", "rt", stdin);
  freopen("elev2.out", "wt", stdout);
#endif
  // read the input
  int N, B;
  scanf("%d %d", &N, &B);
  for (int i=0; i<N; i++)
    scanf("%d", &(W[i]));
  // sort weights in ascending order
  sort(W, W+N);
  // calculate
  int l = 0, r = N-1;
  int count = 0;
  while (l <= r) {
    // the light ones go only if they fit with the heavy ones
    if (l < r && W[l] + W[r] <= B) {
      EXPLAIN("%d ", W[l]);
      l++;
    }
    // the heavy ones go anyway
    EXPLAIN("%d\n", W[r]);
    r--;
    count++;
  }
  printf("%d\n", count);
  return 0;
}
