#include <cstdio>
#include <map>

using namespace std;

int main ()
{
#ifdef CONTEST
  freopen("maxzero.in", "rt", stdin);
  freopen("maxzero.out", "wt", stdout);
#endif

  int N;
  scanf("%d", &N);
  map<int, int> seen;
  seen[0] = 0;
  int running=0, best=0;
  for (int i=0; i<N; i++) {
    int a;
    scanf("%d", &a);
    running += a;
    if (seen.find(running) == seen.end())
      seen[running] = i+1;
    else if (i+1-seen[running] > best)
      best = i+1-seen[running];
  }
  printf("%d\n", best);
  return 0;
}
