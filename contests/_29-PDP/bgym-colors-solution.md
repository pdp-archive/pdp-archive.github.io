---
layout: solution
codename: colors
---
## Μέτρηση διαφορετικών χρωμάτων σε διάστημα
Υπάρχουν αρκετοί τρόποι να μετρήσουμε πόσα διαφορετικά χρώματα εμφανίζονται σε ένα διάστημα μήκους $$L$$. 
 1. *Brute force.* Για κάθε στοιχείο στο $$[1, K]$$, κοιτάμε αν εμφανίζεται στο δοσμένο διάστημα. Αν εμφανίζεται τότε αυξάνουμε μία μεταβλητή. Πολυπλοκότητα: $$O(LK)$$.
 2. *Χρήση set.* Διατρέχουμε όλα τα στοιχεία και τα βάζουμε σε ένα set. Το μέγεθος του set είναι το πλήθος των διαφορετικών χρωμάτων στο διάστημα. Πολυπλοκότητα: $$O(L\log L)$$
 3. *Χρήση πίνακα.* Αφού τα στοιχεία παίρνουν τιμές σε μικρό διάστημα $$[1, Κ]$$, μπορούμε να κρατήσουμε έναν πίνακα $$\mathit{counts}$$ όπου $$\mathit{counts}[v]$$ κρατάει πόσες φορές είδαμε αυτό στοιχείο $$v$$. Το πλήθος των μη-μηδενικών στοιχείων είναι ίσο με το πλήθος των διαφορετικών χρωμάτων στο διάστημα. Πολυπλοκότητα: $$O(L + K)$$.

## Brute force λύση
Η πιο απλή λύση είναι να μετρήσουμε για κάθε δυνατό διάστημα πόσα διαφορετικά χρώματα υπάρχουν. Υπάρχουν $$N(N+1)/2 = O(N^2)$$ διαστήματα και το μέσο μήκος διαστήματος είναι $$O(N)$$.

```c++
#include <algorithm>
#include <cstdio>
#include <set>

const long MAXN = 1000000;

long A[MAXN];

long countColoursInInterval(long st, long en) {
  std::set<long> colors_set;
  for (long i = st; i <= en; ++i) {
    colors_set.insert(A[i]);
  }
  return colors_set.size();
}
    

int main() {
  FILE *fi = fopen("colors.in", "r");
  long N, K;
  fscanf(fi, "%ld %ld", &N, &K);
  
  for (long i = 0; i < N; ++i) {
    fscanf(fi, "%ld", &A[i]);
  }
  fclose(fi);
  
  long min_length = N + 1;
  for (long i = 0; i < N; ++i) {
    for (long j = i; j < N; ++j) {
      if (countColoursInInterval(i, j) == K) {
        min_length = std::min(min_length, j - i + 1);
      }
    }
  }
  
  FILE *fo = fopen("colors.out", "w");
  fprintf(fo, "%ld\n", (min_length == N + 1) ? 0 : min_length);
  fclose(fo);
  return 0;
}
```

Αντί για set μπορούμε να διατηρήσουμε έναν πίνακα και τότε η πολυπλοκότητα είναι $$O(N^3 + K)$$ και χρειάζεται μνήμη $$O(N+K)$$.

## Λύση σε $$O(N^2 +K)$$
Μπορούμε να επιταχύνουμε την παραπάνω λύση, παρατηρώντας ότι διαστήματα με την ίδια αρχή, μοιράζονται αρκετούς υπολογισμούς. Άρα για κάθε αρχή $$i$$ (υπάρχουν $$O(N)$$ τέτοιες), βρίσκουμε πόσα διαφορετικά χρώματα υπάρχουν στο $$[i, t]$$ για κάθε $$t > i$$. 

Διατηρούμε ένα set που στην αρχή είναι άδειο και προσθέτουμε τα στοιχεία $$Α[i], A[i+1], ... , A[N-1]$$, τότε το μέγεθος του συνόλου στο $$t$$-οστό βήμα είναι το πλήθος των διαφορετικών στοιχείων στο $$[i, i+t]$$.

```c++
#include <algorithm>
#include <cstdio>
#include <set>

const long MAXN = 1000000;
const long MAXK = 100000;

long A[MAXN];

int main() {
  FILE *fi = fopen("colors.in", "r");
  long N, K;
  fscanf(fi, "%ld %ld", &N, &K);
  
  for (long i = 0; i < N; ++i) {
    fscanf(fi, "%ld", &A[i]);
  }
  fclose(fi);
  
  long min_length = N + 1;
  for (long i = 0; i < N; ++i) {
    std::set<long> colors_set;
    for (long j = i; j < N; ++j) {
      colors_set.insert(A[j]);
      if (colors_set.size() == K) {
        // Βρήκαμε όλα τα διαφορετικά χρώματα.
        min_length = std::min(min_length, j - i + 1);
        break;
      }
    }
  }
  
  FILE *fo = fopen("colors.out", "w");
  fprintf(fo, "%ld\n", (min_length == N + 1) ? 0 : min_length);
  fclose(fo);
  return 0;
}
```


Αντί για set μπορούμε να διατηρήσουμε έναν πίνακα και τότε η πολυπλοκότητα είναι $$O(N^2 + K)$$ και χρειάζεται μνήμη $$O(N+K)$$.

## Λύση σε $$O(N \log N + K)$$
**Παρατήρηση:** Αν υπάρχει διάστημα μήκους $$L$$ που περιέχει όλα τα χρώματα, τότε υπάρχει διάστημα μήκους $$L'$$ που τα περιέχει όλα τα χρώματα για κάθε $$N \geq L' \geq L$$.

Επομένως μπορούμε να κάνουμε δυαδική αναζήτηση στο μήκος του διαστήματος. Για ένα συγκεκριμένο μήκος $$L$$ μπορούμε να δούμε αν υπάρχει διάστημα με όλα τα χρώματα, με το εξής τρόπο:
 1. Κρατάμε στον πίνακα $$\mathit{counts}$$ πόσες φορές εμφανίζεται κάθε χρώμα στα πρώτα $$L$$ στοιχεία και το πλήθος των διαφορετικών χρωμάτων ($$\mathit{colors}$$) που έχουν εμφανιστεί.
 2. Σε κάθε βήμα προχωράμε το παράθυρο κατά μία θέση προς τα δεξιά. Αφαιρούμε το στοιχείο $$A[i]$$ από τον πίνακα και προσθέτουμε το $$A[i + L]$$ (διορθώνοντας το $$\mathit{colors}$$.

Κάθε βήμα θέλει $$O(N)$$ χρόνο, άρα η πολυπλοκότητα είναι $$O(N \log N)$$ και η μνήμη είναι $$O(N + K)$$.

```c++
#include <algorithm>
#include <cstdio>

const long MAXN = 1000000;
const long MAXK = 100000;

long A[MAXN];
long count[MAXK + 1];

long N, K;

void clearCount() {
  for (long k = 1; k <= K; ++k) count[k] = 0;
}

// Ελέγχει αν υπάρχει διάστημα με μήκος len, που να
// περιέχει όλα τα Κ χρώματα.
bool existsIntervalWithLength(long len) {
  clearCount();
  long different_colors = 0;
  // Αρχικοποιούμε τον πίνακα count.
  for (long i = 0; i < len; ++i) {
    if (count[A[i]] == 0) ++different_colors;
    ++count[A[i]];
  }
  if (different_colors == K) return true;
  
  // Κοιτάμε για κάθε δυνατό interval [i, i + len) αν έχει
  // όλα τα χρώματα διαφορετικά.
  for (long i = 1; i + len -1 < N; ++i) {
    // Μεταφέρουμε το παράθυρο κατά μία θέση άρα αφαιρούμε το στοιχείο
    // A[i-1] και προσθέτουμε το A[i+len-1].
    --count[A[i-1]];
    if (count[A[i-1]] == 0) --different_colors;
    if (count[A[i+len-1]] == 0) ++different_colors;
    ++count[A[i+len-1]];
    if (different_colors == K) return true;
  } 
  return false;
}

int main() {
  FILE *fi = fopen("colors.in", "r");
  fscanf(fi, "%ld %ld", &N, &K);
  
  for (long i = 0; i < N; ++i) {
    fscanf(fi, "%ld", &A[i]);
  }
  fclose(fi);
  
  long lo = K, hi = N;
  while (lo < hi) {
    long mid = (lo + hi) / 2;
    if (existsIntervalWithLength(mid)) hi = mid;
    else lo = mid + 1;
  }
  
  FILE *fo = fopen("colors.out", "w");
  fprintf(fo, "%ld\n", existsIntervalWithLength(N) ? lo : 0);
  fclose(fo);
  return 0;
}
```


## Λύση σε $$O(N+K)$$
**Παρατήρηση:** Αν το διάστημα $$[i, j]$$ είναι το μικρότερο διάστημα που ξεκινάει στο $$i$$ και περιέχει όλα τα διαφορετικά χρώματα, τότε το διάστημα που ξεκινάει στο $$i+1$$ και περιέχει όλα τα διαφορετικά χρώματα πρέπει να τελειώνει σε $$j' \geq j$$.

Με αυτή την παρατήρηση ξεκινάμε για να βρούμε για κάθε αρχή $$i$$ το ελάχιστο διάστημα με όλα τα διαφορετικά χρώματα. Αν $$\mathit{counts}$$ έχει το πλήθος κάθε χρώματος στο ελάχιστο διάστημα που ξεκινάει στο $$i$$ (και τελειώνει στο $$j$$), τότε μπορούμε να βρούμε το ελάχιστο διάστημα για το $$i + 1$$, ακολουθώντας:
 1. Αφαιρούμε το χρώμα του $$A[i]$$ από το $$\mathit{counts}$$.
 2. Αν $$\mathit{counts}[A[i]] > 0$$, τότε έχει το ίδιο τέλος $$j$$.
 3. Διαφορετικά, αυξάνουμε το $$j$$ μέχρι να βρούμε το επόμενο χρώμα ίδιο με το $$A[i]$$. Στην πορεία ανανεώνουμε τον $$\mathit{counts}$$.

Αφού το $$j$$ μπορεί να αυξηθεί το πολύ $$N$$ φορές, ο αλγόριθμος έχει πολυπλοκότητα $$O(N + K)$$ και χρειάζεται μνήμη $$O(K)$$. 

```c++
#include <algorithm>
#include <cstdio>

const long MAXN = 1000000;
const long MAXK = 100000;

long A[MAXN];
long count[MAXK + 1];

int main() {
  FILE *fi = fopen("colors.in", "r");
  long N, K;
  fscanf(fi, "%ld %ld", &N, &K);
  
  for (long i = 0; i < N; ++i) {
    fscanf(fi, "%ld", &A[i]);
  }
  fclose(fi);
  
  // Βρίσκουμε το πρώτο διάστημα.
  long different_colors = 0;
  long j = 0;
  while(different_colors < K && j < N) {
    if (count[A[j]] == 0) ++different_colors;
    ++count[A[j]];
    ++j;
  }
  // Αν δεν βρήκαμε όλα τα χρώματα τότε δεν υπάρχει λύση. 
  long min_length = (different_colors != K) ? 0 : j;
  for (long i = 1; i < N; ++i) {
    --count[A[i-1]];
    if (count[A[i-1]] == 0) {
      do {
        count[A[j]]++;
        ++j;
      } while (j < N && A[j-1] != A[i-1]);
      // Δεν βρήκαμε άλλο τέτοιο χρώμα.
      if (A[j-1] != A[i-1]) break;
    }
    min_length = std::min(min_length, j - i);
  }
  
  FILE *fo = fopen("colors.out", "w");
  fprintf(fo, "%ld\n", min_length);
  fclose(fo);
  return 0;
}
```
