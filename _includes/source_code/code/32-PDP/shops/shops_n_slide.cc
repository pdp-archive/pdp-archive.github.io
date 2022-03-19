#include <cstdio>
#include <algorithm>

const long MAXN = 2000000;
using namespace std;

long N, K, ans, A[MAXN+5], maxUpTo[MAXN+5];

int main() {
  freopen("shops.in","r",stdin);
  freopen("shops.out","w",stdout);
  scanf("%ld %ld", &N, &K);
  for(long i=1; i<=N; ++i) 
    scanf("%ld", &A[i]);

  for(long shopleft=0, i=1; i<=N-K; ++i){
      shopleft += A[i];
      if(i > K){
          //το shopleft έχει άθροισμα Κ+1 διαδοχικών θέσεων. 
          //Αφαίρεσε την παλιότερη.
          shopleft -= A[i-K];
      }
      maxUpTo[i] = max(shopleft,maxUpTo[i-1]);
  }
  for(long shopright=0, i=N; i>K; --i){
      shopright += A[i];
      if(i <= N-K){
          //το shopright έχει άθροισμα Κ+1 διαδοχικών θέσεων. 
          //Αφαίρεσε την παλιότερη.
          shopright -= A[i+K];
      }
      ans = max(ans, maxUpTo[i-1]+shopright);
  }
  printf("%ld\n", ans);
  return 0;
}
