#include <cstdio>
#include <cinttypes>
#include <vector>

using namespace std;

typedef uint64_t number;

number gcd(number x, number y) {
  while (x > 0 && y > 0) if (x > y) x %= y; else y %= x;
  return x + y;
}

number lcm(number x, number y) {
  return x / gcd(x, y) * y;
}

int main() {
#ifdef CONTEST
  freopen("agora.in", "rt", stdin);
  freopen("agora.out", "wt", stdout);
#endif
  int N;
  scanf("%d", &N);
  vector<unsigned> x(N);
  for (int i = 0; i < N; ++i) scanf("%u", &x[i]);
  vector<number> left(N), right(N);
  left[0] = 1;
  for (int i = 1; i < N; ++i) left[i] = lcm(left[i-1], x[i-1]);
  right[N-1] = 1;
  for (int i = N-2; i >= 0; --i) right[i] = lcm(right[i+1], x[i+1]);
  number best = lcm(x[0], right[0]) + 1;
  unsigned remove = 0;
  for (int i = 0; i < N; ++i) {
    number m = lcm(left[i], right[i]);
    if (m < best) best = m, remove = i;
  }
  printf("%" PRIu64 " %u\n", best, best % x[remove] == 0 ? 0 : remove+1);
}
