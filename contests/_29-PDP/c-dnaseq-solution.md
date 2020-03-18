---
layout: solution
codename: dnaseq
---
## Επεξήγηση εκφώνησης
Το πρόβλημα μας δίνει δύο ακολουθίες $$A$$ και $$Β$$ και εμείς πρέπει να βρούμε ακουλουθίες $$X$$, $$Y$$ και $$Z$$, ώστε $$A = XYZ$$ και $$B = X\overline{Y}Z$$, και το μήκος της $$Y$$ να είναι ελάχιστο. Ο συμβολισμός $$\overline{Y}$$ σημαίνει η ακολουθία $$Y$$ αντρίστροφα (πχ αν $$Y = ``abc"$$ τότε $$\overline{Y} = ``cba"$$

## Brute force
Η πιο απλή λύση είναι να δοκιμάσουμε όλα τα $$L$$ και $$M$$, και να ελέγξουμε σε γραμμικό χρόνο αν ικανοποιούν τις συνθήκες.

Ο αλγόριθμος αυτός έχει πολυπλοκότητα $$O(N^3)$$ και χρειάζεται $$O(N)$$ μνήμη.

```c++
#include <algorithm>
#include <cstdio>

const size_t MAXN = 1000000;

char A[MAXN + 2];
char B[MAXN + 2];

long N;

bool checkEqualPrefix(long L) {
  for (long i = 1; i < L; ++i) {
    if (A[i] != B[i]) return false;
  }
  return true;
}

bool checkEqualSuffix(long M) {
  for (long i = M + 1; i <= N; ++i) {
    if (A[i] != B[i]) return false;
  }
  return true;
}

bool checkReversedMiddleStrings(long L, long M) {
  for (long i = L; i <= M; ++i) {
    if (A[i] != B[M+L-i]) return false;
  }
  return true;
}

int main() {
  FILE *fi = fopen("dnaseq.in", "r");
  fscanf(fi, "%ld\n", &N);
  fgets(A + 1, N + 2, fi);
  fgets(B + 1, N + 2, fi);
  fclose(fi);

  long min_diff = N + 1;
  for (long L = 1; L <= N; ++L) {
    for (long M = L; M <= N; ++M) {
      if (checkEqualPrefix(L) && checkEqualSuffix(M)
        && checkReversedMiddleStrings(L, M)) {
        min_diff = std::min(min_diff, M - L);
      }
    }
  }
  
  FILE *fo = fopen("dnaseq.out", "w");
  if (min_diff == N + 1) fprintf(fo, "no\n");
  else fprintf(fo, "%ld\n", min_diff);
  fclose(fo);
  return 0;
}
```

## Λύση με rolling hash
*Η λύση αυτή προϋποθέτει ότι γνωρίζεται τι είναι το rolling hash.*

Μπορούμε να επιταχύνουμε την προηγούμενη λύση χρησιμοποιώντας rolling hash για να συγκρίνουμε ακολουθίες. Κρατάμε $$\mathit{RA}[i] = (\sum_{k=1}^i A[i] \cdot x^i) \mod p$$ και $$\mathit{LA}[i] = (\sum_{k=i}^{N} B[i] \cdot x^{(N-i+1)}) \mod p$$ για έναν πρώτο αριθμό $$p$$ και μία βάση $$x$$.

Οι δοσμένες συνθήκες μπορούν να επαληθευτούν ως εξής:
1. $$\mathit{RA}[L-1] == \mathit{RB}[L-1]$$
2. $$\mathit{LA}[M+1] == \mathit{LB}[M+1]$$
3. $$(\mathit{RA}[M] - \mathit{RA}[L-1])\cdot x^{(N-M+1)} == (\mathit{LB}[L] - \mathit{LA}[M+1])\cdot x^{L}$$ (ο πολλαπλασιασμός με τις δυνάμεις του $$x$$ χρειάζεται ώστε οι δύο ακολουθίες που συγκρίνουμε να ξεκινάμε από την ίδια δύναμη (την $$x^{(N-M+L+1)}$$).

```c++
#include <algorithm>
#include <cstdio>

const size_t MAXN = 1000000;

typedef long long ll;

ll p = 1000000123LL; // Πρώτος αριθμός
ll x = 26; // Βάση 

char A[MAXN + 2];
char B[MAXN + 2];

ll pw[MAXN + 2]; // pw[i] = x^i mod p.
ll RA[MAXN + 2], RB[MAXN + 2];
ll LA[MAXN + 2], LB[MAXN + 2];

long N;

void precomputePowers() {
  pw[0] = 1;
  for (long i = 1; i <= N; ++i) {
    pw[i] = (pw[i-1] * x) % p;
  }
}

void precomputeR() {
  for (long i = 1; i <= N; ++i) {
    RA[i] = (RA[i-1] + A[i] * pw[i]) % p;
    RB[i] = (RB[i-1] + B[i] * pw[i]) % p;
  }
}

void precomputeL() {
  for (long i = N; i >= 1; --i) {
    LA[i] = (LA[i+1] + A[i] * pw[N-i+1]) % p;
    LB[i] = (LB[i+1] + B[i] * pw[N-i+1]) % p;
  }
}

bool checkEqualPrefix(long L) {
  return RA[L-1] == RB[L-1];
}

bool checkEqualSuffix(long M) {
  return LA[M+1] == LB[M+1];
}

bool checkReversedMiddleStrings(long L, long M) {
  return ((RA[M] - RA[L-1] + p) * pw[N-M+1])%p == ((LB[L] - LB[M+1] + p) * pw[L]) % p;
}

// Βάζουμε τους λατινικούς χαρακτήρες στο [0, 25].
void normaliseSequences() {
  for (long i = 1; i <= N; ++i) {
    A[i] -= 'A';
    B[i] -= 'A';
  }
}

int main() {
  FILE *fi = fopen("dnaseq.in", "r");
  fscanf(fi, "%ld\n", &N);
  fgets(A + 1, N + 2, fi);
  fgets(B + 1, N + 2, fi);
  
  normaliseSequences();
  precomputePowers();
  precomputeL();
  precomputeR();

  long min_diff = N + 1;
  for (long L = 1; L <= N; ++L) {
    for (long M = L; M <= N; ++M) {
      if (checkEqualPrefix(L) && checkEqualSuffix(M)
        && checkReversedMiddleStrings(L, M)) {
        min_diff = std::min(min_diff, M - L);
      }
    }
  }
  fclose(fi);
  
  FILE *fo = fopen("dnaseq.out", "w");
  if (min_diff == N + 1) fprintf(fo, "no\n");
  else fprintf(fo, "%ld\n", min_diff);
  fclose(fo);
  return 0;
}
```

Ο αλγόριθμος αυτός έχει πολυπλοκότητα $$O(N^2)$$ και χρειάζεται $$O(N)$$ μνήμη. Το πρόβλημα του είναι ότι με κάποια *μικρή* πιθανότητα μπορεί να βρει λάθος απάντηση (το hash μπορεί να είναι ίδιο αλλά οι ακολουθίες όχι).

## Βέλτιστη λύση
Η βέλτιστη λύση είναι να κάνουμε τα $$X$$ και $$Z$$ όσο πιο μεγάλα γίνεται και μετά να ελέγξουμε ότι οι μεσαίες υποακολουθίες είναι αντίστροφες.

Αυτός ο αλγόριθμος έχει πολυπλοκότητα $$O(N)$$ και χρειάζεται $$O(N)$$ μνήμη.

```c++
#include <algorithm>
#include <cstdio>

const size_t MAXN = 1000000;

char A[MAXN + 2];
char B[MAXN + 2];

long N;

long findLongestCommonPrefix() { 
  long L = 1;
  while (L <= N) {
    if (A[L] != B[L]) return L;
    ++L;
  }
  return N+1;
}

long findLongestCommonSuffix() {
  long M = N;
  while (M >= 1) {
    if (A[M] != B[M]) return M;
    --M;
  }
  return 1;
}

bool checkReversedMiddleStrings(long L, long M) {
  for (long i = L; i <= M; ++i) {
    if (A[i] != B[M+L-i]) return false;
  }
  return true;
}

int main() {
  FILE *fi = fopen("dnaseq.in", "r");
  fscanf(fi, "%ld\n", &N);
  fgets(A + 1, N + 2, fi);
  fgets(B + 1, N + 2, fi);
  fclose(fi);
  
  long L = findLongestCommonPrefix();
  long M = findLongestCommonSuffix();

  FILE *fo = fopen("dnaseq.out", "w");
  if (L > M) fprintf(fo, "0\n");
  else if (checkReversedMiddleStrings(L, M)) fprintf(fo, "%ld\n", M - L);
  else fprintf(fo, "no\n");
  fclose(fo);
  return 0;
}


```

Ακολουθεί η απόδειξη ορθότητας (που δεν είναι αναγκαία για τον διαγωνισμό).

**Θεώρημα:** Αν οι ακολουθίες συσχετίζονται, τότε ο παραπάνω αλγόριθμος δίνει σωστά $$X$$, $$Y$$ και $$Z$$.

*Απόδειξη.* Πρέπει να δείξουμε ότι αν ακολουθήσουμε τον παραπάνω αλγόριθμο και η μία μεσαία ακολουθία $$M_1$$ του $$A$$ δεν είναι η αντίστροφη της μεσαίας ακολουθίας $$M_2$$ στο $$B$$, τότε οι ακολουθίες δεν γίνεται να συσχετίζονται. 

Ας υποθέσουμε ότι οι $$a$$ και $$b$$ είναι οι ακολουθίες με το ελάχιστο συνολικό μήκος ώστε $$M_1' = aM_1b$$ και $$M_2' = aM_2b$$, με $$M_1' = \overline{M_2'}$$. Τότε $$aM_1b = \overline{b}\overline{M_2}\overline{a}$$ και συνεπώς $$a$$ και $$\overline{b}$$ έχουν κοινό prefix. Άρα υπάρχει $$k$$ ώστε $$a = ka'$$ και $$b = b'k$$. Άρα $$M_1' = ka'M_1b'k$$ και $$M_2' = ka'M_2b'k$$. Άρα τα $$M_1'' =a'M_1b'$$ και $$M_2'' = a'M_2b'$$, είναι αντίστροφες. Αλλά $$a''$$ και $$b''$$ έχουν μικρότερο συνολικό μήκος από το ελάχιστο. Άτοπο.

**Σημείωση:** Αν το $$a$$ ή το $$b$$ είναι κενές ακολουθίες τότε η κοινή ακολουθία είναι με το $$M_1$$.

**Θεώρημα:** Το ελάχιστο μήκος της $$Y$$, δίνεται με τον παραπάνω αλγόριθμο.

*Απόδειξη:* Ούτε το $$M$$ μπορεί να είναι μικρότερο, ούτε το $$L$$ μεγαλύτερο. Επομένως αυτή είναι η ελάχιστη διαφορά τους.

