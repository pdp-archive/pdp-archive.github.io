#include <cstdio>
#include <climits>
#include <vector>

using namespace std;

int main () {
#ifdef CONTEST
  freopen("skitrip.in", "rt", stdin);
  freopen("skitrip.out", "wt", stdout);
#endif

  // Read the input.
  int N;
  scanf("%d", &N);
  vector<int> x(N);
  for (int i = 0; i < N; ++i)
    scanf("%d", &x[i]);
  // Store the positions of maximum elements traversing backward.
  vector<int> r;
  r.reserve(N);
  int max = INT_MIN;
  for (int i = N-1; i >= 0; --i)
    if (x[i] > max) {
      max = x[i];
      r.push_back(i);
    }
  // Solve.
  int min = INT_MAX;
  int best = 0;
  for (int i = 0, j = r.size()-1; i < N; ++i)
    if (x[i] < min) {
      // We will only consider minimum elements traversing forward.
      min = x[i];
      // If we are past the corresponding maximum element, we can stop.
      while (j > 0 && x[i] <= x[r[j-1]]) --j;
      if (r[j] - i > best) best = r[j] - i;
    }
  printf("%d\n", best);
  return 0;
}
