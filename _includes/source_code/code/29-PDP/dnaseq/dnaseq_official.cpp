#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 1000000

char A[MAX+2], B[MAX+2];

int main() {
  freopen("dnaseq.in", "rt", stdin);
  freopen("dnaseq.out", "wt", stdout);
  int N;
  scanf("%d\n", &N);
  fgets(A, MAX+2, stdin);
  fgets(B, MAX+2, stdin);
  int L = 0;
  while (L < N && A[L] == B[L]) L++;
  if (L == N)
    printf("0\n");
  else {
    int M = N-1;
    while (A[M] == B[M]) M--;
    bool good = true;
    int i, j;
    for (i = L, j = M; good && i <= j; i++, j--) good = A[i] == B[j];
    if (good)
      printf("%d\n", M-L);
    else
      printf("no\n");
  }
}
