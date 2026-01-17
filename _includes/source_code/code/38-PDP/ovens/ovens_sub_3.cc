#include <cstdio>

const size_t MAXN = 200'000;

bool a[MAXN];
long k[MAXN];

int main(){
  long N;
  scanf("%ld", &N);
   
  for(long i = 0; i < N; ++i) {
    int temp;
    scanf("%d", &temp);
    a[i] = temp;
  }
  for(long i = 0; i < N; ++i) {
    scanf("%ld", &k[i]);
  }
   
  long num_switch = 0; // Το πλήθος των διακοπτών που πατήσαμε.
  for (long i = 0; i < N; ++i) {
    if (a[i]) {
      a[i] = 0;
      ++num_switch;
      // Αλλάζουμε την κατάσταση των επόμενων k[i] διακοπτών.
      for (int j = i + 1; j <= i + k[i]; ++j) {
        a[j] = !a[j];
      }
    }
  }

  printf("%ld\n", num_switch);
   
  return 0;
}
