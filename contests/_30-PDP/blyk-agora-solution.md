---
layout: solution
codename: agora
---

## Επεξήγηση εκφώνησης
Μας δίνονται $$N$$ θετικοί ακέραιοι που αναπαριστούν τη συχνότητα επίσκεψης των κατοίκων στην αγορά. 

Δύο άνθρωποι με συχνότητες $$x_1$$ και $$x_2$$, θα συναντηθούν τη στιγμή $$k$$ αν $$k = x_1 a_1 = x_2 a_2$$ για κάποια $$a_1$$ και $$a_2$$. Το $$k$$ θα είναι η ελάχιστη στιγμή αν είναι το ελάχιστο κοινό πολλαπλάσιο του $$x_1$$ και $$x_2$$. 

Αν είχαμε $$m$$ ανθρώπους με συχνότητες $$x_1, x_2, \ldots, x_m$$ που συναντιόνταν την στιγμή $$k$$, τότε για κάποια $$a_i$$, $$k = a_1 x_1 = \ldots = a_m x_m$$. Επομένως το $$k$$ είναι ένα κοινό πολλαπλάσιο των $$x_1, x_2, \ldots, x_m$$. Το ελάχιστο $$k$$ είναι το ελάχιστο κοινό πολλαπλάσιο. 

Για το ελάχιστο κοινό πολλαπλάσιο (lcm) και τον μέγιστο κοινό διαιρέτη (gcd), ισχούν τα εξής 

 1. $$\mathrm{lcm}(a, b) \cdot \mathrm{gcd}(a, b) = a \cdot b$$
 2. $$\mathrm{lcm}(a, b, c) = \mathrm{lcm}(\mathrm{lcm}(a, b), c)$$

Ο αλγόριθμος του Ευκλείδη μας δίνει το gcd σε χρόνο $$O(\log{a} + \log{b})$$. Επομένως, σε τέτοιο χρόνο μπορούμε να υπολογίσουμε και το lcm, δύο αριθμών χρησιμοποιώντας:

$$\mathrm{lcm}(a, b) = \frac{a \cdot b}{\mathrm{gcd}(a, b)}$$

## Brute force
Υπάρχουν $$N$$ δυνατές ομάδες από $$N-1$$ συχνότητες (μπορούμε να αφαιρέσουμε οποιονδήποτε έναν). Έχοντας τα παραπάνω, μπορούμε να υπολογίσουμε για κάθε δυνατή ομάδα το lcm σε χρόνο $$O(N\log{x_{\mathrm{max} } })$$ και να βρούμε την μικρότερη (αν όλες είναι ίσες τότε θα συναντηθούν όλοι). 

Επομένως, ο αλγόριθμος τρέχει σε χρόνο $$O(N^2 \log{x_{\mathrm{max} } })$$ και χρειάζεται μνήμη $$O(N)$$.

**Σημείωση:** Όταν χρησιμοποιούμε τον τύπο για να βρούμε το lcm από το gcd πρέπει να κάνουμε τον πολλαπλασιασμό $$a\cdot b$$ που μπορεί να είναι πολύ μεγάλος (θεωρήστε τα στοιχεία με συχνότητες $$a = b = 2^{63}$$) και να μην χωράει σε $$64$$-bit. Για να αποφύγουμε αυτό όταν βρούμε το gcd, διαιρούμε τον έναν από τους δύο με το gcd και μετά πολλαπλασιάζουμε με τον άλλον. Δηλαδή, 

$$\mathrm{lcm}(a, b) = \frac{a}{\mathrm{gcd}(a, b)} \cdot b$$


```c++
#include <cstdio>

typedef unsigned long long ull;

const size_t MAXN = 1000000;

long N;

ull x[MAXN + 1];

ull gcd(ull a, ull b) {
   while (a != 0) {
      ull tmp = a;
      a = b % a;
      b = tmp;
   }
   return b;
}

ull lcm(ull a, ull b) {
   ull g = gcd(a, b);
   return (a/g) * b;
}

ull lcmWithout(long idx) {
   ull temp = 1;
   for (long i = 1; i <= N; ++i) {
      if (i == idx) continue;
      temp = lcm(temp, x[i]);
   }
   return temp;
}

int main() { 
   FILE *fi = fopen("agora.in", "r");
   fscanf(fi, "%ld", &N);
   for (long i = 1; i <= N; ++i) {
      fscanf(fi, "%llu", &x[i]);
   }
   fclose(fi);
   
   ull best_value = lcmWithout(0);
   long best_idx = 0;
   for (long i = 1; i <= N; ++i) {
      ull candidate = lcmWithout(i);
      if (candidate < best_value) {
         best_value = candidate;
         best_idx = i;
      }
   }
   
   FILE *fo = fopen("agora.out", "w");
   fprintf(fo, "%llu %ld\n", best_value, best_idx);
   fclose(fo);
   
   return 0;
}

```

## Βέλτιστη λύση
Αν επιλέξουμε να αφήσουμε έξω τον κάτοικο $$j$$ τότε το lcm είναι 

$$\mathrm{lcm}(x_1, x_2, \ldots , x_{j-1}, x_{j+1}, \ldots, x_{N-1}, x_N)$$

Αυτό είναι ίσο με

$$\mathrm{lcm}(\mathrm{lcm}(x_1, x_2, \ldots , x_{j-1}), \mathrm{lcm}(x_{j+1}, \ldots, x_{N-1}, x_N))$$

Αν ορίσουμε $$\mathrm{lcm\_prefix}[i] = \mathrm{lcm}(x_1, \ldots , x_{i})$$ και $$\mathrm{lcm\_suffix}[i] = \mathrm{lcm}(x_{i+1}, \ldots , x_{N})$$, τότε το παραπάνω γράφετε ως

$$\mathrm{lcm}(\mathrm{lcm\_prefix}[i-1], \mathrm{lcm\_suffix}[i+1])$$

Όμως μπορούμε να προϋπολογίσουμε τον πίνακα $$\mathrm{lcm\_prefix}$$ και τον πίνακα $$\mathrm{lcm\_suffix}$$ σε χρόνο $$O(N)$$, χρησιμοποιώντας τις σχέσεις

$$\mathrm{lcm\_prefix}[i] = \mathrm{lcm}(\mathrm{lcm\_prefix}[i-1], x_i)$$, με $$\mathrm{lcm\_prefix}[0] = 1$$

$$\mathrm{lcm\_suffix}[i] = \mathrm{lcm}(\mathrm{lcm\_suffix}[i+1], x_i)$$, με $$\mathrm{lcm\_suffix}[0] = 1$$

Αυτό μας επιτρέπει να βρούμε το lcm για όλους τους κατοίκους εκτός από έναν σε σταθερό χρόνο. Επομένως, ο αλγόριθμος χρειάζεται $$O(N)$$ χρόνο και $$O(N)$$ μνήμη. 

```c++
#include <cstdio>

typedef unsigned long long ull;

const size_t MAXN = 1000000;

ull x[MAXN + 2];
ull lcm_prefix[MAXN + 2];
ull lcm_suffix[MAXN + 2];

ull gcd(ull a, ull b) {
   while (a != 0) {
      ull tmp = a;
      a = b % a;
      b = tmp;
   }
   return b;
}

ull lcm(ull a, ull b) {
   ull g = gcd(a, b);
   return (a/g) * b;
}

int main() {
   long N; 
   FILE *fi = fopen("agora.in", "r");
   fscanf(fi, "%ld", &N);
   for (long i = 1; i <= N; ++i) {
      fscanf(fi, "%llu", &x[i]);
   }
   fclose(fi);
   
   lcm_prefix[0] = 1;
   for (long i = 1; i <= N; ++i) {
      lcm_prefix[i] = lcm(lcm_prefix[i-1], x[i]);
   }
   
   lcm_suffix[N+1] = 1;
   for (long i = N; i > 0; --i) {
      lcm_suffix[i] = lcm(lcm_suffix[i+1], x[i]);
   }
   
   ull best_value = lcm_suffix[1];
   long best_idx = 0;
   for (long i = 1; i <= N; ++i) {
      ull candidate = lcm(lcm_prefix[i-1], lcm_suffix[i+1]);
      if (candidate < best_value) {
         best_value = candidate;
         best_idx = i;
      }
   }
   
   FILE *fo = fopen("agora.out", "w");
   fprintf(fo, "%llu %ld\n", best_value, best_idx);
   fclose(fo);
   
   return 0;
}

```

