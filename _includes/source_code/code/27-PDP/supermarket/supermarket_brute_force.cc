#include <cstdio>

using namespace std;

const int MAXN = 100005;

int N, M, K;
int items[MAXN];
bool moved[MAXN];
int best_score = 0;

int calculate_total_score(int total_moved) {
  int current_moved = 0;
  int score = 0;

  for (int i = 1; i <= N; ++i) {
    int final_pos = -1;

    if (moved[i]) {
      current_moved++;
      // Τα αντικείμενα k που μετακινήθηκαν μετά από το i είναι total_moved - current_moved
      // άρα N - k = N - (total_moved - current_moved) = N - total_moved + current_moved.
      final_pos = N - total_moved + current_moved;
    } else {
      final_pos = i - current_moved;
    }

    if (final_pos % K == 0) {
      score += items[i];
    }
  }

  return score;
}

void iterate(int pos, int total_moved) {
  // 'Οταν θέσουμε το moved για όλα τα αντικείμενα μπορούμε να υπολογίσουμε
  // την συνολική αξία των δωροεπιταγών.
  if (pos == N + 1) {
    int score = calculate_total_score(total_moved);
    if (score > best_score) {
      best_score = score;
    }
    return;
  }

  moved[pos] = 0;
  iterate(pos + 1, total_moved);

  if (total_moved == M) return;
  moved[pos] = 1;
  iterate(pos + 1, total_moved + 1);
}

int main()
{
  FILE *fin = fopen("supermarket.in", "r");
  FILE *fout = fopen("supermarket.out", "w");

  fscanf(fin, "%d %d %d", &N, &M, &K);
  if (M > N)
    M = N;
  for (int i = 1; i <= N; ++i)
    fscanf(fin, "%d", items + i);
  fclose(fin);

  iterate(1, 0);

  fprintf(fout, "%d\n", best_score);
  fclose(fout);
}
