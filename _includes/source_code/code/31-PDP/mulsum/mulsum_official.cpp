#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N, M;
  freopen("mulsum.in", "r", stdin);
  scanf("%d %d", &N, &M);
  vector<int> r(M);
  r[0] = 0;
  for (int i = 1; i < M; ++i) r[i] = -1;

  int sum = 0, best = 0;
  for (int i = 0; i < N; ++i) {
    int x;
    scanf("%d", &x);
    sum += x;
    int prv = r[sum % M];
    if (prv >= 0) best = max(sum-prv, best); else r[sum % M] = sum;
  }
  freopen("mulsum.out", "w", stdout);
  printf("%d\n", best);
}
