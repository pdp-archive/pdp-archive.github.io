#include <algorithm>
#include <cstdio>

int main(){
  FILE *in = fopen("ovens.in", "r");
  long N;
  fscanf(in, "%ld", &N);
  long num_switch = 0;
 
  for(long i = 0; i < N; ++i) {
    fscanf(in, "%ld", &a[i]);
    num_switch += a[i];
  }
  fclose(in);
   

    
  FILE *out= fopen("ovens.out", "w");
  fprintf(out, "%ld\n", num_switch);
  fclose(out);
   
  return 0;
}
