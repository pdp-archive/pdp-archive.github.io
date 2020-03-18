---
layout: solution
codename: solar
---

## Brute force λύση

Κοιτάμε για κάθε αριθμό $$A[i]$$ αν ικανοποιεί τις συνθήκες:
 1. Όλοι οι προηγούμενοι αριθμοί είναι μικρότεροι από $$A[i]$$.
 2. Όλοι οι επόμενοι αριθμοί είναι μεγαλύτεροι από $$A[i]$$.

Για να ελέγξουμε τη συνθήκη 1), διατρέχουμε τις τιμές $$Α[0], ... , A[i-1]$$ και κοιτάμε αν όλες είναι μικρότερες από $$A[i]$$. Για να ελέγξουμε τη συνθήκη 2), διατρέχουμε τις τιμές $$A[i+1], ... , A[N-1]$$ και κοιτάμε αν όλες είναι μεγαλύτερες από $$A[i]$$.

Κρατάμε στην μεταβλητή $$answer$$ τη μεγαλύτερη τιμή που ικανοποιεί τις συνθήκες 1) και 2). Αρχικά θέτουμε την τιμή ως $$-1$$ (τιμή μικρότερη από όλες τις άλλες), και αν παραμείνει ως το τέλος, τυπώνουμε `"NOT FOUND"`.

Η πολυπλοκότητα του αλγορίθμου είναι $$O(N^2)$$ και χρειάζεται $$O(N)$$ μνήμη, που δεν είναι αρκετό για να περάσει όλα τα testcases.

```c++
#include <cstdio>

const long MAXN = 1000000;

long A[MAXN];
long N;

/* Ελέγξτε αν τα στοιχεία στο [0, i) είναι μικρότερα από το A[i]. */
bool arePreviousSmallerThan(long i) {
  for (long k = 0; k < i; ++k) {
    if (A[i] <= A[k]) return false;
  }
  return true;
}

/* Ελέγξτε αν τα στοιχεία στο (i, N) είναι μεγαλύτερα από το A[i]. */
bool areSubsequentLargerThan(long i) {
  for (long k = i + 1; k < N; ++k) {
    if (A[i] >= A[k]) return false;
  }
  return true;
}

int main() {
  FILE *fi = fopen("solar.in", "r");
  fscanf(fi, "%ld", &N);
  
  for (long i = 0; i < N; ++i) {
    fscanf(fi, "%ld\r\n", &A[i]);
  }
  
  long answer = -1;
  for (long i = 0; i < N; ++i) {
    if (answer < A[i] && arePreviousSmallerThan(i) && areSubsequentLargerThan(i)) {
	  answer = A[i];
	}
  }
  fclose(fi);
  
  FILE *fo = fopen("solar.out", "w");
  if (answer == -1) fprintf(fo, "NOT FOUND\n");
  else fprintf(fo, "%ld\n", answer);
  fclose(fo);
  
  return 0;
}
```


## Βέλτιση Λύση
Μπορούμε να επιταγχύνουμε την παραπάνω λύση με τις εξής παρατηρήσεις:
 * Έστω $$\mathit{mx}[i] = \max(A[0], .. , A[i-1])$$.
 * Η συνθήκη 1) είναι ισοδύναμε με $$\mathit{mx}[i] < A[i]$$.
 * Μπορούμε να υπολογίσουμε το $$\mathit{mx}[i]$$ χρησιμοποιώντας $$\mathit{mx}[i] = \max(\mathit{mx}[i-1], A[i-1])$$ για $$i>0$$ και $$\mathit{mx}[0] = -1$$.

Αντίστοιχα, η συνθήκη 2) ισοδυναμεί με $$\mathit{mn}[i] = \min(A[i+1], .. , A[N-1]) > A[i]$$ και μπορούμε να το υπολογίσουμε χρησιμοποιώντας $$\mathit{mn}[i] = \min(\mathit{mn}[i+1], A[i+1])$$ για $$i < N-1$$ και $$\mathit{mn}[N-1] = \mathit{MAXK} + 1$$ (μεγαλύτερο από τη μέγιστη δυνατή τιμή).

Η πολυπλοκότητα του αλγορίθμου είναι $$Ο(Ν)$$ και χρειάζεται $$Ο(Ν)$$ μνήμη.

```c++
#include <algorithm>
#include <cstdio>

const long MAXN = 1000000;
const long MAXK = 1000000;
long A[MAXN], mx[MAXN], mn[MAXN];
long N;

int main() {
  FILE *fi = fopen("solar.in", "r");
  fscanf(fi, "%ld", &N);
  
  for (long i = 0; i < N; ++i) {
    fscanf(fi, "%ld\r\n", &A[i]);
  }
  
  mx[0] = -1;
  for (long i = 1; i < N; ++i) {
    mx[i] = std::max(mx[i-1], A[i - 1]);
  }
  
  mn[N-1] = MAXK;
  for (long i = N - 2; i >= 0; --i) {
    mn[i] = std::min(mn[i+1], A[i + 1]);
  }
  
  long answer = -1;
  for (long i = 0; i < N; ++i) {
    if (answer < A[i] && mx[i] < A[i] && mn[i] > A[i]) {
      answer = A[i];
    }
  }
  fclose(fi);
  
  FILE *fo = fopen("solar.out", "w");
  if (answer == -1) fprintf(fo, "NOT FOUND\n");
  else fprintf(fo, "%ld\n", answer);
  fclose(fo);
  
  return 0;
}
```
