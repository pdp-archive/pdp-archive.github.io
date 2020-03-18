---
layout: solution
codename: karla
---

## Επεξήγηση εκφώνησης

Μας δίνεται ένας πίνακας $$N\times N$$ με ακέραιες τιμές και πρέπει να υπολογίσουμε πόσα συνδεδεμένα τμήματα θα μείνουν αν αφαιρέσουμε όλες τις τιμές μικρότερες ή ίσες με $$M$$.


Δύο τιμές $$A, B$$ είναι συνδεδεμένες ($$A\leftrightarrow B$$) αν:

 * H μία είναι μία από τις τέσσερις γειτονικές της άλλης.

 * Αν υπάρχει μία ακολουθία από γειτονικές τιμές $$k_1, \ldots, k_n$$ ώστε $$Α \leftrightarrow k_1 \leftrightarrow \ldots \leftrightarrow k_n \leftrightarrow B$$.

 
Αυτή η συνδεσιμότητα ορίζει έναν γράφο. Επομένως, πρέπει να μετρήσουμε τα συνεκτικά τμήματα του γράφου. 


## Αναζήτηση κατά βάθος

Ξεκινάμε από μία τιμή ($$> M$$) του πίνακα και βρίσκουμε όλες με τις οποίες συνδέεται. Το κάνουμε αυτό ξεκινώντας μία αναζήτηση-κατά-βάθος (DFS) στην τιμή. Κάθε τιμή που επισκεπτόμαστε την μαρκάρουμε, ώστε να μην την ξανα-επισκεφτούμε. Όταν δεν υπάρχουν άλλες τιμές που μπορούμε να επισκεφτούμε, συνεχίζουμε με την επόμενη τιμή μεγαλύτερη από $$M$$ και αυξάνουμε τον μετρητή τμημάτων.


Αφού στο τέλος θα επισκεφτούμε κάθε τιμή μία φορά, ο αλγόριθμος τρέχει σε $$O(N^2)$$ και χρειάζεται μνήμη $$O(N^2)$$.


Υπάρχουν δύο κλασικοί τρόποι υλοποίησης της DFS: αναδρομικά ή γραμμικά. Ο γραμμικός τρόπος έχει το (μικρό) πλεονέκτημα ότι χρησιμοποιεί μικρότερη στοίβα κλήσεων. 

```c++
#include <stdio.h>

const size_t MAXN = 100;

int values[MAXN][MAXN]; // Οι τιμές του πίνακα.
bool visited[MAXN][MAXN]; // Αν έχουμε επισκεφτεί την αντίστοιχη τιμή.

int N, M;

// Ελέγχουμε αν το στοιχείο που θα πάμε να επισκεφτούμε είναι μέσα στο
// τετράγωνο.
bool isWithinBounds(int i, int j) {
   return i >= 0 && j >= 0 && i < N && j < N;
}

void visitAndMark(int i, int j) {
   visited[i][j] = true;
   if (isWithinBounds(i+1, j) && !visited[i+1][j] && values[i+1][j] > M) {
      visitAndMark(i+1, j);
   }
   if (isWithinBounds(i-1, j) && !visited[i-1][j] && values[i-1][j] > M) {
      visitAndMark(i-1, j);
   }
   if (isWithinBounds(i, j+1) && !visited[i][j+1] && values[i][j+1] > M) {
      visitAndMark(i, j+1);
   }
   if (isWithinBounds(i, j-1) && !visited[i][j-1] && values[i][j-1] > M) {
      visitAndMark(i, j-1);
   }
}

int main() {
   FILE *fi = fopen("karla.in", "r");
   fscanf(fi, "%d%d", &N, &M);
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
         fscanf(fi, "%d", &values[i][j]);
      }
   }
   fclose(fi);
   
   int total = 0;
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
         if (!visited[i][j] && values[i][j] > M) {
            visitAndMark(i, j);
            ++total;
         }
      }
   }
   
   FILE *fo = fopen("karla.out", "w");
   fprintf(fo, "%d\n", total);
   fclose(fo);
   
   return 0;
}
```

```c++
#include <algorithm>
#include <stdio.h>
#include <stack>

const size_t MAXN = 100;

int values[MAXN][MAXN];
bool visited[MAXN][MAXN];

int N, M;

bool isWithinBounds(int i, int j) {
   return i >= 0 && j >= 0 && i < N && j < N;
}

// Κρατάμε σε μία στοίβα της τιμές που είναι να επισκεφτούμε. Κάθε στιγμή, αφαιρούμε το
// πάνω πάνω στοιχείο και βάζουμε τους γείτονές του.
void dfsIteratively(int begin_i, int begin_j) {
   std::stack<std::pair<int, int>> st;
   st.push(std::make_pair(begin_i, begin_j));
   
   while (!st.empty()) {
      int i = st.top().first;
      int j = st.top().second;
      st.pop();
      
      if (isWithinBounds(i+1, j) && !visited[i+1][j] && values[i+1][j] > M) {
         visited[i+1][j] = true;
         st.push(std::make_pair(i+1, j));
      }
      if (isWithinBounds(i-1, j) && !visited[i-1][j] && values[i-1][j] > M) {
         visited[i-1][j] = true;
         st.push(std::make_pair(i-1, j));
      }
      if (isWithinBounds(i, j+1) && !visited[i][j+1] && values[i][j+1] > M) {
         visited[i][j+1] = true;
         st.push(std::make_pair(i, j+1));
      }
      if (isWithinBounds(i, j-1) && !visited[i][j-1] && values[i][j-1] > M) {
         visited[i][j-1] = true;
         st.push(std::make_pair(i, j-1));
      }
   }
}

int main() {
   FILE *fi = fopen("karla.in", "r");
   fscanf(fi, "%d%d", &N, &M);
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
         fscanf(fi, "%d", &values[i][j]);
      }
   }
   fclose(fi);
   
   int total = 0;
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
         if (!visited[i][j] && values[i][j] > M) {
            dfsIteratively(i, j);
            ++total;
         }
      }
   }
   
   FILE *fo = fopen("karla.out", "w");
   fprintf(fo, "%d\n", total);
   fclose(fo);
   
   return 0;
}
```

Μπορούμε να απλοποίησουμε τον έλεγχο των γειτονικών με το ακόλουθο τρικ

```c++
#include <algorithm>
#include <stdio.h>
#include <vector>

const size_t MAXN = 100;

int values[MAXN][MAXN];
bool visited[MAXN][MAXN];

int N, M;

bool isWithinBounds(int i, int j) {
   return i >= 0 && j >= 0 && i < N && j < N;
}

std::vector<std::pair<int, int>> deltas({ {1, 0}, {-1, 0}, {0, 1}, {0, -1} });

void visitAndMark(int i, int j) {
   visited[i][j] = true;
   for (const auto& delta : deltas) {
      int ii = i + delta.first;
      int jj = j + delta.second;
      if (isWithinBounds(ii, jj) && !visited[ii][jj] && values[ii][jj] > M) {
         visitAndMark(ii, jj);
      }
   }
}

int main() {
   FILE *fi = fopen("karla.in", "r");
   fscanf(fi, "%d%d", &N, &M);
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
         fscanf(fi, "%d", &values[i][j]);
      }
   }
   fclose(fi);
   
   int total = 0;
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
         if (!visited[i][j] && values[i][j] > M) {
            visitAndMark(i, j);
            ++total;
         }
      }
   }
   
   FILE *fo = fopen("karla.out", "w");
   fprintf(fo, "%d\n", total);
   fclose(fo);
   
   return 0;
}
```

