#include <algorithm>
#include <cstdio>
#include <vector>

typedef long long ll;

bool is_lucky(const std::vector<int>& digitsA, const std::vector<int>& digitsB) {
   int total_length = (digitsA.size() + digitsB.size());
   if (total_length % 2 == 1) return false; // Αν έχει μονό πλήθος ψηφίων, τότε δεν είναι τυχερός.
   
   int cur_sum[2]; 
   cur_sum[1] = 0; // Το άθροισμα των ψηφίων του πρώτου μισού.
   cur_sum[0] = 0; // Το άθροισμα των ψηφίων του δεύτερου μισού.
   
   int midpoint = total_length / 2;
   for (int i = 0; i < digitsA.size(); ++i) {
      cur_sum[i < midpoint] += digitsA[i];
   }
   for (int i = 0; i < digitsB.size(); ++i) {
      cur_sum[i + digitsA.size() < midpoint] += digitsB[i];
   }

   return cur_sum[0] == cur_sum[1];
}   

int main() {
   FILE *fi = fopen("luckyagain.in", "r");
   long N;
   fscanf(fi, "%ld", &N);
   
   std::vector<std::vector<int>> digits(N);
   
   for (int i = 0; i < N; ++i) {
      long temp;
      fscanf(fi, "%ld", &temp);
      
      // Βρίσκουμε τα ψηφία ενός αριθμού.
      while (temp > 0) {
         digits[i].push_back(temp % 10);
         temp /= 10;
      }
      // Δεδομένου του υπόλοιπου κώδικα η ακόλουθη αντιστροφή δεν είναι 
      // αναγκαία (γιατί;)
      // std::reverse(digits[i].begin(), digits[i].end());
   }
   fclose(fi);
   
   // Μετράμε πόσα από τα δυνατά ζευγάρια φτιάχνουν έναν τυχερό αριθμό.
   ll total_count = 0;
   for (long i = 0; i < N; ++i) {
      for (long j = 0; j < N; ++j) {
         if (i == j) continue;
         total_count += is_lucky(digits[i], digits[j]);
      }
   }
   
   FILE *fo = fopen("luckyagain.out", "w");
   fprintf(fo, "%lld\n", total_count);
   fclose(fo);
   
   return 0;
}
