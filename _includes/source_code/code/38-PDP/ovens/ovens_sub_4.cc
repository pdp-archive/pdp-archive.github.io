#include <cstdio>

const size_t MAXN = 200'000;

long a[MAXN];

int main(){
  long N;
  scanf("%ld", &N);
   
  for(long i = 0; i < N; ++i) {
    int temp;
    scanf("%d", &temp);
    a[i] = temp;
  }
  for(long i = 0; i < N; ++i) {
    long ignore;
    scanf("%ld", &ignore);
  }
  
  long num_switch = 0;
  bool active_switch_mod_2 = 0;
  for (long i = 0; i < N; ++i) {
    if (a[i] ^ active_switch_mod_2) {
      ++num_switch;
      active_switch_mod_2 = !active_switch_mod_2;
    }
  }
    
  printf("%ld\n", num_switch);
   
  return 0;
}

