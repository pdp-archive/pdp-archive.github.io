#include <cstdio>
using namespace std;

const size_t MAXN = 1000000;

long A[MAXN];

int main() {
   freopen("xxx.in", "r", stdin);
   freopen("xxx.out", "w", stdout);
   long N;
   scanf("%ld", &N);
   for (long i = 0; i < N; i++)
      scanf("%ld", &A[i]);
   long K = 0;
   for (long i = 0; i < N; i++) {
      bool ok = true;
      for (long j = i + 1; j < N; j++) {
         if (A[j] >= A[i]) {
            ok = false;
            break;
         }
      }
      if (ok)
         K++;
   }
   printf("%ld\n", K);
   return(0);
}
