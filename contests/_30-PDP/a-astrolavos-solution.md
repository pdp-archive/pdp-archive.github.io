---
layout: solution
codename: astrolavos
---


**Παρατήρηση:** Όταν γυρίζει ένα δόντι στο πρώτο τροχό, τότε γυρνάει ένα δόντι σε όλους τους άλλους τροχούς. 

Σε $$N$$ στροφές θα γυρίσουν $$M[0] \cdot N$$ δόντια στον αρχικό τροχό, άρα και σε κάθε άλλον τροχό. Το πρόβλημα μας ρωτάει πόσες στροφές κάνει ένας τροχός με $$M[K[i]]$$ δόντια. Με απλή διαίρεση η απάντηση είναι 

$$\frac{M[0] \cdot N}{M[K[i]]}$$

Κάθε διαίρεση θέλει σταθερό χρόνο, συνεπώς ο αλγόριθμος θέλει $$O(L)$$ χρόνο και $$O(L)$$ μνήμη.

**Σημείωση:** Το γινόμενο $$M[0] \cdot N$$ μπορεί να μην χωράει σε μεταβλητή long, επομένως πρέπει να χρησιμοποιήσουμε είτε long long είτε doubles. 

```c++
#include <stdio.h>

const size_t MAXL = 1000;

long M[MAXL];
long K[5];

int main() {
   long L, N; 
   FILE *fi = fopen("astrolavos.in", "r");
   fscanf(fi, "%ld", &L);
   for (long i = 0; i < L; ++i) {
      fscanf(fi, "%ld", &M[i]);
   }
   fscanf(fi, "%ld", &N);
   for (long i = 0; i < 5; ++i) {
      fscanf(fi, "%ld", &K[i]);
   }
   fclose(fi);
   
   FILE *fo = fopen("astrolavos.out", "w");
   for (long i = 0; i < 5; ++i) {
      double ans = N * double(M[0]) /double(M[K[i]-1]);
      if (i > 0) fprintf(fo, " ");
      fprintf(fo, "%.3lf", ans);
   }
   fprintf(fo, "\n");
   fclose(fo);
   return 0;
}
```
