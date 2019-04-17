#include <cstdio>
#include <vector>

using namespace std;

int main ()
{
  int N, K;
  scanf("%d %d", &N, &K);
  vector<int> a(N), s(N);
  int i, j;
  for (i = 0; i < N; i++) scanf("%d", &(a[i]));
  s[0] = 0;
  for (i = 0; i < K; i++) s[0] += a[i];
  for (i = K; i < N; i++) s[i-K+1] = s[i-K] - a[i-K] + a[i];
  int best = 0, left = 0;
  for (i = 0, j = K; j <= N-K; i++, j++) {
    if (left < s[i]) left = s[i];
    if (best < left + s[j]) best = left + s[j];
  }
  printf("%d\n", best);
  return 0;
}
