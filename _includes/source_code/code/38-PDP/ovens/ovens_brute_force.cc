#include <algorithm>
#include <cstdio>
#include <vector>

const size_t MAXN = 200'000;

long a[MAXN], k[MAXN];

int main(){
  long N;
  scanf("%ld", &N);
   
  for(long i = 0; i < N; ++i) {
    scanf("%ld", &a[i]);
  }
  for(long i = 0; i < N; ++i) {
    scanf("%ld", &k[i]);
  }
   
  long num_switch = 0;
  for (long i = 0; i < N; ++i) {
    if (a[i] == 1) {
      a[i] = 0;
      ++num_switch;
      for (int j = i + 1; j <= i + k[i]; ++j) {
        a[j] = 1 - a[j];
      }
    }
  }

  printf("%ld\n", num_switch);
   
  return 0;
}
