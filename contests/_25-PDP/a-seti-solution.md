---
layout: solution
codename: seti
---

## Επεξήγηση εκφώνησης

Μας δίνετεαι ένας πίνακας $$A$$ με $$N$$ ακεραίους και μας ζητείται να βρούμε όλες τις θέσεις $$c$$ για τις οποίες υπάρχει $$x$$ ώστε $$A[c-x] = A[c+x]$$ και $$A[c] > 2\cdot A[c-x]$$.

## Λύση 
Μπορούμε να δοκιμάσουμε για κάθε $$c$$ όλα τα δυνατά $$x$$ και να ελέγξουμε αν ισχύει η παραπάνω σχέση. 

Αφού υπάρχουν $$N$$ διαφορετικά $$c$$ και $$O(N)$$ δυνατές τιμές για τα $$x$$, ο αλγόριθμος τρέχει σε $$O(N^2)$$ χρόνο . 

```c++
#include <cstdio>

const size_t MAXN = 10000;
typedef long long ll;

long A[MAXN];
bool forms_triplet[MAXN]; // Δείχνει αν το i-οστό στοιχείο είναι μεσαία τιμή τριπλέτας.

int main() {
   long N;
   FILE *fi = fopen("seti.in", "r");
   fscanf(fi, "%ld", &N);
   for (long i = 0; i < N; ++i) {
      fscanf(fi, "%ld", &A[i]);
   }
   fclose(fi);
   
   ll total = 0; // Συνολικός αριθμός μεσαίων συχνοτήτων.
   for (long center = 0; center < N; ++center) {
      long x = 1;
      while (center - x >= 0 && center + x < N) {
         if (A[center - x] == A[center + x] && A[center - x] * 2 < A[center]) {
            ++total;
            forms_triplet[center] = true;
            break;
         }
         ++x;
      }
   }
   
   FILE *fo = fopen("seti.out", "w");
   fprintf(fo, "%lld\n", total);
   for (long i = 0; i < N; ++i) {
      if (forms_triplet[i]) {
         fprintf(fo, "%ld\n", i + 1); 
      }
   }
   fclose(fo);
   
   return 0;
}

```

**Σήμείωση:** Υπάρχει πιο αποδοτικός αλγόριθμος, αλλά είναι έξω από τα πλαίσια του διαγωνισμού. 
