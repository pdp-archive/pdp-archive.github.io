#include <cstdio>
#include <vector>

using namespace std;

int main ()
{
  int N, K;
  scanf("%d %d", &N, &K);
  vector<int> s(N+1);
  s[0] = 0;
  for (int i=1; i<=N; i++) {
    int a;
    scanf("%d", &a);
    s[i] = s[i-1] + a;
  }

  for (int len = 0; len <= N; len++)
    for (int start = 0; start + len <= N; start++)
      if (s[start+len] - s[start] == K) {
        printf("%d\n", len);
        return 0;
      }
  printf("0\n");
  return 0;
}
