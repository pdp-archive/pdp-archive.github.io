#include<bits/stdc++.h>
const long MAXN = 1000000;
using namespace std;

long N, K, A[MAXN+5];

int main() {
  freopen("longsumk.in","r",stdin);
  freopen("longsumk.out","w",stdout);
  scanf("%ld %ld", &N, &K);
  long left=1, sum=0, ans=0;
  for(long right=1; right<=N; ++right) {
    scanf("%ld", &A[right]);
    sum += A[right];
    while (sum - A[left] >= K) {
      sum -= A[left];
      ++left;
    }
    if (sum==K && ans < right-left+1)
      ans = right-left+1;
  }

  printf("%ld\n", ans);
  return 0;
}
