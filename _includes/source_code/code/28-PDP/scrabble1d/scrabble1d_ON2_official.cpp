#include <cstdio>
#include <vector>

using namespace std;

int main ()
{
  int N, K;
  scanf("%d %d", &N, &K);
  vector<int> a(N+1), s(N+1);
  s[0] = 0;
  for (int i = 1; i <= N; i++) {
    int a;
    scanf("%d", &a);
    s[i] = s[i-1] + a;
  }
  int best = 0;
  for (int i = 0; i <= N-K; i++) {
    int s1 = s[i+K] - s[i];
    for (int j = i+K; j <= N-K; j++) {
      int s2 = s[j+K] - s[j];
      if (best < s1+s2) best = s1+s2;
    }
  }
  printf("%d\n", best);
  return 0;
}
