---
layout: solution
codename: numbase
---

## Επεξήγηση εκφώνησης
Ο αριθμός $$Μ$$ μπορεί να γραφτεί σε μία βάση $$K$$ με όλα τα $$n$$ ψηφία του ίδια, αν υπάρχει $$x$$ ώστε

$$x + xK + xK^2 + ... + xK^{(n-1)} = M$$

Κάνουμε τις εξής παρατηρήσεις που βοηθάνε σε όλες τις λύσεις (ή την ανάλυση αυτών):

**Παρατήρηση 1:** Το μέγιστο $$n$$ γίνεται όταν η βάση είναι ελάχιστη, δηλαδή $$K=2$$. Άρα το μέγιστο $$n$$ είναι της τάξης $$\log_2(Μ)$$.

**Παρατήρηση 2:** Όλοι οι αριθμοί $$Μ$$ στη βάση $$K = Μ+1$$ χρησιμοποιούν μόνο ένα στοιχείο, άρα ικανοποιούν την συνθήκη.

## Λύση 1 (30%)
Δοκιμάζουμε όλες τις πιθανές βάσεις $$K < M$$ και δοκιμάζουμε όλα τα πιθανά ψηφία $$x < K$$ αν ικανοποιούν την παραπάνω εξίσωση.

Ο αλγόριθμος έχει πολυπλοκότητα $$Ο(Μ^2 \log M)$$ και σταθερή μνήμη.

```c++
#include <cstdio>

typedef long long ll;

ll solve(ll M) {
  for (ll k = 2; k < M; ++k) {
    for (ll x = 1; x < k; ++x) {
      ll sum = 0;
      ll power = 1;
      while (sum < M) {
        sum += x * power;
        power *= k;
      }
      if (sum == M) {
        return k;
      }
    }
  }
  return M + 1;
}

int main() {
  FILE *fi = fopen("numbase.in", "r");
  long N;
  fscanf(fi, "%ld", &N);
  FILE *fo = fopen("numbase.out", "w");
  for (long test_case = 0; test_case < N; ++test_case) {
    ll M;
    fscanf(fi, "%lld", &M);
    fprintf(fo, "%lld\n", solve(M));
  }
  fclose(fi);
  fclose(fo);
  return 0;
}
```

## Λύση 2 (50%)
Δοκιμάζουμε όλες τις πιθανές βάσεις $$K < M$$ και ελέγχουμε αν η αναπαράσταση έχει όλα τα ίδια ψηφία. 

Η αναπαράσταση ενός αριθμού μπορεί να υπολογιστεί χρησιμοποιώντας τον Ευκλείδειο αλγόριθμο διαίρεσης.

Ο αλγόριθμος έχει πολυπλοκότητα $$Ο(Μ \log M)$$ και σταθερή μνήμη.

```c++
#include <cstdio>

typedef long long ll;

bool checkRepresentationHasSingleDigit(ll M, ll k) {
  ll prev_digit = -1;
  while (M > 0) {
    ll current_digit = M % k;
    if (prev_digit != -1 && prev_digit != current_digit) {
      return false;
    }
    prev_digit = current_digit;
    M /= k;
  }
  return true;
}

ll solve(ll M) {
  for (ll k = 2; k < M; ++k) {
    if (checkRepresentationHasSingleDigit(M, k)) {
      return k;
    }
  }
  return M + 1;
}

int main() {
  FILE *fi = fopen("numbase.in", "r");
  long N;
  fscanf(fi, "%ld", &N);
  FILE *fo = fopen("numbase.out", "w");
  for (long test_case = 0; test_case < N; ++test_case) {
    ll M;
    fscanf(fi, "%lld", &M);
    fprintf(fo, "%lld\n", solve(M));
  }
  fclose(fi);
  fclose(fo);
  return 0;
}
```

## Λύση 3 (50%)
Σταθεροποιούμε τα $$x$$ και $$n$$, και ορίζουμε 
$$Μ(K) = x + xK + xK^2 + ... + xK^{(n-1)}$$.
Για μεγαλύτερο $$K$$ παίρνουμε μεγαλύτερες τιμές $$M(K)$$. Επομένως κάνουμε δυαδική αναζήτηση ψάχνοντας το $$K$$ ώστε $$M(K) = M$$. 

Ο αλγόριθμος αυτός έχει πολυπλοκότητα $$Ο(Μ (\log M)^3)$$ και σταθερή μνήμη.

**Σημείωση:** Ο λόγος που χρησιμοποιούμε το γραμμικό άθροισμα αντί τον τύπο για το άθροισμα γεωμετρικής προόδου είναι ότι ο υπολογισμός του μπορεί να κάνει εύκολα overflow.

```c++
#include <algorithm>
#include <cstdio>

typedef long long ll;

int cmpSum(ll k, ll x, ll n, ll M) {
  ll sum = 0;
  ll pw = 1;
  for (ll i = 0; i < n; ++i) {
    sum += pw * x;
    if (sum > M) return 1;
    pw *= k;
  }
  if (sum == M) return 0;
  return -1;
}

ll findOptimal(ll x, ll n, ll M) {
  ll lo = x + 1;
  ll hi = M - 1;
  while (lo < hi) {
    ll mid = (lo + hi) / 2;
    int cmp = cmpSum(mid, x, n, M);
    if (cmp == 0) return mid;
    else if (cmp == -1) lo = mid + 1;
    else hi = mid - 1;
  }
  if (cmpSum(lo, x, n, M) == 0) return lo;
  return M + 1;
}

ll smallestPowerOfTwoGreaterThan(ll M) {
  ll pw = 1;
  ll exponent = 0;
  while (pw < M) {
    pw <<= 1;
    ++exponent;
  }
  return exponent;
}

ll solve(ll M) {
  ll best_k = M + 1;
  ll max_n = smallestPowerOfTwoGreaterThan(M);
  for (ll x = 1; x < M; ++x) {
    for (ll n = max_n; n >= 1; --n) {
      best_k = std::min(findOptimal(x, n, M), best_k);
    }
  } 
  return best_k;
}

int main() {
  FILE *fi = fopen("numbase.in", "r");
  long N;
  fscanf(fi, "%ld", &N);
  FILE *fo = fopen("numbase.out", "w");
  for (long test_case = 0; test_case < N; ++test_case) {
    ll M;
    fscanf(fi, "%lld", &M);
    fprintf(fo, "%lld\n", solve(M));
  }
  fclose(fi);
  fclose(fo);
  return 0;
}
```


## Λύση 4 (100%)
Παραγοντοποιούμε την αρχική σχέση, $$x(1 + Κ + Κ^2 + ... + Κ^{(n-1)}) = M$$.
Επομένως $$x | M$$. Άρα χρειάζεται να ελέγξουμε μόνο για τους διαιρέτες του $$Μ$$ ως πιθανά ψηφία. 

**Θεώρημα:** Ένας φυσικός αριθμός $$M$$ δεν έχει πάνω από $$2\sqrt{Μ}$$ διαιρέτες.

*Απόδειξη:* Έστω $$x | M$$, τότε $$M = xy$$ για κάποιον άλλο διαιρέτη $$y$$. Θα δείξουμε ότι αν $$x \neq \sqrt{M}$$, τότε ένας διαιρέτης είναι μεγαλύτερος από $$\sqrt{M}$$ και ένας μικρότερος. 
Αν $$x > \sqrt{M}$$ και $$y > \sqrt{M}$$, τότε $$M = xy > \sqrt{M}^2 = M$$ (άτοπο). Αντίστοιχα για την περίπτωση που $$x < \sqrt{M}$$ και $$y < \sqrt{M}$$. Άρα ένας διαιρέτης είναι μεγαλύτερος από $$\sqrt{M}$$ και ένας μικρότερος.
Αυτό σημαίνει ότι κάθε διαιρέτης $$d_1 > \sqrt{M}$$ του $$M$$ αντιστοιχεί σε έναν διαιρέτη $$d_2 < \sqrt{M}$$ του $$M$$. Συνεπώς υπάρχουν το πολύ $$2 \sqrt{M} - 1$$ διαιρέτες (μετρώντας τον $$\sqrt{M}$$ το πολύ μία φορά).

Με το παραπάνω θεώρημα μπορούμε θα περιορίσουμε τους αριθμούς $$x$$ που θα ελέγξουμε και να επιταχύνουμε τη Λύση 3. Ο αλγόριθμος αυτός έχει πολυπλοκότητα $$Ο(\sqrt{Μ} (\log M)^3)$$ και σταθερή μνήμη.

```c++
#include <algorithm>
#include <cstdio>

typedef long long ll;

int cmpSum(ll k, ll x, ll n, ll M) {
  ll sum = 0;
  ll pw = 1;
  for (ll i = 0; i < n; ++i) {
    sum += pw * x;
    if (sum > M) return 1;
    pw *= k;
  }
  if (sum == M) return 0;
  return -1;
}

ll findOptimal(ll x, ll n, ll M) {
  ll lo = x + 1;
  ll hi = M - 1;
  while (lo < hi) {
    ll mid = (lo + hi) / 2;
    int cmp = cmpSum(mid, x, n, M);
    if (cmp == 0) return mid;
    else if (cmp == -1) lo = mid + 1;
    else hi = mid - 1;
  }
  if (cmpSum(lo, x, n, M) == 0) return lo;
  return M + 1;
}

ll smallestPowerOfTwoGreaterThan(ll M) {
  ll pw = 1;
  ll exponent = 0;
  while (pw < M) {
    pw <<= 1;
    ++exponent;
  }
  return exponent;
}

ll solve(ll M) {
  ll best_k = M + 1;
  ll max_n = smallestPowerOfTwoGreaterThan(M);
  for (ll n = 1; n <= max_n; ++n) {
    for (ll x = 1; x * x <= M; ++x) {
      if (M % x == 0) {
        ll other_factor = M / x;
        best_k = std::min(findOptimal(x, n, M), best_k);
        best_k = std::min(findOptimal(other_factor, n, M), best_k);
      }
    } 
  }
  return best_k;
}

int main() {
  FILE *fi = fopen("numbase.in", "r");
  long N;
  fscanf(fi, "%ld", &N);
  FILE *fo = fopen("numbase.out", "w");
  for (long test_case = 0; test_case < N; ++test_case) {
    ll M;
    fscanf(fi, "%lld", &M);
    fprintf(fo, "%lld\n", solve(M));
  }
  fclose(fi);
  fclose(fo);
  return 0;
}
```
