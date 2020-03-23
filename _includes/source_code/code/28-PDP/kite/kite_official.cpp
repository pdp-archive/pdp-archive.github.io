#include <cstdio>
#include <vector>

using namespace std;

int main ()
{
  int N, K;
  scanf("%d %d", &N, &K);
  vector<int> a(N);
  for (int i=0; i<N; i++) scanf("%d", &(a[i]));

  int sum = 0, best = N+1;
  for (int start = 0, next = 0; start < N; sum -= a[start++]) {
    // invariant: start <= next
    // invariant: sum = \sum_{i=start}^{i<next} a[i]
    while (sum < K && next < N) sum += a[next++];
    if (sum == K) best = min(best, next-start);
  }
  if (best <= N)
    printf("%d\n", best);
  else
    printf("0\n");
  return 0;
}
