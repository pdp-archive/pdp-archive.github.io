#include <cstdio>
#include <vector>

using namespace std;

int main ()
{
  int N, K;
  scanf("%d %d", &N, &K);
  vector<int> a(N), s(N);
  for (int i = 0; i < N; i++) scanf("%d", &(a[i]));
  int best = 0;
  for (int i = 0; i <= N-K; i++) {
    int s1 = 0;
    for (int k = 0; k < K; k++) s1 += a[i+k];
    for (int j = i+K; j <= N-K; j++) {
      int s2 = 0;
      for (int k = 0; k < K; k++) s2 += a[j+k];
      if (best < s1+s2) best = s1+s2;
    }
  }
  printf("%d\n", best);
  return 0;
}
