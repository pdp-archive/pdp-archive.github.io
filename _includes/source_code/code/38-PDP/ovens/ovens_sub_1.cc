#include <algorithm>
#include <cstdio>

int main(){
  long N;
  scanf("%ld", &N);
  long num_switch = 0;
 
  for(long i = 0; i < N; ++i) {
    long a_i;
    scanf("%ld", a_i);
    num_switch += a_i;
  }
    
  printf("%ld\n", num_switch);
   
  return 0;
}
