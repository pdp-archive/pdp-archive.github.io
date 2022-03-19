#undef DEBUG

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) do ; while(0)
#define NDEBUG
#endif

#include <assert.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
#ifdef CONTEST
  freopen("fishtank.in", "rt", stdin);
  freopen("fishtank.out", "wt", stdout);
#endif
  // input
  int N;
  scanf("%d", &N);
  vector<int> x(N);
  for (int i=0; i<N; i++)
    scanf("%d", &(x[i]));
  // sort
  sort(x.begin(), x.end());
  // calculate
  int i = 0, j = 0;
  int best = 0;
  while (j<N)
    if (x[j++] > 2*x[i])
      i++;
    else if (best < j-i)
      best = j-i;
  // output
  printf("%d\n", best);

  return 0;
}
