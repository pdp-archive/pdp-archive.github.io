#include <cstdio>
#include <cassert>

using namespace std;

int main() {
  int subtask;
  scanf("%i", &subtask);
  assert(subtask == 1);

  int n, q;
  scanf("%i%i", &n, &q);
  
  long sol = 0;
  for (int i = 0; i < n; ++i) {
    int t;
    scanf("%i", &t);
    sol += t;
  }

  for (int i = 0; i < n-1; ++i) {
    int tmp1, tmp2, tmp3;
    scanf("%i%i%i", &tmp1, &tmp2, &tmp3);
  }

  for (int i = 0; i < q; ++i) {
    int src, dst;
    scanf("%i%i", &src, &dst);
    printf("%li\n", sol);
  }

  return 0;
}
