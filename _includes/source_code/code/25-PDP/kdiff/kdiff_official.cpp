#undef DEBUG

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) do ; while(0)
#define NDEBUG
#endif

#include <assert.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main ()
{
#ifdef CONTEST
  freopen("kdiff.in", "rt", stdin);
  freopen("kdiff.out", "wt", stdout);
#endif

  int N;
  long long K;
  
  scanf("%d %lld\n", &N, &K);
  int A[N];
  for (int i=0; i<N; i++)
    scanf("%d", &(A[i]));

  sort(A, A+N);

  long long total = (long long) N*(N-1)/2;
  K = total-K+1;
  int high = A[N-1] - A[0];
  int low = 1;
  int res = 0;
  do {
    long long large = 0;
    int mid = (high+low)/2;
    int j = N-1;
    for (int i = N-1; i >= 0; i--) {
      while (j >= 0 && A[i] - A[j] < mid) j--;
      large += j+1;
    }
    if (large >= K) {
      res = mid;
      low = mid+1;
    }
    else
      high = mid-1;
  } while (low <= high);

  printf("%d\n", res);
  return 0;
}
