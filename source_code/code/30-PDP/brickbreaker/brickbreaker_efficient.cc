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
