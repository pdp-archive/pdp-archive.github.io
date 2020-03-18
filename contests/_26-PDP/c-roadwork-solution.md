---
layout: solution
codename: roadwork
---
## Λύση $$O(NL)$$
Διατηρούμε έναν πίνακα $$Τ$$ από booleans με μήκος $$L$$, όπου $$T[i]$$ δείχνει αν το $$[i, i+1]$$ είναι καλυπτόμενo από κάποιο διάστημα. Για να προσθέσουμε ένα διάστημα $$[S, T]$$ σημαδεύουμε όλα σημεία $$T[i] = 1$$ για $$i \in [S, T)$$. Για να βρούμε το μέγιστο κενό, διατρέχουμε τον πίνακα $$T$$ και αναζητούμε για την μέγιστη συνεχόμενη ακολουθία από $$0$$. Το μήκος της είναι το μέγιστο κενό. Προσθέτουμε ένα-ένα τα διαστήματα, και όταν το μέγιστο κενό γίνει μικρότερο από $$X$$, έχουμε βρει την απάντηση.

Κάθε βήμα του αλγορίθμου θέλει στην χειρότερη περίπτωση $$O(L)$$ χρόνο, άρα η τελική πολυπλοκότητα είναι $$O(NL)$$ και η μνήμη είναι $$O(L)$$.

```c++
#include <algorithm>
#include <cstdio>

const size_t MAXL = 1000000;
const size_t MAXN = 1000000;

bool is_covered[MAXL];

long cover(long s, long t) {
  for (long j = s; j < t; ++j) {
	is_covered[j] = true;
  }
}

long N, L, X;

long findMaxGap() {
  long prev_one = -1;
  long max_gap = 0;
  for (long j = 0; j < L; ++j) {
    if (is_covered[j]) prev_one = j;
	else {
	  long gap = j - prev_one;
	  max_gap = std::max(max_gap, gap);
	}
  }
  return max_gap;
}

int main() {
  FILE *fi = fopen("roadwork.in", "r");
  fscanf(fi, "%ld %ld %ld", &N, &L, &X);
  long solution = -1;
  if (findMaxGap() <= X) {
    solution = 0;
  } else {	
	  for (long j = 0; j < N; ++j) {
		long s, t;
		fscanf(fi, "%ld %ld", &s, &t);
		cover(s, t);
		if (findMaxGap() <= X) {
		  solution = j + 1;
		  break;
		}
	  }
  }
  FILE *fo = fopen("roadwork.out", "w");
  fprintf(fo, "%ld\n", solution);
  fclose(fi);
  fclose(fo);
  return 0;
}  
```

## Λύση σε $$O(N^2)$$
Το $$L$$ μπορεί να είναι πολύ μεγάλο, άρα η προηγούμενη λύση είναι αργή. Θα επιταχύνουμε την εύρεση του μεγίστου κενού για τα $$D$$ πρώτα διαστήματα.

### Εύρεση μέγιστου κενού
Παρατηρούμε ότι σημασία για το μέγιστο κενό έχουν μόνο οι αρχές και τα τέλη των διαστημάτων. Επομένως ακολουθούμε τα εξής βήματα:
 1. Ταξινομούμε τις αρχές και τα τέλη των διαστημάτων (με τις αρχές να παίρνουν προτεραιότητα από τα τέλη).
 2. Διατρέχουμε τον πίνακα, και σε κάθε σημείο ξέρουμε ότι είμαστε μέσα σε κάποιο διάστημα αν έχουμε δει λιγότερα τέλη από αρχές. Αν έχουμε δει ίσα, τότε είμαστε εκτός διαστήματος και ξεκινάει ένα κενό (από το τωρινό (τελικό) σημείο στο αμέσως επόμενό του).
 3. Βρίσκουμε το μέγιστο από αυτά τα κενά. 

Για παράδειγμα, για τα διαστήματα $$\lbrace [1, 4], [2, 6], [8, 10] \rbrace$$, η αναπαράσταση είναι η εξής:

![Example](/assets/26-pdp-c-roadwork-example.svg)

| Αρχή $$s(\cdot)$$ / Τέλος $$e(\cdot)$$ | $$s(1)$$ | $$s(3)$$ | $$e(4)$$ | $$e(6)$$ | $$s(8)$$ | $$e(10)$$ |
| Αρχές χωρίς τέλος | $$1$$ | $$2$$ | $$1$$ | $$0$$ | $$1$$ | $$0$$ |

Προσέξτε ότι όταν το πλήθος των αρχών που δεν έχουν τέλος είναι μηδέν, τότε υπάρχει κενό. Το μήκος του κενού που ξεκινάει στο $$e(6)$$ είναι $$8-6=2$$.

**Σημείωση:** Πρέπει να λάβουμε υπόψιν τα κενά στην αρχή και στο τέλος ολόκληρου του διαστήματος.

Αυτό μας δίνει τον αλγόριθμο με πολυπλοκότητα $$O(N^2)$$ και μνήμη $$O(N)$$.

```c++
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAXN 1001000

using namespace std;

struct ent{
  long x; // Θέση.
  long t; // Τύπος (+1: αρχή, -1: τέλος).
  long d; // Στιγμή που εισήχθη.
  bool operator<(const ent &E) const{
    if (x == E.x) return t > E.t; // Πρώτα τα τέλη.
    return x < E.x;
  }
  ent(long x, long t, long d) : x(x), t(t), d(d) { }
  ent() { }
} interv[2*MAXN];

long L, N, X;
long findMaxGap(long d){
  long prev = 1, gap = 0, open_intervals = 0, max_gap = 0;
  for (long i = 0; i < 2 * N; i++){
    // Ελέγχουμε ένα σημείο μόνο αν ανήκει στα πρώτα
    // d διαστήματα.
    if (d >= interv[i].d){
      if (open_intervals == 0) {
        gap += interv[i].x - prev;
        max_gap = max(max_gap, gap);
      } else gap = 0;
      open_intervals += interv[i].t;
      prev = interv[i].x;
    }
  }
  return max(max_gap, L-prev);
}

int main(){
  FILE *fi = fopen("roadwork.in", "r");
  fscanf(fi, "%ld%ld%ld", &N, &L, &X);
  for (long i = 1; i <= N; i++){
    long A, B;
    fscanf(fi, "%ld%ld", &A, &B);
    interv[2*i-2] = ent(A,  1, i);
    interv[2*i-1] = ent(B, -1, i);
  }
  sort(interv, interv+2*N);

  long answer = -1;
  for (long d = 1; d <= N; ++d) {
    if (findMaxGap(d) <= X) {
      answer = d;
      break;
    }
  }
  
  FILE *fo = fopen("roadwork.out", "w");
  fprintf(fo, "%ld\n", answer);
  fclose(fi);
  fclose(fo);
  return 0;
}
```

## Λύση σε $$O(N \log N)$$
**Παρατήρηση:** Έστω $$x_1$$ και $$x_2$$ το μέγιστο κενό για τα $$k_1$$ και $$k_2$$ πρώτα διαστήματα. Αν $$k_1 < k_2$$, τότε  $$x_1 > x_2$$, καθώς τα κενά μπορούν μόνο να μικρύνουν όταν προσθέτουμε διαστήματα.

Αυτή η μονοτονία μας επιτρέπει να κάνουμε δυαδική αναζήτηση στο πρώτο $$k$$ για το οποίο το μέγιστο κενό είναι μικρότερο από $$X$$. Άρα χρειάζεται να τρέξουμε τον παραπάνω αλγόριθμο $$Ο(\log N)$$ φορές.

Ο αλγόριθμος αυτός έχει πολυπλοκότητα $$Ο(N \log N)$$ για την ταξινόμηση και $$O(N)$$ για την εύρεση του κάθε μέγιστου κενού. Χρειάζεται $$O(N)$$ μνήμη.

```c++
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAXN 1001000

using namespace std;

struct ent{
  long x; // Θέση.
  long t; // Τύπος (+1: αρχή, -1: τέλος).
  long d; // Στιγμή που εισήχθει.
  bool operator<(const ent &E) const{
	if (x == E.x) return t > E.t; // Πρώτα τα τέλη.
	return x < E.x;
  }
  ent(long x, long t, long d) : x(x), t(t), d(d) { }
  ent() { }
} interv[2*MAXN];

long L, N, X;
int findMaximumGap(int d){
  long prev = 1, gap = 0, open_intervals = 0, max_gap = 0;
  for (int i = 0; i < 2 * N; i++){
	// Ελέγχουμε ένα σημείο μόνο αν ανήκει στα πρώτα
	// d διαστήματα.
    if (d >= interv[i].d){
      if (open_intervals == 0) {
        gap += interv[i].x - prev;
        max_gap = max(max_gap, gap);
      } else gap = 0;
      open_intervals += interv[i].t;
      prev = interv[i].x;
    }
  }
  return max(max_gap, L-prev);
}

long binSearchAnswer() {
  if (findMaximumGap(N) > X) return -1;
  long st = 0, en = N; 
  while (st < en - 1){
    long mn = (st + en)/2;
    if (findMaximumGap(mn) <= X) en = mn;
    else st = mn + 1;
  }
  if (findMaximumGap(st) <= X) return st;
  return en;
}

int main(){
  FILE *fi = fopen("roadwork.in", "r");
  fscanf(fi, "%ld%ld%ld", &N, &L, &X);
  for (long i = 1; i <= N; i++){
	long A, B;
    fscanf(fi, "%ld%ld", &A, &B);
    interv[2*i-2] = ent(A,  1, i);
    interv[2*i-1] = ent(B, -1, i);
  }
  sort(interv, interv+2*N);
   
  FILE *fo = fopen("roadwork.out", "w");
  fprintf(fo, "%ld\n", binSearchAnswer());
  fclose(fi);
  fclose(fo);
  return 0;
}
```

**Σημείωση:** Το πρόβλημα μπορεί να λυθεί και με την χρήση δομών δεδομένων όπως τα sets και τα segment trees, χωρίς την χρήση δυαδικής αναζήτησης στην απάντηση.