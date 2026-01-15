#include <algorithm>
#include <cstdio>
#include <vector>

const size_t MAXN = 200'000;

long a[MAXN], k[MAXN];
bool switch_ending[MAXN];

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
  bool toggle = 0;
  for (long i = 0; i < N; ++i) {
    if ((a[i] ^ toggle) == 1) {
      a[i] = 0;
      ++num_switch;
      switch_ending[i + k[i]] = !switch_ending[i + k[i]];
      toggle = !toggle;
    }
    if (switch_ending[i]) {
      toggle = !toggle;
    }
  }

  printf("%ld\n", num_switch);
 
  return 0;
}
