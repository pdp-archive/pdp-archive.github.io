#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
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
   Z = std::min(Z, N);
   Y = std::min(Y, N - Z);
   X = std::min(X, N - Z - Y);
   
   std::vector<Score> scores(N);
   for(long i = 0; i < N; ++i) {
      fscanf(in, "%ld%ld%ld", &scores[i].A, &scores[i].B, &scores[i].C);
   }
   fclose(in);
   
   std::sort(scores.begin(), scores.end(), [](const Score& one, const Score& two) {
      return one.B - one.A > two.B - two.A;
   });
   
   // Βρίσκουμε μία λύση μόνο με τα χάλκινα και τα ασημένια.
   ll ans = 0;
   std::vector<int> contract(N, 0);
   // Κρατάμε τα κόστη του να αναβαθμίσουμε ένα συμβόλαιο σε καλύτερο σε ουρές προτεραιότητας.
   std::priority_queue<std::pair<ll /* score */, long /* id */>> 
      from_a_to_c, from_b_to_c, from_a_to_b;
   for (long i = 0; i < N; ++i) {
      if (i < Y) {
         ans += scores[i].B;
         contract[i] = 1;
         from_b_to_c.push({ scores[i].C - scores[i].B, i });
      }
      else {
         ans += scores[i].A;
         from_a_to_c.push({ scores[i].C - scores[i].A, i });
         from_a_to_b.push({ scores[i].B - scores[i].A, i });
      }
   }
   
   // Προσθέτουμε ένα ένα τα χρυσά.
   for (long i = 0; i < Z; ++i) {
      // Περίπτωση 1η: Αλλάζουμε ένα χάλκινο σε χρυσό.
      ll score_1 = 0;
      if (!from_a_to_c.empty()) score_1 = from_a_to_c.top().first;
      
      // Περίπτωση 2η: Αλλάζουμε ένα ασημένιο σε χρυσό.
      ll score_2 = 0;
      if (!from_b_to_c.empty() && !from_a_to_b.empty()) {
         score_2 = from_b_to_c.top().first + from_a_to_b.top().first;
      }
      if (score_1 >= score_2) {
         ans += score_1;
         contract[from_a_to_c.top().second] = 2;
      } else {
         ans += score_2;
         contract[from_b_to_c.top().second] = 2;
         long id2 = from_a_to_b.top().second;
         contract[id2] = 1;
         from_b_to_c.push({ scores[id2].C - scores[id2].B, id2 });
      }
      
      // Βγάζουμε τα στοιχεία που δεν είναι πια valid.
      while (!from_a_to_c.empty() && contract[from_a_to_c.top().second] != 0) from_a_to_c.pop();
      while (!from_a_to_b.empty() && contract[from_a_to_b.top().second] != 0) from_a_to_b.pop();
      while (!from_b_to_c.empty() && contract[from_b_to_c.top().second] != 1) from_b_to_c.pop();
   }
   
   FILE *out= fopen("hiring.out", "w");
   fprintf(out, "%lld\n", ans);
   fclose(out);
   
   return 0;
}
