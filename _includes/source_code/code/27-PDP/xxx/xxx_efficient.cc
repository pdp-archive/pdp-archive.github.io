#include <cstdio>
using namespace std;

const size_t MAXN = 1000000;

long A[MAXN];

int main() {
   freopen("xxx.in", "r", stdin);
   freopen("xxx.out", "w", stdout);
   long N;
   scanf("%d", &N);
   for (long i = 0; i < N; i++)
      scanf("%ld", &A[i]);
   long K = 1, mx = A[N - 1];
   for (long i = N - 2; i >= 0; i--) {
      if (A[i] > mx) {
         K++;
         mx = A[i];
      }
   }
   printf("%ld\n", K);
   return(0);
}
