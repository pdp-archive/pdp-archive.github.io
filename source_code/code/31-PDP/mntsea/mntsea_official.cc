#include <cstdio>
#include <vector>

using namespace std;

int main () {
#ifdef CONTEST
  freopen("mntsea.in", "rt", stdin);
  freopen("mntsea.out", "wt", stdout);
#endif

  int N;
  scanf("%d\n", &N);
  vector<int> count(2*N+1);
  count[N+0] = 1;

  long long int result = 0;
  int parity = 0;
  for (int i = 0; i < N; ++i) {
    char c = getchar();
    if (c == 'm') ++parity; else --parity;
    result += count[N+parity];
    ++count[N+parity];
  }
  printf("%lld\n", result);
}
