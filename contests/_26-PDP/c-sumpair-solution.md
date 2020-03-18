---
layout: solution
codename: sumpair
---

## Brute force λύση $$Ο(Ν^2Q)$$
Η πιο απλή λύση είναι για κάθε ερώτημα, να διατρέξουμε όλα τα δυνατά ζεύγη στοιχείων του πίνακα και να δούμε αν έχουν το ζητούμενο άθροισμα.

Κάθε ερώτημα παίρνει $$O(N^2)$$, άρα η πολυπλοκότητα του αλγορίθμου είναι $$O(Ν^2Q)$$ και η μνήμη είναι $$O(N)$$.

```c++
#include <cstdio>

const size_t MAXN = 1000000;

long A[MAXN];
long N, Q;

bool doesPairExist(long target) {
  for (long i = 0; i < N; ++i) {
    for (long j = i + 1; j < N; ++j) {
      if (A[i] + A[j] == target) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  FILE *fi = fopen("sumpair.in", "r");
  fscanf(fi, "%ld %ld", &N, &Q);
  for (long i = 0; i < N; ++i) {
    fscanf(fi, "%ld", &A[i]);
  }
  FILE *fo = fopen("sumpair.out", "w");
  for (long j = 0; j < Q; ++j) {
    long target;
    fscanf(fi, "%ld", &target);
    fprintf(fo, "%s\n", doesPairExist(target) ? "true" : "false");
  }
  fclose(fi);
  fclose(fo);
  return 0;
}
```

## Λύση με set $$Ο(Q N \log N)$$
Στην παραπάνω λύση ψάχνουμε για κάθε $$A[i]$$, αν υπάρχει $$A[j]$$ ώστε $$A[i] + A[j] = \mathit{target}$$. Άρα ψάχνουμε για κάθε $$A[i]$$, αν υπάρχει στοιχείο $$A[j] = \mathit{target} - A[i]$$. 

Η δομή δεδομένων set μπορεί να μας βοηθήσει να απαντήσουμε τέτοιες ερωτήσεις σε χρόνο $$O(\log N)$$, αφού πρώτα βάλουμε προσθέσουμε όλα τα στοιχεία σε χρόνο $$O(N \log N)$$.

Ένα σημείο που θέλει προσοχή είναι ότι δεν πρέπει να χρησιμοποιήσουμε το ίδιο στοιχείο δύο φορές, πχ $$15 + 15 = 30$$ στο παράδειγμα. Για να το αποφύγουμε αυτό κρατάμε ένα set από τα στοιχεία που εμφανίζονται τουλάχιστον δύο φορές.

**Σημείωση:** Αν χρησιμοποιήσουμε unordered_set τότε η μέση πολυπλοκότητα γίνεται $$O(NQ)$$.

```c++
#include <cstdio>
#include <set>

const size_t MAXN = 1000000;

std::set<long> s, has_duplicate;

long A[MAXN];
long N, Q;

bool doesPairExist(long target) {
  for (long i = 0; i < N; ++i) {
    if (2 * A[i] == target) {
      if (has_duplicate.find(A[i]) != has_duplicate.end())
        return true;
    } else {
      if (s.find(target - A[i]) != s.end()) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  FILE *fi = fopen("sumpair.in", "r");
  fscanf(fi, "%ld %ld", &N, &Q);
  for (long i = 0; i < N; ++i) {
    fscanf(fi, "%ld", &A[i]);
    if (s.find(A[i]) != s.end()) {
      has_duplicate.insert(A[i]);
    }
    s.insert(A[i]);
  }
  FILE *fo = fopen("sumpair.out", "w");
  for (long j = 0; j < Q; ++j) {
    long target;
    fscanf(fi, "%ld", &target);
    fprintf(fo, "%s\n", doesPairExist(target) ? "true" : "false");
  }
  fclose(fi);
  fclose(fo);
  return 0;
}
```

## Λύση με δύο δείκτες $$O(N \log N + Q N)$$
Η βέλτιστη λύση είναι να ταξινομήσουμε τον πίνακα και να διατηρούμε δύο δείκτες $$lo$$ και $$hi$$, ώστε $$[lo, hi]$$ να έχει όλα τα δυνατά ζεύγη που έχουν άθροισμα target.

**Παρατήρηση:** Αν $$A[\mathit{lo}] + A[\mathit{hi}] > \mathit{target}$$, τότε το στοιχείο $$A[\mathit{hi}]$$ δεν μπορεί να είναι σε κανένα ζεύγος με άθροισμα $$\mathit{target}$$. 

*Απόδειξη* Από την υπόθεση, όλα τα ζεύγη με άθροισμα target είναι στο $$[\mathit{lo}, \mathit{hi}]$$. Άρα για $$i \in [\mathit{lo}, \mathit{hi}]$$, $$A[i] + A[\mathit{hi}] \geq A[\mathit{lo}] + A[\mathit{hi}] > \mathit{target}$$. 

Αντίστοιχα, αν $$A[\mathit{lo}] + A[\mathit{hi}] < \mathit{target}$$, τότε το στοιχείο $$A[\mathit{lo}]$$ δεν μπορεί να είναι σε κανένα ζεύγος με άθροισμα $$\mathit{target}$$, γιατί $$A[\mathit{lo}] + A[i] \leq A[\mathit{lo}] + A[i] < target$$.

Αυτές οι παρατηρήσεις μας οδηγούν στον αλγόριθμο όπου αφαιρούμε είτε την αρχή είτε το τέλος από το διάστημα $$[\mathit{lo}, \mathit{hi}]$$ βάσει του $$Α[\mathit{lo}] + Α[\mathit{hi}]$$, μέχρι να βρούμε ένα καλό ζεύγος ή να είναι άδειο το διάστημα. Αφού σε κάθε επανάληψη το μήκος του διαστήματος μικραίνει κατά $$1$$, κάθε ερώτημα θέλει $$O(N)$$ χρόνο. Άρα ο αλγόριθμος έχει πολυπλοκότητα $$O(N \log N + Q N)$$ και μνήμη $$O(N)$$.

```c++
#include <algorithm>
#include <cstdio>

const size_t MAXN = 1000000;

long A[MAXN];
long N, Q;

bool doesPairExist(long target) {
  long lo = 0, hi = N - 1;
  while (lo < hi) {
    long sum = A[lo] + A[hi];
    if (sum == target) return true;
    else if (sum > target) --hi;
    else ++lo;
  }
  return false;
}

int main() {
  FILE *fi = fopen("sumpair.in", "r");
  fscanf(fi, "%ld %ld", &N, &Q);
  for (long i = 0; i < N; ++i) {
    fscanf(fi, "%ld", &A[i]);
  }
  fclose(fi);
  
  std::sort(A, A+N);
  
  FILE *fo = fopen("sumpair.out", "w");
  for (long j = 0; j < Q; ++j) {
    long target;
    fscanf(fi, "%ld", &target);
    fprintf(fo, "%s\n", doesPairExist(target) ? "true" : "false");
  }
  fclose(fo);
  return 0;
}
```
