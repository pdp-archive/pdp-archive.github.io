#include <algorithm>
#include <cstdio>

int main(){
  long N;
  scanf("%ld", &N);
  long num_switch = 0;
 
  for(long i = 0; i < N; ++i) {
    scanf("%ld", &a[i]);
    num_switch += a[i];
  }
    
  printf("%ld\n", num_switch);
   
  return 0;
}
