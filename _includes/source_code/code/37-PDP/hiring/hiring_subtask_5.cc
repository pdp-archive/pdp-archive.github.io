#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

typedef long long ll;

struct Score {
   long A, B, C; 
};

int main(){
   long P, N, X, Y, Z;
   
   FILE *in = fopen("hiring.in", "r");
   fscanf(in, "%ld\n", &P);
   fscanf(in, "%ld %ld %ld %ld\n", &N, &X, &Y, &Z);
   
   std::vector<Score> scores(N);
   for(long i = 0; i < N; ++i) {
      fscanf(in, "%ld%ld%ld", &scores[i].A, &scores[i].B, &scores[i].C);
   }
   fclose(in);
   
   std::sort(scores.begin(), scores.end(), [](const Score& one, const Score& two) {
      return one.B - one.A > two.B - two.A;
   });
   
   ll base = 0, ans = 0;
   for (long i = 0; i < N; ++i) {
      if (i < Y) base += scores[i].B;
      else base += scores[i].A;
   }
   
   // Δοκιμάζουμε όλες τις πιθανότητες για το χρυσό συμβόλαιο.
   for (long i = 0; i < N; ++i) {
      ll cur_ans = base;
      if (i >= Y) {
         // Αλλάζουμε ένα χάλκινο σε χρυσό.
         cur_ans += scores[i].C - scores[i].A;
      } else {
         // Αλλάζουμε ένα ασημένιο σε χρυσό. 
         // Επίσης αυτό μας επιτρέπει να αλλάζουμε ένα χάλκινο σε ασημένιο (και διαλέγουμε
         // αυτό με την μέγιστη διαφορά (που δεν έχουμε χρησιμοποιήσει).
         cur_ans += scores[i].C - scores[i].B + scores[Y].B - scores[Y].A;
      }
      ans = std::max(ans, cur_ans);
   }
   
   FILE *out= fopen("hiring.out", "w");
   fprintf(out, "%lld\n", ans);
   fclose(out);
   
   return 0;
}
