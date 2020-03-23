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
