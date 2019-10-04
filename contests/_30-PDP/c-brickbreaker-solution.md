---
layout: solution
codename: brickbreaker
---

## Επεξήγηση εκφώνησης

Μας δίνεται ένας πίνακας $$N \times M$$ που περιγράφει τα τούβλα σε έναν τοίχο και μία ακολουθία από τούβλα που σπάμε ένα ένα. Για κάθε τούβλο που σπάμε, πρέπει να βρούμε πόσα τούβλα πέφτουν.

Το πρόβλημα αυτό είναι ουσιαστικά ένα πρόβλημα θεωρίας γράφων. Μπορούμε να μοντελοποιήσουμε έναν τοίχο ως έναν γράφο όπου οι κορυφές είναι τα τούβλα και οι ακμές δηλώνουν συνδέσεις μεταξύ των γειτονικών τούβλων. Στο παράδειγμα, ο γράφος είναι ως εξής:

<center>
<img src="/assets/30-pdp-c-brickbreaker-example-representation.svg" width="300" height="300">
</center>

Η ερώτηση λοιπόν που έχουμε είναι αν αφαιρέσουμε μία κορυφή, πόσες κορυφές δεν συνδέονται (άμεσα ή έμμεσα) με μία της πρώτης γραμμής. Για παράδειγμα, αν αφαιρέσουμε την κόκκινη κορυφή τότε για τις πράσινες κορυφές δεν υπάρχει μονοπάτι προς μία κορυφή της πρώτης γραμμής. 

<center>
<img src="/assets/30-pdp-c-brickbreaker-example-removal.svg" width="300" height="300">
</center>

## Αργή λύση

**Παρατήρηση:** Έστω ότι $$\mathit{connected\_to\_top}(q)$$ είναι το πλήθος των κορυφών που συνδέονται με την πρώτη γραμμή αφού αφαιρέσουμε την $$q$$-οστή κορυφή. Η απάντηση στο $$q$$-οστό ερώτημα είναι $$\mathit{connected\_to\_top}(q-1) - \mathit{connected\_to\_top}(q) - 1$$ (μείον ένα για την ίδια την κορυφή). 

Μένει να βρούμε έναν τρόπο να υπολογίζουμε $$\mathit{connected\_to\_top}(q)$$. Αυτό είναι απλά το άθροισμα των μεγεθών των συνεκτικών συνιστωσών των στοιχείων της πρώτης γραμμής. Το μέγεθος κάθε συνιστώσας μπορούμε να το βρούμε σε γραμμικό χρόνο στο μέγεθος του γράφου χρησιμοποιώντας αναζήτηση κατά βάθος ή κατά πλάτος. Επομένως, για κάθε ερώτημα, αφαιρούμε την κορυφή, υπολογίζουμε το $$\mathit{connected\_to\_top}(q)$$ και παίρνουμε τη διαφορά από το προηγούμενο.

Υπάρχουν $$Q$$ ερωτήματα και το κάθε ερώτημα θέλει $$O(NM)$$ χρόνο (μία αναζήτηση κατά βάθος/πλάτος). Συνεπώς, ο αλγόριθμος χρειάζεται $$O(QNM)$$ χρόνο και $$O(NM)$$ μνήμη. Αυτό είναι αρκετό για το $$50\%$$ των testcases. 

**Σημείωση 1:** Για να απλοποιήσουμε την υλοποίηση, προσθέτουμε μία γραμμή γεμάτη τούβλα πάνω από την πρώτη γραμμή. Αυτό ενώνει τις συνεκτικές συνιστώσες όλων των κορυφών της πρώτης γραμμής σε μία.

**Σημείωση 2:** Για να απλοποιήσουμε την υλοποίηση, κρατάμε έναν πίνακα από $$\mathit{deltas} = \lbrace (0, 1), (0, -1), (1, 0), (-1, 0) \rbrace$$ που δείχνει πόσο πρέπει να προσθέσουμε στις συντεταγμένες της κορυφής $$(x, y)$$ για να πάρουμε τους $$4$$ πιθανούς της γείτονες.

```c++
#include <algorithm>
#include <cstdio>
#include <stack>
#include <vector>

const size_t MAXN = 1000 + 1;
const size_t MAXM = 1000;

char board[MAXN][MAXM];

// Πίνακας που δίνει τους αιρθμούς που πρέπει να 
// προσθέσουμε στις συντεταγμένες μίας θέσης για να
// πάρουμε τις πιθανές γειτονικές της.
const std::vector<std::pair<long, long>> deltas({
   {-1, 0}, {1, 0}, {0, -1}, {0, 1}
});

long N, M;

// Βοηθητική συνάρτηση που ελέγχει αν οι δοσμένες συντεταγμένες
// ανήκουν στον πίνακα.
bool isWithinBounds(long x, long y) {
   return 0 <= x && x < N && 0 <= y && y < M;
}

// Βοηθητική συνάρτηση που ελέγχει αν μία θέση έχει τούβλο.
bool hasBrick(long x, long y) {
   return board[x][y] == '#';
}

// Βοηθητικός πίνακας για την αναζήτηση κατά βάθος.
bool visited[MAXN][MAXM];

// Βοηθητική συνάρτηση για καθαρισμού του πίνακα μεταξύ
// δύο αναζητήσεων κατά βάθος.
void resetVisited() {
   for (long i = 0; i < N; ++i) {
      for (long j = 0; j < M; ++j) {
         visited[i][j] = false;
      }
   }
}

long countBricksAtTop() {
   resetVisited();
   long count = 0;
   std::stack<std::pair<long, long>> s;
   // Ξεκινάμε μία αναζήτηση κατά βάθος από το (0, 0), 
   // που συνδέεται με όλες τις κορυφές της πρώτης γραμμής.
   s.push(std::make_pair(0, 0));
   while (!s.empty()) {
      long x = s.top().first;
      long y = s.top().second;
      s.pop();
      // Διατρέχουμε όλους τους πιθανούς γείτονες και 
      // επισκεπτόμαστε αυτούς που έχουν τούβλα και είναι στα
      // πλαίσια και δεν τους έχουμε επισκεφτεί.
      for (const auto& delta : deltas) {
         long neigh_x = x + delta.first;
         long neigh_y = y + delta.second;
         if (isWithinBounds(neigh_x, neigh_y) && hasBrick(neigh_x, neigh_y) 
             && !visited[neigh_x][neigh_y]) {
            s.push(std::make_pair(neigh_x, neigh_y));
            visited[neigh_x][neigh_y] = true;
            count++;
         }
      }
   }
   return count;
}

int main() {
   FILE *fi = fopen("brickbreaker.in", "r");
   fscanf(fi, "%ld %ld\n", &N, &M);
   for (long i = 0; i < N; ++i) {
      for (long j = 0; j < M; ++j) {
         fscanf(fi, "%c", &board[i + 1][j]);
      }
      fscanf(fi, "\n");
   }
   // Προσθέτουμε την μία ψεύτικη γραμμή που συνδέει
   // όλα τα τούβλα της πρώτης γραμμής.
   ++N;
   for (long j = 0; j < M; ++j) {
      board[0][j] = '#';
   }
   
   FILE *fo = fopen("brickbreaker.out", "w");
   long Q;
   fscanf(fi, "%ld", &Q);
   long prev_count = countBricksAtTop();
   for (long q = 0; q < Q; ++q) {
      long x, y;
      fscanf(fi, "%ld %ld", &x, &y);
      board[x][y-1] = '.';
      long current_count = countBricksAtTop();
      fprintf(fo, "%ld\n", prev_count - current_count - 1);
      prev_count = current_count;
   }
   fclose(fi);
   fclose(fo);
   return 0;
}
```

## Βέλτιστη λύση

Μπορούμε να επιταχύνουμε τον παραπάνω αλγόριθμο. Γενικά, υπάρχουν πιο γρήγοροι αλγόριθμοι για όταν προσθέτουμε κορυφές παρά όταν αφαιρούμε. Γι'αυτό αξίζει να δούμε το πρόβλημα ανάποδα. Τι θα γινόταν αν ξεκινούσαμε με όλες τις $$Q$$ κορυφές αφαιρεμένες και τις προσθέταμε μία μία; Θα θέλαμε να μετρήσουμε πόσες κορυφές που συνδέονται με την κορυφή που προσθέτουμε δεν ήταν συνδεδεμένες με την πρώτη γραμμή. 

Μπορούμε να το κάνουμε αυτό αποδοτικά με τη δομή δεδομένων union-find. Κρατάμε ένα σύνολο για κάθε συνεκτική συνιστώσα από τούβλα και διατηρούμε και το μέγεθος της συνιστώσας. Η union-find μας επιτρέπει γρήγορα να δούμε αν δύο κορυφές ανήκουν στο ίδιο σύνολο. Όταν προσθέτουμε μία κορυφή τότε κοιτάμε ποιες από τις τέσσερις γειτονικές συνιστώσες δεν συνδέονται με τη συνιστώσα της πάνω γραμμής και αθροίζουμε τα μεγέθη τους. Αυτό μας δίνει το πλήθος των κορυφών που θα πέσουν όταν αφαιρεθεί το τούβλο (γιατί δεν έχουν άλλον τρόπο που συνδέονται με την πρώτη γραμμή).

Πιο αναλυτικά, τα βήματα είναι τα εξής:

 1. Αφαιρούμε τα τούβλα των ερωτημάτων.
 2. Δημιουργούμε ένα σύνολο στη union-find δομή για κάθε συνιστώσα από τούβλα. Το σύνολο κρατάει και το μέγεθος της κάθε συνιστώσας. Αυτό το κάνουμε κρατώντας το πεδίο $$\mathit{size}$$ που το ανανεώνουμε κάθε φορά που ενώνουμε δύο σύνολα. Στο παράδειγμα, τα αρχικά σύνολα (για τα τούβλα), είναι τα εξής:
<center>
<img src="/assets/30-pdp-c-brickbreaker-fast-init-example.svg" height="300">
</center>
 3. Διατρέχουμε τα ερωτήματα από το τελευταίο στο πρώτο: 
    1. Για το τούβλο του ερωτήματος, ενώνουμε τις γειτονικές συνιστώσες (οι οποίες είναι διαφορετικές της συνιστώσας της πάνω γραμμής) με την συνιστώσα του τούβλου.
    2. Σε αυτό το σημείο, η συνιστώσα του τούβλου έχει όλα τα τούβλα που θα πέσουν αν αφαιρεθεί. Άρα βρίσκουμε το μέγεθος της συνιστώσας (μείον ένα) και το κρατάμε ως την απάντηση.
    3. Ενώνουμε τη συνιστώσα του τούβλου με τη συνιστώσα της πρώτης γραμμής (ώστε να απαντήσουμε σωστά τα μετέπειτα ερωτήματα). Για παράδειγμα, στο δεύτερο τούβλο έχουμε την εξής αναπαράσταση:

<center>
<img src="/assets/30-pdp-c-brickbreaker-fast-example.svg" height="300">
</center>
    
Η ένωση στην union-find θέλει χρόνο $$\alpha (N\times M)$$ (όπου $$\alpha$$ είναι μία συνάρτηση που μεγαλώνει πολύ πιο αργά και από λογαριθμική συνάρτηση). Επομένως, ο αλγόριθμος θέλει $$O(N\times M + Q a(N\times M))$$ χρόνο και $$O(N\times M)$$ μνήμη.

```c++
#include <algorithm>
#include <cstdio>
#include <vector>

const size_t MAXN = 1000 + 1;
const size_t MAXM = 1000;
const size_t MAXQ = MAXN * MAXM;

char board[MAXN][MAXM];

std::pair<long, long> queries[MAXQ];
long answers[MAXQ];

// Τιμές για την union-find.
long size[MAXN * MAXM]; // Number of elements in the component.
long par[MAXN * MAXM]; // Parent of element.
long height[MAXN * MAXM]; // Height of component.

const std::vector<std::pair<long, long>> deltas({
   {-1, 0}, {1, 0}, {0, -1}, {0, 1}
});

long N, M; 

// Βοηθητική συνάρτηση που μετατρέπει τις συντεταγμένες
// σε έναν ακέραιο.
long id(long i, long j) {
   return i * M + j;
}

// Συναρτήσεις για την union-find. 

long findParent(long id) {
   if (id == par[id]) return id;
   return par[id] = findParent(par[id]);
}

void unite(long id1, long id2) {
   long par1 = findParent(id1);
   long par2 = findParent(id2);
   
   if (par1 == par2) return;
   if (height[par1] < height[par2]) {
      std::swap(par1, par2);
   }
   par[par2] = par1;
   size[par1] += size[par2];
   if (height[par1] == height[par2]) {
      height[par1]++;
   }
}
     
void initializeUnionFind() {
   for (long i = 0; i < N * M; ++i) {
      par[i] = i;
     size[i] = 1;
   }
}

bool isWithinBounds(long x, long y) {
   return 0 <= x && x < N && 0 <= y && y < M;
}

bool hasBrick(long x, long y) {
   return board[x][y] == '#';
}

bool isConnectedToTop(long id) {
   // Το (0, 0) ανήκει στη συνιστώσα της πρώτης
   // γραμμής, άρα αρκεί να ελέγξουμε αν έχουν ίδια
   // roots.
   return findParent(id) == findParent(0);
}

void connectToTop(long id) {
   unite(0, id);
}

// Ενώνουμε την κορυφή (x, y) με τις γειτονικές τις
// συνιστώσες (αν έχουν τούβλα).
void connectToNeighs(long x, long y) {
   long current_id = id(x, y);
   for (const auto& delta : deltas) {
      long neigh_x = x + delta.first;
     long neigh_y = y + delta.second;
     if (!isWithinBounds(neigh_x, neigh_y) || !hasBrick(neigh_x, neigh_y)) continue;
     long neigh_id = id(neigh_x, neigh_y);
     unite(current_id, neigh_id);
   }
}
     

int main() {
   FILE *fi = fopen("brickbreaker.in", "r");
   fscanf(fi, "%ld %ld\n", &N, &M);
   for (long i = 0; i < N; ++i) {
      for (long j = 0; j < M; ++j) {
        fscanf(fi, "%c", &board[i + 1][j]);
     }
     fscanf(fi, "\n");
   }
   ++N;
   for (long j = 0; j < M; ++j) {
      board[0][j] = '#';
   }
   
   // 1. Διαβάζουμε τα ερωτήματα και αφαιρούμε
   // τα τούβλα των ερωτημάτων από τον πίνακα.   
   long Q;
   fscanf(fi, "%ld", &Q);
   for (long q = 0; q < Q; ++q) {
      long x, y;
      fscanf(fi, "%ld %ld", &x, &y);
     queries[q] = std::make_pair(x, y - 1);
     board[x][y - 1] = '.';
   }
   fclose(fi);
   
   // 2. Φτιάχνουμε τα αρχικά σύνολα της union-find.
   initializeUnionFind();
   for (long i = 0; i < N; ++i) {
      for (long j = 0; j < M; ++j) {
       // Ενώνουμε κάθε τούβλο με τα διπλανά του.
        if (hasBrick(i, j)) {
          connectToNeighs(i, j);
       }
      }
   }
   
   // 3. Διατρέχουμε τα ερωτήματα ανάποδα.
   for(long q = Q - 1; q >= 0; --q) {
      long x = queries[q].first;
     long y = queries[q].second;
     long current_id = id(x, y);
     for (const auto& delta : deltas) {
         long neigh_x = x + delta.first;
        long neigh_y = y + delta.second;
       if (!isWithinBounds(neigh_x, neigh_y) 
          || !hasBrick(neigh_x, neigh_y)) 
             continue;
        long neigh_id = id(neigh_x, neigh_y);
       // Βρίσκουμε τις γειτονικές συνιστώσες που
       // δεν είναι ίσες με τη συνιστώσα της πρώτης γραμμής 
       // και την ενώνουμε με τη συνιστώσα του τούβλου.
       if (!isConnectedToTop(neigh_id)) {
          unite(current_id, neigh_id);
       }
      }
     // Το μέγεθος της συνιστώσας -1 είναι το πλήθος των τούβλων
     // που θα πέσουν.
     answers[q] = size[findParent(current_id)] - 1;
     // Ενώνουμε τη συνιστώσα του τούβλου με τη συνιστώσα της
     // πρώτης γραμμής.
     connectToTop(current_id);
     board[x][y] = '#';
   }
   
   // Τυπώνουμε τις απαντήσεις.
   FILE *fo = fopen("brickbreaker.out", "w");
   for (long q = 0; q < Q; ++q) {
      fprintf(fo, "%ld\n", answers[q]);
   }
   fclose(fo);
   return 0;
}

``` 
