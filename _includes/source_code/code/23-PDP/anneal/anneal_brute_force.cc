#include <algorithm>
#include <cstdio>
#include <vector>

typedef long long ll;

const long MAXN = 50'000;
const ll MAXV = 10'000'000LL * 2 * (MAXN + 1);
long a[MAXN];

long N;

ll solve(long pos, ll temp) {
   if (pos == N) return 0;
   if (a[pos] >= temp) return solve(pos+1, temp) + (a[pos] - temp);
   ll one = solve(pos + 1, temp) + 2 * a[pos];
   ll two = solve(pos + 1, a[pos]);
   return std::min(one, two);
}

int main() {
   FILE *fi = fopen("anneal.in", "r");
   fscanf(fi, "%ld", &N);
   long max_a = 0;
   for (long i = 0; i < N; ++i) {
      fscanf(fi, "%ld", &a[i]);
      max_a = std::max(max_a, a[i]);
   }
   fclose(fi);
   
   ll mn = MAXV;
   for (long i = 0; i <= max_a; ++i) {
      ll candidate = solve(0, i);
      mn = std::min(mn, candidate);
   }
   
   FILE *fo = fopen("anneal.out", "w");
   fprintf(fo, "%lld\n", mn);
   fclose(fo);
   return 0;
}
