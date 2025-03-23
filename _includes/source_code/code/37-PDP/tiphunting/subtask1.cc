#include <cstdio>
#include <cassert>

using namespace std;

int main() {
  int subtask;
  scanf("%i", &subtask);
  assert(subtask == 1);

  long n, q;
  scanf("%li%li", &n, &q);
  
  long long sol = 0;
  for (long i = 0; i < n; ++i) {
    long t;
    scanf("%li", &t);
    sol += t;
  }

  for (long i = 0; i < n-1; ++i) {
    long tmp1, tmp2, tmp3;
    scanf("%li%li%li", &tmp1, &tmp2, &tmp3);
  }

  for (long i = 0; i < q; ++i) {
    long L, R;
    scanf("%li%li", &L, &R);
    printf("%lli\n", sol);
  }

  return 0;
}
