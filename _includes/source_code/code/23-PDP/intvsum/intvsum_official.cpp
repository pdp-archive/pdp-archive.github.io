#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
  int N, M, i, sum;
  FILE *f;
  
  f = fopen("intvsum.in", "rt");
  fscanf(f, "%d\n", &N);
  int A[N+1], B[N+1];
  for (i=1; i<=N; i++)
    fscanf(f, "%d", &(A[i]));
  fclose(f);

  sum = A[N-1];
  M=1;
  for (i=2; i<=N-1; i++) {
    if (sum-A[N-i] > 0) {
      B[M]=sum-A[N-i]; 
      if (B[M] == A[N]) break;
      M++;
    }
    sum+=A[N-i];
  }
   
  if (i<N)
    i=N;
  else {
    M--;
    sort(B+1, B+1+M); 
    i=N; sum=A[N];
    while (i > 3) {
      i--;
      sum+=2*A[i]-A[i+1]; 
      if (binary_search(B+1, B+1+M, sum)) break;
    }
    if (i == 3)
      i=0;
  }

  f = fopen("intvsum.out", "wt");
  fprintf(f, "%d\n", i);
  fclose(f);
}
