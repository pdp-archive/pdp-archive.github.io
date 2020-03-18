---
layout: solution
codename: sound
---

## Επεξήγηση εκφώνησης
Το πρόβλημα μας ζητάει να βρούμε σε πόσα διαστήματα μήκους $$M$$ η διαφορά της μέγιστης και της ελάχιστης τιμής είναι μικρότερη ή ίση του $$C$$. 

## Brute force λύση
Υπάρχουν $$N-M+1$$ διαστήματα μεγέθους $$M$$, κάθε ένα της μορφής $$[i, i+M)$$ για $$i=0, \ldots , N-M$$. Για κάθε ένα από αυτά υπολογίζουμε την μέγιστη και την ελάχιστη τιμή διατρέχοντας όλα τα στοιχεία του διαστήματος σε χρόνο $$O(M)$$.

Συνεπώς ο αλγόριθμος χρειάζεται χρόνο $$O(N\cdot M)$$ και μνήμη $$O(N)$$. 

```c++
#include <algorithm>
#include <stdio.h> 
#include <stdlib.h>

const size_t MAXN = 1000000;

long a[MAXN];
long N, M, C;

long findMaxDiffInInterval(long st, long en) {
   long max_val = a[st], min_val = a[st];
   for (long i = st; i < en; ++i) {
      max_val = std::max(max_val, a[i]);
      min_val = std::min(min_val, a[i]);
   }
   return max_val - min_val;
}


int main() { 
   FILE *fi = fopen("sound.in", "r");
   fscanf(fi, "%ld%ld%ld", &N, &M, &C);
   for (long i = 0; i < N; ++i) {
      fscanf(fi, "%ld", &a[i]);
   }
   fclose(fi);
   
   FILE *fo = fopen("sound.out", "w");
   bool found = false;
   for (long i = 0; i + M <= N; ++i) {
      long diff = findMaxDiffInInterval(i, i + M);
      if (diff <= C) {
         fprintf(fo, "%ld\n", i + 1);
         found = true;
      }
   }
   if (!found) {
      fprintf(fo, "NULL\n");
   }

   fclose(fo);
   return 0;
}
```

## Λύση με set
Μπορούμε να επιταχύνουμε την παραπάνω λύση βρίσκοντας το ελάχιστο και το μέγιστο για τα διαστήματα $$[0, M)$$, $$[1, M+1)$$, $$\ldots$$ με τη σειρά. Ας δούμε πώς βρίσκουμε γρήγορα το ελάχιστο και με παρόμοια λογική μπορούμε να βρούμε και το μέγιστο. Κρατάμε ένα set $$min\_set$$ με στοιχεία $$(A[x], x)$$. Όταν επεξεργαζόμαστε το διάστημα $$[i, i+M)$$, το $$min\_set$$ μας δίνει το ελάχιστο στοιχείο, αλλά μπορεί αυτό να αντιστοιχεί σε στοιχείο $$(A[j], j)$$ με $$j < i$$ (δηλαδή εκτός διαστήματος). Κάθε τέτοιο στοιχείο που συναντάμε μπορούμε να το αφαιρέσουμε αφού δεν μπορεί να είναι το ελάχιστο για τα επόμενα διαστήματα. Αφαιρώντας στοιχεία, κάποια στιγμή θα βρούμε ένα στοιχείο που ανήκει στο διάστημα $$[i, i+M)$$. Αφού βρούμε το ελάχιστο προσθέτουμε το στοιχείο $$(A[i+M], i+M)$$ και συνεχίζουμε με το επόμενο διάστημα (αν υπάρχει). 

Κάθε στοιχείο θα προστεθεί μία φορά και θα αφαιρεθεί το πολύ μία φορά. Αφού κάθε πράξη στο set θέλει χρόνο $$O(\log{N})$$, ο αλγόριθμος θέλει συνολικό χρόνο $$O(N\log{N})$$ και μνήμη $$O(N)$$. 

```c++
#include <algorithm>
#include <set>
#include <stdio.h> 
#include <stdlib.h>

const size_t MAXN = 1000000;

long a[MAXN];
long N, M, C;

// Κρατάμε τα ζεύγη (A[i], i).
struct Item {
   long idx;
   long value;
   Item(long idx, long value) : idx(idx), value(value) { }
   
   bool operator<(const Item& other) const {
      if (value == other.value) return idx < other.idx;
      return value < other.value;
   }
};

std::set<Item> min_set;
std::set<Item> max_set;

long extractMax(long idx) {
   // Αφαιρούμε στοιχεία μέχρι να βρούμε ένα που είναι στο διάστημα.
   while (max_set.rbegin()->idx < idx - M + 1) max_set.erase(std::prev(max_set.end()));
   return max_set.rbegin()->value;
}

long extractMin(long idx) {
   // Αφαιρούμε στοιχεία μέχρι να βρούμε ένα που είναι στο διάστημα.
   while (min_set.begin()->idx < idx - M + 1) min_set.erase(min_set.begin());
   return min_set.begin()->value;
}

int main() { 
   FILE *fi = fopen("sound.in", "r");
   fscanf(fi, "%ld%ld%ld", &N, &M, &C);
   for (long i = 0; i < N; ++i) {
      fscanf(fi, "%ld", &a[i]);
   }
   fclose(fi);
   
   // Αρχικοποιούμε το set για τα πρώτα M-1 στοιχεία.
   for (long i = 0; i < M - 1; ++i) {
      min_set.insert(Item(i, a[i]));
      max_set.insert(Item(i, a[i]));
   }
   
   FILE *fo = fopen("sound.out", "w");
   bool found = false;
   for (long i = M - 1; i < N; ++i) {
      min_set.insert(Item(i, a[i]));
      max_set.insert(Item(i, a[i]));
      
      if (extractMax(i) - extractMin(i) <= C) {
         found = true;
         fprintf(fo, "%ld\n", i - M + 2);
      }
   }
   
   if (!found) {
      fprintf(fo, "NULL\n");
   }

   fclose(fo);
   return 0;
}

```

## Λύση με μονότονη ουρά
**Παρατήρηση:** Αν βάλουμε μία τιμή $$(A[i], i)$$ στο $$min\_set$$ τότε όλες οι $$(A[j], j)$$ με $$j<i$$ και $$A[i] \leq A[j]$$, δεν μπορούν ποτέ να είναι το ελάχιστο των επόμενων διαστημάτων. 

Με αυτή την παρατήρηση, τροποποιούμε τον παραπάνω αλγόριθμο ώστε να κρατάμε deque[^1] αντί για set. Για το ελάχιστο κρατάμε τα στοιχεία με αύξον $$i$$ και αύξον $$A[i]$$. Όταν πηγαίνουμε από το διάστημα $$[i, i+M)$$ στο $$[i+1, i+M+1)$$, αφαιρούμε από το πίσω μέρος της deque όλα τα στοιχεία που έχουν λήξει (δηλαδή πιθανώς το A[i]) και προσθέτουμε το $$A[i+M]$$. Όταν προσθέσουμε το $$A[i+M]$$ πρέπει να διατηρήσουμε την μονοτονία επομένως αφαιρούμε από μπροστά όλα τα στοιχεία που είναι μεγαλύτερα από το $$A[i]$$ (αφού από την παραπάνω παρατήρηση δεν θα είναι ποτέ ελάχιστα). Το πίσω πίσω στοιχείο είναι το ελάχιστο του διαστήματος.

Για το παράδειγμα, η deque για το ελάχιστο αλλάζει ως εξής:

| Deque      | Σχόλια | Ελάχιστο |
| ----------- | ----------- | ----------- |
| (0, 0) (1, 1)  | Αρχική κατάσταση σε αύξουσα σειρά θέσης | 0 |
| ~~(0, 0) (1, 1)~~ (2, 1) | Αφαιρούμε το (0, 0) επειδή είναι εκτός διαστήματος και το (1,1) επειδή δεν θα είναι ποτέ ελάχιστο | 1 |
| (2, 1) (3, 2)  | Απλά προσθέτουμε το καινούργιο | 1 |
| ~~(2, 1)~~ (3, 2) (4, 3)  | Αφαιρούμε το (2, 1) επειδή είναι εκτός διαστήματος | 2 |
| ~~(3, 2) (4, 3)~~ (5, 2) | Αφαιρούμε το (3, 2) επειδή είναι εκτός διαστήματος και το (4, 3) επειδή δεν θα είναι ποτέ ελάχιστο | 2 |
| ~~(5, 2)~~ (6, 2) | Αφαιρούμε το (5, 2) επειδή δεν θα είναι ποτέ ελάχιστο | 2 |



Αφού κάθε στοιχείο προστίθεται και αφαιρείται μία φορά, ο αλγόριθμος χρειάζεται συνολικά $$O(N)$$ χρόνο και $$O(N)$$ μνήμη.

```c++
#include <algorithm>
#include <deque>
#include <stdio.h> 
#include <stdlib.h>

const size_t MAXN = 1000000;

long a[MAXN];
long N, M, C;

struct Item {
   long idx;
   long value;
   Item(long idx, long value) : idx(idx), value(value) { }
};

std::deque<Item> min_deque;
std::deque<Item> max_deque;

void insertToDeques(long i, long value) {
   Item item(i, value);
   while (!min_deque.empty() && value <= min_deque.front().value) min_deque.pop_front();
   min_deque.push_front(item);
   while (!max_deque.empty() && value >= max_deque.front().value) max_deque.pop_front();
   max_deque.push_front(item);
}

int main() { 
   FILE *fi = fopen("sound.in", "r");
   fscanf(fi, "%ld%ld%ld", &N, &M, &C);
   for (long i = 0; i < N; ++i) {
      fscanf(fi, "%ld", &a[i]);
   }
   fclose(fi);
   
   for (long i = 0; i < M - 1; ++i) {
      insertToDeques(i, a[i]);
   }
   
   FILE *fo = fopen("sound.out", "w");
   bool found = false;
   for (long i = M - 1; i < N; ++i) {
      // Αφαιρούμε το πίσω στοιχείο αν είναι εκτός διαστήματος [i, i+M).
      if (min_deque.back().idx < i - M + 1) min_deque.pop_back();
      if (max_deque.back().idx < i - M + 1) max_deque.pop_back();
      
      insertToDeques(i, a[i]);
      if (max_deque.back().value - min_deque.back().value <= C) {
         found = true;
         fprintf(fo, "%ld\n", i - M + 2);
      }
   }
   
   if (!found) {
      fprintf(fo, "NULL\n");
   }

   fclose(fo);
   return 0;
}

```

[^1]: Δομή δεδομένων που υποστηρίζει `push_front`, `push_back`, `pop_front` και `pop_back` σε $$O(1)$$.