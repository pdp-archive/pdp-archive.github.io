#include <cstdio>
#include <vector>

typedef long long ll;

ll counts[10 /* πλήθος ψηφίων */][82 /* άθροισμα ψηφίων */]; // Πλήθος αριθμών

int main() {
   FILE *fi = fopen("luckyagain.in", "r");
   long N;
   fscanf(fi, "%ld", &N);
   
   std::vector<std::vector<int>> digits(N);
   std::vector<int> digit_sum(N, 0);
   
   for (int i = 0; i < N; ++i) {
      long temp;
      fscanf(fi, "%ld", &temp);
      
      // Βρίσκουμε τα ψηφία ενός αριθμού και το άθροισμά τους.
      while (temp > 0) {
         int cur_digit = temp % 10;
         digit_sum[i] += cur_digit;
         digits[i].push_back(cur_digit);
         temp /= 10;
      }
      
      // (Προ)-ϋπολογισμός του πίνακα counts.
      ++counts[digits[i].size()][digit_sum[i]];
   }
   fclose(fi);
   
   ll total_count = 0;
   // Οι αριθμοί με το ίδιο πλήθος ψηφίων θα μετρηθούν δύο φορές. Επομένως κρατάμε 
   // το πλήθος αυτών ώστε να το αφαιρέσουμε το μισό από το σύνολο.
   ll same_digit_count = 0;
   for (int j = 0; j < N; ++j) {
      const int sum_of_digits = digit_sum[j];
      const int len = digits[j].size();
      
      // Βρίσκουμε το πλήθος των ζευγαριών που έχουν τον j-οστό αριθμό
      // σαν πρώτο μέρος και μέσο η θέση (len - i).
      int suffix_sum = 0;
      for (int i = 0; 2 * i < len; ++i) {
         ll cur_count = counts[len - 2 * i][sum_of_digits - 2 * suffix_sum];
         total_count += cur_count;
         if (i == 0) { // Το μέσο είναι στο τέλος του αριθμού.
            same_digit_count += cur_count - 1; // -1, για να μην μετρήσουμε τον εαυτό του.
         }
         suffix_sum += digits[j][i];
      }
      
      // Βρίσκουμε το πλήθος των ζευγαριών που έχουν τον j-οστό αριθμό
      // σαν δεύτερο μέρος και μέσο η θέση i.
      int prefix_sum = 0;
      for (int i = 0; 2 * i < len; ++i) {
         ll cur_count = counts[len - 2 * i][sum_of_digits - 2 * prefix_sum];
         total_count += cur_count;
         if (i == 0) { // Το μέσο είναι στην αρχή του αριθμού.
            same_digit_count += cur_count - 1;
         }
         prefix_sum += digits[j][len - i - 1];
      }
      
      // Αφαιρούμε τον εαυτό του απο την μέτρηση.
      total_count -= 2;
   }
   total_count -= same_digit_count / 2;
   
   FILE *fo = fopen("luckyagain.out", "w");
   fprintf(fo, "%lld\n", total_count);
   fclose(fo);
   
   return 0;
}
