#include <cstdio>

const size_t MAXN = 200'000;

bool a[MAXN];
long k[MAXN];

// switch_ending[i] = Το πλήθος των διακοπτών (mod 2) 
//      που τελειώνει στην θέση i. 
bool switch_ending[MAXN];

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
  bool active_switch_mod_2 = 0; // Το πλήθος των ενεργών διακοπτών mod 2.
  for (long i = 0; i < N; ++i) {
    bool is_current_oven_on = a[i] ^ active_switch_mod_2;
    if (is_current_oven_on) { 
      // Πατάμε τον i-οστό διακόπτη.
      ++num_switch;
      // Δηλώνουμε ότι υπάρχει ένας διακόπτης που επηρεάζει τους φούρνους
      // (από το i) έως το i + k[i].
      switch_ending[i + k[i]] = !switch_ending[i + k[i]];
      // Το πλήθος των ενεργών διακοπτών αλλάζει κατά ένα
      // (άρα το υπόλοιπο με το δύο αντιστρέφεται).
      active_switch_mod_2 = !active_switch_mod_2;
    }
    // Αν υπάρχει μονό πλήθος διακοπτών που τελειώνει στο i, 
    // τότε αλλάζουμε το υπόλοιπο των ενεργών διακοπτών.
    if (switch_ending[i]) {
      active_switch_mod_2 = !active_switch_mod_2;
    }
  }

  printf("%ld\n", num_switch);
 
  return 0;
}
