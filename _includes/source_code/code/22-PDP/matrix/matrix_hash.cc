#include <cstdio>

const size_t MAXN = 1024;
const size_t MAXM = 65536;

typedef long long ll;

char A[MAXN];
char B[MAXM];

ll range = 222;
ll base = (1 << 31) - 1;

// Μετατρέπει τους χαρακτήρες από το [-127,+127] 
// στο [0, 221] (αφού η εκφώνηση μας δίνει ότι οι χαρακτήρες
// είναι μεταξύ [33, 254]
int norm_char(char c) {
   return c + 256 - 33;
}

// Προσθέτει έναν χαρακτήρα στο hash.
ll add_hash(char c, ll hash) {
   return (norm_char(c) + hash * range) % base;
}

int main() {
   long N, M;
   FILE *fi = fopen("matrix.in", "r");
   fscanf(fi, "%ld\n", &N);
   long long hash_A = 0;
   for (long i = 0; i < N; ++i) {
      A[i] = fgetc(fi);
      hash_A = add_hash(A[i], hash_A); 
   }
   
   fscanf(fi, "%ld\n", &M);
   for (long i = 0; i < M; ++i) {
      B[i] = fgetc(fi);
   }
   long found_pos = -1;
   // Υπολογίζουμε το rolling hash των πρώτων N στοιχείων
   // και την N-οστή δυναμη της range.
   long long pow = 1, hash_B = 0;
   for (long i = 0; i < N; ++i) {
      pow = (pow * range) % base;
      hash_B = add_hash(B[i], hash_B);
   }
   // Δοκιμάζουμε κάθε δυνατή υπο-συμβολοσειρά μήκους N, αν έχει
   // το ίδιο hash με την A.
   for (long i = N; i <= M; ++i) {
      if (hash_B == hash_A) {
         // Ελέγχουμε ότι όντως 
         // Στα δοσμένα testcases, ακόμα και αν αφαιρέσουμε τον
         // έλεγχο ο κώδικας τα περνάει επιτυχώς.
         bool found_diff = false;
         for (long j = 0; j < N; ++j) {
            if (A[j] != B[i - N + j]) {
               found_diff = true;
               break;
            }
         }
         if (!found_diff) found_pos = i + 1 - N;
         break;
      }
      if (i < M) {
         hash_B = add_hash(B[i], hash_B);
         // Αφαιρούμε τον i - N χαρακτήρα ώστε το 
         // hash_B να κρατάει το hash B[i-N+1, i].
         hash_B = (base + (hash_B - pow * norm_char(B[i - N])) % base) % base;
      }
   }
   FILE *fo = fopen("matrix.out", "w");
   if (found_pos == -1) fprintf(fo, "F\n");
   else fprintf(fo, "%ld\n", found_pos);
   return 0;
}
