#include <cstdio>

using namespace std;

#define MAXN 1000000
#define MAXK 100000

int a[MAXN], last[MAXK];

int main() {
  freopen("colors.in", "rt", stdin);
  freopen("colors.out", "wt", stdout);
  int N, K;
  scanf("%d %d", &N, &K);
  for (int i = 0; i < N; ++i) {
    int c;
    scanf("%d", &c);
    a[i] = c-1;
  }
  for (int i = 0; i < K; ++i) last[i] = -1;
  int front = 0, back = 0, seen = 0, best = MAXN+1;
  while (back < N) {
    // Advance the front index as much as necessary.
    while (front < N && seen < K) {
      if (last[a[front]] == -1) seen++;
      last[a[front]] = front;
      front++;
    }
    // Advance the back index as much as you can.
    do {
      if (seen == K && front - back < best)
        best = front - back;
      if (last[a[back]] == back) {
        last[a[back]] = -1;
        seen--;
      }
      back++;
    } while (back < front && seen == K);
  }
  printf("%d\n", best > MAXN ? 0 : best);
  return 0;
}
