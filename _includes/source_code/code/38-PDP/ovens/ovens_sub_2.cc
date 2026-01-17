#include <cstdio>

const size_t MAXN = 200'000;

long k[MAXN];

int main(){
  long N;
  scanf("%ld", &N);
   
  for(long i = 0; i < N; ++i) {
    long ignore;
    scanf("%ld", &ignore);
  }
  for(long i = 0; i < N; ++i) {
    scanf("%ld", &k[i]);
  }
  
  long num_switch = 0;
  for (long i = 0; i < N; i += k[i] + 1) {
    ++num_switch;
  }
    
  printf("%ld\n", num_switch);
   
  return 0;
}

// Σημείωση: Δεν χρειάζεται να κρατήσουμε το k[].

