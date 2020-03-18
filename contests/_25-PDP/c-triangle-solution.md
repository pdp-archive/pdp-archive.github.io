---
layout: solution
codename: triangle
---

## Brute force
Μπορούμε να δοκιμάσουμε όλα τα δυνατά μονοπάτια που ξεκινάνε από την κορυφή του τριγώνου. Αν είμαστε στο j-οστό στοιχείο της i-οστής γραμμής (για συντομία $$(i, j)$$), τότε μπορούμε είτε να πάμε στο $$(i+1, j)$$ ή στο $$(i+1, j+1)$$. 

Αφού σε κάθε βήμα υπάρχουν δύο επιλογές, θα ελέγξουμε συνολικά $$2^N$$. Αν υπολογίζουμε παράλληλα το άθροισμα, τότε γίνεται σε χρόνο $$O(2^N)$$ και χώρο $$O(N^2)$$. 

```c++
#include <algorithm>
#include <cstdio> 
#include <cstdlib>

const size_t MAXN = 1000;

int T[MAXN][MAXN];
int N;

int findMaxPath(int i, int j) {
   if (i == N) return 0; 
   if (j == N - 1) return T[i][j] + findMaxPath(i + 1, j);
   return T[i][j] + std::max(findMaxPath(i + 1, j), findMaxPath(i + 1, j + 1));
}

int main() { 
   FILE *fi = fopen("triangle.in", "r");
   fscanf(fi, "%d", &N);
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j <= i; ++j) {
         fscanf(fi, "%d", &T[i][j]);
      }
   }
   fclose(fi);
   
   FILE *fo = fopen("triangle.out", "w");
   fprintf(fo, "%d\n", findMaxPath(0, 0));
   fclose(fo);
   return 0;
}
```


## Δυναμικός προγραμματισμός

Η λύση αυτή προϋποθέτει γνώσεις δυναμικού προγραμματισμού.

Έστω $$\mathit{max\_path}[i][j]$$ το μήκος του μεγαλύτερου μονοπατιού που τελειώνει στο j-οστό στοιχείο της i-οστής γραμμής. Υπάρχουν δύο δυνατοί τρόποι να φτάσαμε σε αυτό το στοιχείο στο μεγαλύτερο μονοπάτι:

 1. Να επεκτίναμε το μεγαλύτερο μονοπάτι για το στοιχείο $$(i-1, j)$$
 2. Να επεκτίναμε το μεγαλύτερο μονοπάτι για το στοιχείο $$(i-1, j-1)$$ (αν $$j>0$$)

Το μεγαλύτερο μονοπάτι στο $$(i, j)$$, δίνεται από το

$$\mathit{max\_path}[i][j] = T[i][j] + \max{\lbrace\mathit{max\_path}[i-1][j-1], \mathit{max\_path}[i-1][j] \rbrace}$$

```c++
#include <algorithm>
#include <cstdio> 
#include <cstdlib>

const size_t MAXN = 1000;

int T[MAXN][MAXN];
int max_path[MAXN][MAXN];
int N;

int main() { 
   FILE *fi = fopen("triangle.in", "r");
   fscanf(fi, "%d", &N);
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j <= i; ++j) {
         fscanf(fi, "%d", &T[i][j]);
      }
   }
   fclose(fi);
   
   max_path[0][0] = T[0][0];
   for (int i = 1; i < N; ++i) {
      for (int j = 0; j <= i; ++j) {
         max_path[i][j] = T[i][j];
         if (j == 0) max_path[i][j] += max_path[i - 1][j];
         else max_path[i][j] += std::max(max_path[i - 1][j - 1], max_path[i - 1][j]);
      }
   }
   
   int max_path_to_bottom = max_path[N-1][0];
   for (int i = 0; i < N; ++i) {
      max_path_to_bottom = std::max(max_path[N-1][i], max_path_to_bottom);
   }

   FILE *fo = fopen("triangle.out", "w");
   fprintf(fo, "%d\n", max_path_to_bottom);
   fclose(fo);
   return 0;
}
```

**Σημείωση:** Μπορούμε να δούμε αυτόν τον αλγόριθμο σαν μία παραλλαγή του προηγούμενου, όπου υπολογίζουμε κάθε κλήση της συνάρτησης `findMaxPath` μία φορά.

Αφού υπολογίζουμε κάθε στοιχείο του $$\mathit{max\_path}$$ μόνο μία φορά, ο χρόνος που χρειάζεται ο αλγόριθμος είναι $$O(N^2)$$ και η μνήμη $$O(N^2)$$. 

## Δυναμικός προγραμματισμός με memoisation

Μπορούμε να παρατηρήσουμε ότι για τον υπολογισμό της $$i$$-οστής γραμμής χρειαζόμαστε μόνο τις τιμές της γραμμής $$i-1$$. Επομένως, καθώς διαβάζουμε το input μπορούμε να κρατάμε μόνο τις τιμές των τελευταίων δύο σειρών των $$\max\_path$$ και του $$T$$. Αυτό μειώνει τη μνήμη που χρειάζεται ο αλγόριθμος σε $$2N = O(N)$$.


```c++
#include <algorithm>
#include <cstdio> 
#include <cstdlib>

const size_t MAXN = 1000;

int T[2][MAXN];
int max_path[2][MAXN];
int N;

int main() { 
   FILE *fi = fopen("triangle.in", "r");
   fscanf(fi, "%d", &N);
   max_path[0][0] = 0;
   for (int i = 0; i < N; ++i) {
      int cur_row = (i + 1) % 2;
	  int prev_row = i % 2;
      for (int j = 0; j <= i; ++j) {
         fscanf(fi, "%d", &T[cur_row][j]);
      }
	  for (int j = 0; j <= i; ++j) {
         max_path[cur_row][j] = T[cur_row][j];
         if (j == 0) max_path[cur_row][j] += max_path[prev_row][j];
         else max_path[cur_row][j] += std::max(max_path[prev_row][j - 1], max_path[prev_row][j]);
      }
   }
   fclose(fi);
   
   int last_row = N % 2;
   int max_path_to_bottom = max_path[last_row][0];
   for (int i = 0; i < N; ++i) {
      max_path_to_bottom = std::max(max_path[last_row][i], max_path_to_bottom);
   }

   FILE *fo = fopen("triangle.out", "w");
   fprintf(fo, "%d\n", max_path_to_bottom);
   fclose(fo);
   return 0;
}
```
