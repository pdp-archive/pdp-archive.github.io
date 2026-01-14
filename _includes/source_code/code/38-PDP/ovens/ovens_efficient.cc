#include <algorithm>
#include <cstdio>
#include <vector>

const size_t MAXN = 200'000;

long a[MAXN], k[MAXN];
bool switch_ending[MAXN];

int main(){
  FILE *in = fopen("ovens.in", "r");
  long N;
  fscanf(in, "%ld", &N);
   
  for(long i = 0; i < N; ++i) {
    fscanf(in, "%ld", &a[i]);
  }
  for(long i = 0; i < N; ++i) {
    fscanf(in, "%ld", &k[i]);
  }
  fclose(in);
   
  long num_switch = 0;
  bool toggle = 0;
  for (long i = 0; i < N; ++i) {
    
    if ((a[i] ^ toggle) == 1) {
      a[i] = 0;
      ++num_switch;
      switch_ending[i + k[i]] = !switch_ending[i + k[i]];
    }
    if (switch_ending[i]) {
      toggle = !toggle;
    }
  }
    
  FILE *out= fopen("ovens.out", "w");
  fprintf(out, "%ld\n", num_switch);
  fclose(out);
   
  return 0;
}
