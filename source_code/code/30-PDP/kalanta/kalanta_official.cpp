#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  freopen("kalanta.in", "rt", stdin);
  freopen("kalanta.out", "wt", stdout);
  int N;
  scanf("%d", &N);
  vector<int> x(2*N);
  int sum = 0;
  for (int i = 0; i < N; ++i) {
    scanf("%d", &x[i]);
    x[N+i] = x[i];
    sum += x[i];
  }
  int best = sum;
  int i = 0, j = 0;
  int curr = 0;
  while (i < 2*N) {
    // invariant: curr == \sum_{k=j}^{i-1} x[k]
    if (2*curr <= sum && j < 2*N) curr += x[j++]; else curr -= x[i++];
    best = min(best, abs(curr - (sum-curr)));
  }
  printf("%d\n", best);
}
