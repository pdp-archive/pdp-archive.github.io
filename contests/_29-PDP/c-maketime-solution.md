---
layout: solution
codename: maketime
---

## Επεξήγηση εκφώνησης
Μας δίνεται ένας πίνακας με θέσεις $$[1, N]$$ και $$M$$ στοιχεία τοποθετημένα στις θέσεις $$D_i$$ (για $$1 \leq i \leq M$$). Θέλουμε να βρούμε το μεγαλύτερο διάστημα που να έχει το πολύ $$K$$ σημεία. 

## Brute force $$O(N^3)$$
Μπορούμε να δοκιμάσουμε όλα τα δυνατά διαστήματα που είναι $$N(N+1)/2 = O(N^2)$$ και να μετρήσουμε πόσα στοιχεία περιέχουν. Από αυτά που έχουν λιγότερα ή ίσα από $$K$$, βρίσκουμε αυτό με το μεγαλύτερο μήκος.

Αφού το μέσο μήκος είναι $$O(N)$$, ο αλγόριθμος θέλει $$O(N^3)$$ χρόνο και $$O(M)$$ μνήμη.

```c++
#include <algorithm>
#include <cstdio>

const size_t MAXM = 2000000;

long D[MAXM];

int main() {
  FILE *fi = fopen("maketime.in", "r");
  long N, M, K;
  fscanf(fi, "%ld %ld %ld", &N, &M, &K);
  
  for (long i = 0; i < M; ++i) {
    fscanf(fi, "%ld", &D[i]);
  }
  fclose(fi);
  
  long max_diff = 0;
  for (long i = 1; i <= N; ++i) {
    for (long j = i; j <= N; ++j) {
      long count = 0;
      for (long d = 0; d < M; ++d) {
        if (i <= D[d] && D[d] <= j) {
          ++count;
        }
      }
      if (count <= K) {
        max_diff = std::max(max_diff, j - i + 1);
      }
    }
  }
  
  FILE *fo = fopen("maketime.out", "w");
  fprintf(fo, "%ld\n", max_diff);
  fclose(fo);
  return 0;
}
```



## Λύση σε $$O(N^2)$$
Μπορούμε να επιταχύνουμε τον παραπάνω αλγόριθμο, χρησιμοποιώντας prefix sums. Διατηρούμε έναν πίνακα $$\mathit{counts}$$ όπου $$\mathit{counts}[i]$$ είναι το πλήθος των στοιχείων στην θέση $$i$$ και ορίζουμε $$\mathit{prefix\_sum}[i] = \sum_{x=1}^i \mathit{counts}[x]$$. Τότε το πλήθος των στοιχείων στο διάστημα $$[i, j]$$ είναι $$\mathit{prefix\_sum}[j]- \mathit{prefix\_sum}[i-1]$$.

Μπορούμε να υπολογίσουμε τον πίνακα $$\mathit{prefix\_sum}$$ ως εξής:

$$\mathit{prefix\_sum}[i] = \mathit{prefix\_sum}[i-1] + \mathit{counts}[i]$$

Η πολυπλοκότητα αυτού του αλγορίθμου είναι $$O(N^2)$$ και χρειάζεται $$O(N)$$ μνήμη.

```c++
#include <algorithm>
#include <cstdio>

const size_t MAXN = 2000000;

long counts[MAXN + 1];
long prefix_sum[MAXN + 1];

long N, M, K;

void computePrefixSum() {
  for (long i = 1; i <= N; ++i) {
    prefix_sum[i] = prefix_sum[i-1] + counts[i];
  }
}

int main() {
  FILE *fi = fopen("maketime.in", "r");
  fscanf(fi, "%ld %ld %ld", &N, &M, &K);
  
  for (long i = 0; i < M; ++i) {
    long temp;
    fscanf(fi, "%ld", &temp);
    ++counts[temp];
  }
  fclose(fi);
  
  computePrefixSum();
  
  long max_diff = 0;
  for (long i = 0; i < N; ++i) {
    for (long j = i + 1; j <= N; ++j) {
      long count_between = prefix_sum[j] - prefix_sum[i];
      if (count_between <= K) {
        max_diff = std::max(max_diff, j - i);
      }
    }
  }
  
  FILE *fo = fopen("maketime.out", "w");
  fprintf(fo, "%ld\n", max_diff);
  fclose(fo);
  return 0;
}
```


## Διαδική αναζήτηση στην απάντηση
**Παρατήρηση:** Αν υπάρχει διάστημα μεγέθους $$L$$ που να έχει το πολύ $$K$$ στοιχεία, τότε για κάθε $$L' < L$$ υπάρχει διάστημα μεγέθους $$L'$$ που να έχει το πολύ $$K$$ στοιχεία. 

Χρησιμοποιώντας αυτήν την παρατήρηση μπορούμε να κάνουμε δυαδική αναζήτηση για τον μέγιστο μέγεθος διαστήματος $$L$$ που να έχει το πολύ $$K$$ στοιχεία. Μπορούμε να ελέγξουμε αν υπάρχει τέτοιο διάστημα μετρώντας πόσα στοιχεία υπάρχουν σε κάθε διάστημα της μορφής $$[i, i+L)$$ για κάθε $$i$$, χρησιμοποιώντας τα prefix sums από την προηγούμενη λύση. 

```c++
#include <algorithm>
#include <cstdio>

const size_t MAXN = 2000000;

long counts[MAXN + 1];
long prefix_sum[MAXN + 1];

long N, M, K;

void computePrefixSum() {
  for (long i = 1; i <= N; ++i) {
    prefix_sum[i] = prefix_sum[i-1] + counts[i];
  }
}

bool doesIntervalWithLengthExist(long len) {
  for (long i = 0; i + len <= N; ++i) {
    long count_between = prefix_sum[i + len] - prefix_sum[i];
    if (count_between <= K) {
      return true;
    }
  }
  return false;
}

int main() {
  FILE *fi = fopen("maketime.in", "r");
  fscanf(fi, "%ld %ld %ld", &N, &M, &K);
  
  for (long i = 0; i < M; ++i) {
    long temp;
    fscanf(fi, "%ld", &temp);
    ++counts[temp];
  }
  fclose(fi);
  
  computePrefixSum();
  
  long lo = 0, hi = N;
  while (lo < hi) {
    long mid = (lo + hi + 1)/2;
    if (doesIntervalWithLengthExist(mid)) lo = mid;
    else hi = mid - 1;
  }
  
  FILE *fo = fopen("maketime.out", "w");
  fprintf(fo, "%ld\n", lo);
  fclose(fo);
  return 0;
}
```


## Λύση με ταξινόμηση
**Παρατήρηση:** Το μεγαλύτερο ζητούμενο διάστημα ξεκινάει αμέσως μετά από κάποιο σημείο ή στην αρχή.

*Απόδειξη.* Άμα υπήρχε κενό πριν από το διάστημα τότε θα μπορούσαμε να το συμπεριλάβουμε στο διάστημα χωρίς να αλλάξει το πλήθος των στοιχείων. Άρα θα δημιουργούσαμε ακόμα μεγαλύτερο διάστημα. 

Αντίστοιχα, το μεγαλύτερο ζητούμενο διάστημα θα ξεκινάει αμέσως πριν από κάποιο σημείο ή στο τέλος.

Χρησιμοποιώντας αυτήν την παρατήρηση μπορούμε να ταξινομήσουμε όλα τα σημεία και να δοκιμάσουμε όλα τα διαστήματα που ορίζονται από σημεία που απέχουν στον ταξινομημένο πίνακα $$K+1$$ θέσεις. Αν τα στοιχεία αυτά είναι $$A$$ και $$B$$, τότε το διάστημα $$[A+1, B-1]$$, έχει το πολύ $$Κ$$ στοιχεία. 

Ο αλγόριθμος έχει πολυπλοκότητα $$Ο(N\log N)$$ λόγω της ταξινόμησης και χρειάζεται $$O(N)$$ μνήμη.

**Σημείωση:** Προσθέτουμε τα στοιχεία $$0$$ και $$N+1$$ στον πίνακα ώστε να μην χρειάζεται να κάνουμε διαφορετικό έλεγχο για την αρχή και το τέλος. 

```c++
#include <algorithm>
#include <cstdio>

const size_t MAXM = 2000000;

long D[MAXM + 2];

int main() {
  FILE *fi = fopen("maketime.in", "r");
  long N, M, K;
  fscanf(fi, "%ld %ld %ld", &N, &M, &K);
  D[0] = 0;
  for (long i = 0; i < M; ++i) {
    fscanf(fi, "%ld", &D[i]);
  }
  D[M+1] = N+1;
  fclose(fi);
  
  std::sort(D, D + M + 2);
  
  long max_diff = 0;
  for (long i = 1; i + K <= M + 1; ++i) {
    max_diff = std::max(max_diff, D[i+K] - D[i-1] - 1);
  }
  
  FILE *fo = fopen("maketime.out", "w");
  fprintf(fo, "%ld\n", max_diff);
  fclose(fo);
  return 0;
}
```

## Λύση με δύο δείκτες
**Παρατήρηση:** Αν το μεγαλύτερο διάστημα που ξεκινάει στο $$i$$ τελειώνει στο $$j$$, τότε το μεγαλύτερο διάστημα που ξεκινάει στο $$i+1$$ τελειώνει σε $$j'>j$$.

Υπολογίζουμε τον πίνακα $$\mathit{counts}$$ όπως παραπάνω. Έπειτα για κάθε δυνατή αρχή $$i$$ βρίσκουμε το μεγαλύτερο διάστημα που ξεκινάει στο $$i$$. Για να το κάνουμε αυτό διατηρούμε το πλήθος $$\mathit{current\_count}$$ των στοιχείων που έχουμε συναντήσει καθώς και το $$j$$ για το $$i$$. Για να βρούμε την λύση για το $$i+1$$ αφαιρούμε $$\mathit{counts}[i]$$ από το $$\mathit{current\_count}$$ και αυξάνουμε το $$j$$ ώσπου να μην μπορούμε να επεκτείνουμε άλλο το διάστημα. Τότε έχουμε βρει το μεγαλύτερο διάστημα που ξεκινάει στο $$i+1$$.

Το $$j$$ μπορεί να αυξηθεί το πολύ $$N$$ φορές, επομένως η πολυπλοκότητα του αλγορίθμου είναι $$O(N)$$ και η μνήμη $$O(N)$$.

```c++
#include <algorithm>
#include <cstdio>

const size_t MAXN = 2000000;

long counts[MAXN + 1];
long prefix_sum[MAXN + 1];

long N, M, K;

void computePrefixSum() {
  for (long i = 1; i <= N; ++i) {
    prefix_sum[i] = prefix_sum[i-1] + counts[i];
  }
}

int main() {
  FILE *fi = fopen("maketime.in", "r");
  fscanf(fi, "%ld %ld %ld", &N, &M, &K);
  
  for (long i = 0; i < M; ++i) {
    long temp;
    fscanf(fi, "%ld", &temp);
    ++counts[temp];
  }
  fclose(fi);
  
  computePrefixSum();
  
  long max_diff = 0;
  long current_count = 0;
  long j = 1;
  for (long i = 1; i <= N; ++i) {
    current_count -= counts[i-1];
    while (j <= N && current_count + counts[j] <= K) {
      current_count += counts[j];
      ++j;
    }
    max_diff = std::max(max_diff, j - i);
  }
  
  FILE *fo = fopen("maketime.out", "w");
  fprintf(fo, "%ld\n", max_diff);
  fclose(fo);
  return 0;
}
```
