---
layout: solution
codename: starwars
---

*Σημείωση:* Οι πιο αποδοτικές λύσεις απαιτούν γνώσεις [SQRT-decomposition](https://cp-algorithms.com/data_structures/sqrt_decomposition.html) και [segment trees](https://kallinikos.github.io/Segment-Trees) με lazy propagation.

## Επεξήγηση προβλήματος

Μας δίνεται ένας $$X \times Y \times Z$$ κύβος αποτελούμενος από $$1 \times 1 \times 1$$ κύβους που είναι ευθυγραμμισμένοι με τους άξονες. Αρχικά όλοι οι κύβοι είναι σβηστοί. Μετά μας δίνονται $$M$$ πράξεις:
 * **update:** να αλλάξουμε την κατάσταση όλων των κύβων που έχουν μία συντεταγμένη $$k$$ στο $$[A, B]$$ (σε έναν δοσμένο άξονα)
 * **query:** να βρούμε πόσοι κύβοι είναι αναμμένοι στον κύβο με αντιδιαμετρικές κορυφές $$(x_1, y_1, z_1)$$ και $$(x_2, y_2, z_2)$$.

## Brute force λύση

Ο πιο απλός τρόπος για να λύσουμε το πρόβλημα είναι να κρατάμε έναν πίνακα $$a$$ μεγέθους $$X \times Y \times Z$$ από δυαδικές τιμές, όπου $$0$$ (false) αντιστοιχεί σε σβηστό και $$1$$ (true) αντιστοιχεί σε αναμμένο κύβο.

**updates:** Όταν έρχεται ένα update, για παράδειγμα $$0\ A\ B$$, τότε διατρέχουμε όλους τους κύβους με $$A \leq x \leq B$$ και αλλάζουμε τις καταστάσεις τους:

```c++
void update_x(int l, int r) {
   for (int i = l; i <= r; ++i) {
      for (int j = 0; j < Y; ++j) {
         for (int k = 0; k < Z; ++k) {
            a[i][j][k] = !a[i][j][k];
         }
      }
   }
}
```

Αντίστοιχα, χειριζόμαστε τις περιπτώσεις για τους υπόλοιπους άξονες. Στην χειρότερη περίπτωση μπορεί να χρειαστεί να διατρέξουμε όλους τους κύβους (για παράδειγμα όταν το update είναι $$0\ 0\ (X-1)$$). Άρα η χρονική πολυπλοκότητα για ένα update είναι $$O(X \cdot Y \cdot Z)$$.

**queries:** Για κάθε query, διατρέχουμε όλους τους κύβους μεταξύ των $$(x_1, y_1, z_1)$$ και $$(x_2, y_2, z_2)$$ και μετράμε πόσοι είναι αναμμένοι:

```c++
long sum(int x1, int y1, int z1, int x2, int y2, int z2) {
   long sm = 0;
   for (int i = x1; i <= x2; ++i) {
      for (int j = y1; j <= y2; ++j) {
         for (int k = z1; k <= z2; ++k) {
            sm += a[i][j][k];
         }
      }
   }
   return sm;
}
```

Ξανά, στην χειρότερη περίπτωση (για παράδειγμα όταν το query είναι $$3\ 0\ 0\ 0\ (X-1)\ (Y-1)\ (Z-1)$$) θα χρειαστεί να διατρέξουμε όλους τους $$X \cdot Y \cdot Z$$ κύβους. Άρα η χρονική πολυπλοκότητα για ένα query είναι $$O(X \cdot Y \cdot Z)$$.

Συνεπώς, η χρονική πολυπλοκότητα είναι $$O(M \cdot X \cdot Y \cdot Z)$$ και η λύση αυτή πιάνει το $$20\%$$. Ολόκληρος ο κώδικας δίνεται παρακάτω:

```c++
#include <cstdio>
#include <vector>
#include <iostream>

const size_t MAXD = 100;

bool a[MAXD][MAXD][MAXD];

int X, Y, Z;

void init() {
   for (int i = 0; i < X; ++i) {
      for (int j = 0; j < Y; ++j) {
         for (int k = 0; k < Z; ++k) {
            a[i][j][k] = 0;
         }
      }
   }
}

void update_x(int l, int r) {
   for (int i = l; i <= r; ++i) {
      for (int j = 0; j < Y; ++j) {
         for (int k = 0; k < Z; ++k) {
            a[i][j][k] = !a[i][j][k];
         }
      }
   }
}

void update_y(int l, int r) {
   for (int i = l; i <= r; ++i) {
      for (int j = 0; j < X; ++j) {
         for (int k = 0; k < Z; ++k) {
            a[j][i][k] = !a[j][i][k];
         }
      }
   }
}

void update_z(int l, int r) {
   for (int i = l; i <= r; ++i) {
      for (int j = 0; j < X; ++j) {
         for (int k = 0; k < Y; ++k) {
            a[j][k][i] = !a[j][k][i];
         }
      }
   }
}

long sum(int x1, int y1, int z1, int x2, int y2, int z2) {
   long sm = 0;
   for (int i = x1; i <= x2; ++i) {
      for (int j = y1; j <= y2; ++j) {
         for (int k = z1; k <= z2; ++k) {
            sm += a[i][j][k];
         }
      }
   }
   return sm;
}

int main() {
   freopen("starwars.in", "r", stdin);
   freopen("starwars.out", "w", stdout);
   int T;
   scanf("%d", &T);
   while(T--) {
      int M;
      scanf("%d %d %d %d", &X, &Y, &Z, &M);
      init();
      while (M--) {
         int type;
         scanf("%d", &type);
         if (type == 0) {
            int A, B;
            scanf("%d %d", &A, &B);
            update_x(A, B);
         } else if (type == 1) {
            int A, B;
            scanf("%d %d", &A, &B);
            update_y(A, B);
         } else if (type == 2) {
            int A, B;
            scanf("%d %d", &A, &B);
            update_z(A, B);
         } else if (type == 3) {
            int x1, x2, y1, y2, z1, z2;
            scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
            printf("%ld\n", sum(x1, y1, z1, x2, y2, z2));
         }
      }
   }
   return 0;
}
```

## Καλύτερες λύσεις

Ξεκινάμε με την εξής παρατήρηση:

**Παρατήρηση 1:** Ένας κύβος είναι αναμμένος αν έχει χτυπηθεί μονό αριθμό φορών.

*(Απόδειξη)* Κάθε φορά που χτυπάται ένας κύβος αλλάζει κατάσταση. Άρα μετά από ζυγό αριθμό χτυπημάτων θα επανέρχεται στην αρχική κατάσταση (σβηστό) και μετά από μονό αριθμό θα είναι στην αναμμένη κατάσταση.

Για να κάνουμε τα updates και τα queries πιο αποδοτικά, χρησιμοποιήσουμε τη λύση για το πρόβλημα στο 1D. Αυτό σημαίνει ότι για κάθε άξονα $$i$$ έχουμε τις συναρτήσεις 
 * $$\mathrm{update}_i(A, B)$$ που αλλάζει την κατάσταση όλων των κύβων στο $$[A, Β]$$. Αυτή τη συνάρτηση θα καλούμε σε κάθε update στον αντίστοιχο άξονα.
 * $$\mathrm{sum}_i(A, B)$$ που μας επιστρέφει πόσοι κύβοι είναι αναμμένοι στο $$[A, Β]$$ 

Θα δούμε τώρα πώς θα χρησιμοποιήσουμε αυτές τις τρεις δομές για να λύσουμε το αρχικό πρόβλημα, ξεκινώντας με την απλούστερη περίπτωση του 2D. Μετά θα δούμε πώς γενικεύεται αυτό σε 3D. Παρακάτω, θα κοιτάξουμε πώς θα υλοποιήσουμε αποδοτικά δομές που υποστηρίζουν αυτές τις συναρτήσεις.

### Το πρόβλημα στο 2D


**Παρατήρηση 2:** Μπορούμε να μετρήσουμε τους αναμμένους κύβους με τον εξής τρόπο:

![Μέτρηση σε 2D](/assets/28-pdp-c-starwars-2d-sum.svg){:width="600px"}

*(Απόδειξη)* Οι πρώτοι δύο όροι μετράνε μία φορά τους κύβους που έχουν χτυπηθεί μονό αριθμό φορών σε κάθε έναν από τους άξονες. Αλλά έτσι διπλομετράμε αυτούς που έχουν χτυπηθεί μονό αριθμό φορών και από τους δύο (άρα ζυγό αριθμό συνολικά). Ο τρίτος όρος αφαιρεί αυτά τα κοινά καθώς θα είναι σβηστά.

**Παρατήρηση 3:** Αν έχουμε αποδοτικό τρόπο να λύσουμε το πρόβλημα σε 1D, τότε έχουμε αποδοτικό τρόπο να το λύσουμε σε 2D.

*(Απόδειξη)* Μπορούμε να υπολογίσουμε τα αθροίσματα χρησιμοποιώντας δύο δομές για το 1D, μία για κάθε άξονα. Κάθε φορά που έρχεται ένα update $$i\ A\ B$$, τότε καλούμε $$\mathrm{update}_i(A, B)$$. Επομένως το $$\mathrm{sum}_i(A, B)$$, επιστρέφει πόσες γραμμές είναι αναμμένες άμα κοιτάξουμε μόνο τον άξονα $$i$$. Άρα άμα πολλαπλασιάσουμε επί το μήκος του άλλου άξονα, μας δίνεται ο συνολικός αριθμός των κύβων που αντιστοιχούν στον πρώτο όρο του παραπάνω αθροίσματος. Για παράδειγμα, όταν κοιτάμε τον άξονα $$x$$, έχουμε

![Ατομικά στοιχεία](/assets/28-pdp-c-starwars-1d-to-2d-sum-individual.svg){:width="600px"}

Επομένως, αυτό μας επιτρέπει να υπολογίσουμε τους δύο πρώτους όρους του αθροίσματος ως $$(y_2 - y_1 + 1) \cdot \mathrm{sum}_x(x_1, x_2) + (x_2 - x_1 + 1) \cdot \mathrm{sum}_y(y_1, y_2)$$. Ο τρίτος όρος μπορεί να υπολογιστεί ως $$\mathrm{sum}_x(x_1, x_2) \cdot \mathrm{sum}_y(y_1, y_2)$$, καθώς κάθε αναμμένη γραμμή του $$x$$ τέμνεται με κάθε αναμμένη γραμμή του $$y$$:

![Κοινά στοιχεία](/assets/28-pdp-c-starwars-1d-to-2d-sum-common.svg){:width="650px"}

Επομένως, αν έχουμε έναν τρόπο να υπολογίσουμε γρήγορα την λύση για 1D, τότε έχουμε έναν τρόπο να υπολογίσουμε γρήγορα και για 2D.

### Το 2D πρόβλημα ως πράξεις σε σύνολα

Έχουμε δει πώς μπορούμε να λύσουμε το 2D πρόβλημα αναγάγοντάς το στο 1D πρόβλημα. Ο λόγος που μπορούμε να το κάνουμε γρήγορα είναι γιατί μπορούμε να μετρήσουμε τα κοινά στοιχεία μεταξύ των αναμμένων γραμμών του $$X$$ και του $$Y$$, για να τα αφαιρέσουμε κατάλληλα. Αυτό μπορούμε να το αναπαραστήσουμε με τη μορφή συνόλων. Το σύνολο $$X$$ και το σύνολο $$Y$$ κρατάνε τους αναμμένους κύβους στα αντίστοιχα 1D προβλήματα. Εμείς θέλουμε να υπολογίσουμε το πλήθος των κύβων που καλύπτονται μονό αριθμών φορών, άρα μονό αριθμών φορών από το $$X$$ ή μονό αριθμό φορών από το $$Y$$. Δηλαδή ζητάμε το πλήθος των κύβων στην ένωση των στοιχείων χωρίς την τομή:

![Σύνολο στόχος](/assets/28-pdp-c-starwars-2d-target-set.svg){:width="250px"}

Είδαμε παραπάνω πώς μπορούμε να υπολογίσουμε τα εξής υποσύνολα:

![2D σαν σύνολο](/assets/28-pdp-c-starwars-2d-set-theory.svg){:width="550px"}

Και το άθροισμα αντιστοιχεί στο εξής:

![2D ως άθροισμα συνόλων](/assets/28-pdp-c-starwars-2d-as-sum-set.svg){:width="550px"}

### Το 3D πρόβλημα ως πράξεις σε σύνολα

Τώρα είμαστε έτοιμοι να επεκτείνουμε αυτή την στρατηγική και στο 3D. Θέλουμε να βρούμε όλους του κύβους που καλύπτονται μονό αριθμών φορών. Στο διάγραμμα συνόλων μας ενδιαφέρουν οι εξής περιοχές:

![3D σύνολο στόχος](/assets/28-pdp-c-starwars-3d-target-set.svg){:width="250px"}

Με παρόμοιο τρόπο όπως πριν μπορούμε να υπολογίσουμε τις τομές οποιονδήποτε συνόλων:

![3D σαν σύνολο](/assets/28-pdp-c-starwars-3d-set-theory.svg){:width="550px"}

 1. Για παράδειγμα, η απάντηση για το α) για τον άξονα $$X$$ δίνεται από $$\Delta Y \cdot \Delta Z \cdot \mathrm{sum}_x(x_1, x_2)$$ (σκεφτείτε την γενίκευση των παραπάνω σχημάτων).
 1. Για παράδειγμα, η απάντηση για το β) για τους άξονες $$X, Y$$ δίνεται από $$\Delta Z \cdot \mathrm{sum}_x(x_1, x_2) \cdot \mathrm{sum}_y(y_1, y_2)$$.
 1. Η απάντηση για το γ) δίνεται από $$\mathrm{sum}_x(x_1, x_2) \cdot \mathrm{sum}_y(y_1, y_2) \cdot \mathrm{sum}_z(z_1, z_2)$$.

Τέλος, βρίσκουμε τους συντελεστές ώστε να κάνουμε το άθροισμα των συνόλων ίσο με το σύνολο που θέλουμε:

![2D ως άθροισμα συνόλων](/assets/28-pdp-c-starwars-3d-as-sum-set.svg){:width="550px"}

Σε κώδικα (αν η DataStructureFor1D λύνει το πρόβλημα για το 1D) αυτό είναι:

```c++
size_t len(size_t a, size_t b) {
   return b - a + 1;
}

int main() {
   freopen("starwars.in", "r", stdin);
   freopen("starwars.out", "w", stdout);
   int T;
   scanf("%d", &T);
   while(T--) {
      int X, Y, Z, M;
      scanf("%d %d %d %d", &X, &Y, &Z, &M);
      DataStructureFor1D x_ds(X), y_ds(Y), z_ds(Z);
      while (M--) {
         int type;
         scanf("%d", &type);
         if (type == 0) {
            int A, B;
            scanf("%d %d", &A, &B);
            x_ds.update(A, B);
         } else if (type == 1) {
            int A, B;
            scanf("%d %d", &A, &B);
            y_ds.update(A, B);
         } else if (type == 2) {
            int A, B;
            scanf("%d %d", &A, &B);
            z_ds.update(A, B);
         } else if (type == 3) {
            int x1, x2, y1, y2, z1, z2;
            scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
            size_t x = x_ds.sum(x1, x2);
            size_t y = y_ds.sum(y1, y2);
            size_t z = z_ds.sum(z1, z2);
            
            size_t x_only = x * len(y1, y2) * len(z1, z2);
            size_t y_only = y * len(x1, x2) * len(z1, z2);
            size_t z_only = z * len(y1, y2) * len(x1, x2);
            
            size_t x_y = x * y * len(z1, z2);
            size_t y_z = y * z * len(x1, x2);
            size_t x_z = x * z * len(y1, y2);
            
            long long ans = x_only + y_only + z_only - 2 * (x_y + y_z + x_z) + 4 * x * y * z;
            printf("%lld\n", ans);
         }
      }
   }
   return 0;
}
```

### Αποδοτική λύση για 1D

Μένει να δούμε πώς λύνουμε αποδοτικά το πρόβλημα στο 1D. 

#### SQRT-decomposition

Το [SQRT-decomposition](https://cp-algorithms.com/data_structures/sqrt_decomposition.html) χωρίζει το array (μεγέθους $$N$$) σε διαστήματα (buckets) μεγέθους περίπου $$\sqrt{N}$$. Σε αυτό το πρόβλημα για κάθε διάστημα κρατάμε:
 1. `bucket_sum`: το πλήθος των αναμμένων κύβων
 2. `switch_bucket`: αν έχουμε αλλάξει την κατάσταση όλων των κύβων στο διάστημα

**updates:** Σε κάθε update $$A\ B$$ βρίσκουμε τα διαστήματα που περιέχονται πλήρως στο $$[A, B]$$, για τα οποία ισχύει ότι όλα τα στοιχεία τους αλλάζουν. Αντί να τα αλλάξουμε όλα, αλλάζουμε την μεταβλητή switch_bucket, κι έτσι γλιτώνουμε χρόνο. Επιπλέον ανανεώνουμε το άθροισμα τους όπως παρακάτω.

```c++
void change_state(size_t bucket_id) {
   switch_bucket[bucket_id] = !switch_bucket[bucket_id];
   bucket_sum[bucket_id] = bucket_size(bucket_id) - bucket_sum[bucket_id];
}
```

Με τον τρόπο αυτό γνωρίζουμε το πραγματικό άθροισμα εντός ενός διαστήματος, αλλά έχουμε ακριβώς τις ανάποδες τιμές από αυτές που θα έπρεπε στα στοιχεία του διαστήματος, εάν η μεταβλητή switch_bucket είναι αναμμένη.

Για τα υπόλοιπα στοιχεία του $$[A, B]$$ που όμως το διάστημά τους δεν περιέχεται πλήρως στο $$[A, B]$$, ισχύει ότι ανήκουν είτε στο διάστημα που τέμνει από αριστερά το $$[A, B]$$, είτε από δεξιά. Συνεπώς υπάρχουν το πολύ $$2 \cdot \sqrt{N}$$ τέτοια, για τα οποία εφαρμόζουμε τα updates ένα ένα (αφού εφαρμόσουμε το `switch_bucket` σε ολόκληρο το διάστημα ώστε να αποκτήσουν την πραγματική τους τιμή).

**queries:** Αντίστοιχα, σε κάθε query $$A\ B$$ βρίσκουμε πάλι όλα τα διαστήματα που περιέχονται πλήρως στο $$[A, B]$$ και αθροίζουμε τα πλήθη των αναμμένων κύβων. Για τα στοιχεία εκτός αυτών των διαστημάτων (πάλι στο πλήθος λιγότερα από $$2 \cdot \sqrt{N}$$), τα εξετάζουμε ένα ένα (αφού εφαρμόσουμε το `switch_bucket` σε ολόκληρο το διάστημα). 

Κάθε update και κάθε query θέλει χρόνο $$O(\sqrt{N})$$, επομένως η τελική πολυπλοκότητα είναι $$O(M \cdot \sqrt{X} + X)$$.

```c++
#include <cstdio>
#include <vector>
#include <iostream>

const size_t BUCKET_SIZE = 1000;

struct SqrtDecomposition {
   
   std::vector<bool> state;

   std::vector<bool> switch_bucket;

   std::vector<size_t> bucket_sum;

   size_t N;
   
   SqrtDecomposition(size_t n) {
     N = n;
     state = std::vector<bool>(N, false);
     switch_bucket = std::vector<bool>(N / BUCKET_SIZE + 1, false);
     bucket_sum = std::vector<size_t>(N / BUCKET_SIZE + 1, 0);
   }

   size_t start(size_t bucket_id) {
      return bucket_id * BUCKET_SIZE;
   }

   size_t end(size_t bucket_id) {
      return std::min(N - 1, (bucket_id + 1) * BUCKET_SIZE - 1);
   }

   size_t bucket_size(size_t bucket_id) {
      return end(bucket_id) - start(bucket_id) + 1;
   }

   size_t bucket(size_t i) {
      return i / BUCKET_SIZE;
   }

   void apply_state(size_t bucket_id) {
      if (!switch_bucket[bucket_id]) return;
      switch_bucket[bucket_id] = false;
      for (size_t i = start(bucket_id); i <= end(bucket_id); ++i) {
         state[i] = !state[i];
      }
   }

   void change_state(size_t bucket_id) {
      switch_bucket[bucket_id] = !switch_bucket[bucket_id];
      bucket_sum[bucket_id] = bucket_size(bucket_id) - bucket_sum[bucket_id];
   }

   void update_bucket(size_t bucket_id, size_t start_idx, size_t len) {
      apply_state(bucket_id);
      size_t end_idx = std::min(start_idx + len, end(bucket_id) + 1);
      for (size_t i = start_idx; i < end_idx; ++i) {
         state[i] = !state[i];
         bucket_sum[bucket_id] += state[i];
         bucket_sum[bucket_id] -= 1 - state[i];
      }
   }

   void update(size_t i, size_t j) {
      size_t bucket_i = bucket(i);
      size_t bucket_j = bucket(j);
      if (bucket_i == bucket_j) {
         update_bucket(bucket_i, i, j - i + 1);
         return;
      }
      
      update_bucket(bucket_i, i, BUCKET_SIZE);
      update_bucket(bucket_j, start(bucket_j), j - start(bucket_j) + 1);
      
      for (size_t bucket_id = bucket_i + 1; bucket_id < bucket_j; ++bucket_id) {
         change_state(bucket_id);
      }
   }

   size_t sum_bucket(size_t i, size_t j) {
      size_t bucket_id = bucket(i);
      apply_state(bucket_id);
      size_t sum = 0;
      size_t end_idx = std::min(i + j, end(bucket_id) + 1);
      for (size_t k = i; k < end_idx; ++k) {
         sum += state[k];
      }
      return sum;
   }

   size_t sum(size_t i, size_t j) {
      size_t bucket_i = bucket(i);
      size_t bucket_j = bucket(j);
      if (bucket_i == bucket_j) {
         return sum_bucket(i, j - i + 1);
      }
      
      size_t sm = 0;
      sm += sum_bucket(i, BUCKET_SIZE);
      sm += sum_bucket(start(bucket_j), j - start(bucket_j) + 1);
      
      for (size_t bucket_id = bucket_i + 1; bucket_id < bucket_j; ++bucket_id) {
         sm += bucket_sum[bucket_id];
      }
      return sm;
   }
};

int main() {
   // Ίδιος κώδικας με πριν..
   
   SqrtDecomposition x_ds(X), y_ds(Y), z_ds(Z);
}
```

#### Segment tree

Αντί για SQRT-decomposition μπορούμε να χρησιμοποιήσουμε ένα [segment tree](https://kallinikos.github.io/Segment-Trees) με lazy propagation. Σε κάθε κόμβο κρατάμε το πλήθος των αναμμένων κύβων `node_sum` και το `switch_node`, αν έχουμε αλλάξει την κατάσταση όλων των κύβων στο διάστημα. Η μόνη αλλαγή με το κλασσικό segment tree είναι η συνάρτηση που ανανεώνει τους κόμβους παιδιά του τωρινού κόμβου, με βάση την τιμή `switch_node`. Καλείται πριν το update και το query των παιδιών.

```c++
void propagate(size_t n, long b, long e) {
   if (switch_node[n]) {
      switch_node[2*n] = !switch_node[2*n];
      node_sum[2*n] = ( (b+e)/2 - b + 1 ) - node_sum[2 * n];
      switch_node[2*n + 1] = !switch_node[2*n + 1];
      node_sum[2*n + 1] = ( e - (b+e)/2 ) - node_sum[2*n + 1];
      switch_node[n] = false;
   }
}
```

Τα updates και τα queries στο segment tree θέλουν $$O(\log{X})$$, επομένως η χρονική πολυπλοκότητα του αλγορίθμου είναι $$O(M \cdot \log{X} + X)$$. Ο πλήρης κώδικας δίνεται παρακάτω.

```c++
#include <cstdio>
#include <vector>
#include <iostream>

struct SegTree {
   
   std::vector<bool> state;

   std::vector<bool> switch_node;

   std::vector<long> node_sum;

   size_t N;
   
   SegTree(size_t n) {
      N = n;
      state.resize(4 * N + 1, false);
      switch_node.resize(4 * N + 1, false);
      node_sum.resize(4 * N + 1, 0);
   }
   
   void propagate(size_t n, long b, long e) {
      if (switch_node[n]) {
         switch_node[2*n] = !switch_node[2*n];
         node_sum[2*n] = ( (b+e)/2 - b + 1 ) - node_sum[2 * n];
         switch_node[2*n + 1] = !switch_node[2*n + 1];
         node_sum[2*n + 1] = ( e - (b+e)/2 ) - node_sum[2*n + 1];
         switch_node[n] = false;
      }
   }

   void update(size_t n, long b, long e, long i, long j) {
      if (b > j || e < i) return;
      if (i <= b && e <= j) {
         switch_node[n] = !switch_node[n];
         node_sum[n] = (e - b + 1) - node_sum[n];
         return;
      }
      propagate(n, b, e);
      
      update(2*n, b, (b+e)/2, i, j);
      update(2*n+1, (b+e)/2+1, e, i, j);
      node_sum[n] = node_sum[2*n] + node_sum[2*n+1];
   }
   
   void update(long i, long j) {
      update(1, 0, N-1, i, j);
   }
   
   long sum(size_t n, long b, long e, long i, long j) {
      if (b > j || e < i) return 0;
      if (i <= b && e <= j) {
         return node_sum[n];
      }
      
      propagate(n, b, e);
      
      long sum1 = sum(2*n, b, (b+e)/2, i, j);
      long sum2 = sum(2*n+1, (b+e)/2+1, e, i, j);
      
      return sum1 + sum2;
   }
   
   long sum(long i, long j) {
      return sum(1, 0, N-1, i, j);
   }
};

int main() {
   // Ίδιος κώδικας με πριν..
   
   SegTree x_ds(X), y_ds(Y), z_ds(Z);
}
```