/* Από το μαθητή Μαντουλίδη Χρήστο Απόστολο */
          
#include <cstdio>
using namespace std;
int N, M;


int main() {
  FILE *fIn, *fOut;
  int a, b, m, i;
  int L;
  int ans; 
  
  if ((fIn = fopen("balls.in", "r")) == NULL) return 1;
  fOut = fopen("balls.out", "w");
  fscanf(fIn, "%d", &L);
  while (L--) {
    fscanf(fIn, "%d %d", &N, &M);
    ans = 0;
    a = 1, b = N;
    while (a <= b && a < N) {
      m = (a+b)/2;
      ++ans;
      if (m >= M) {
        for (i = a; i <= M && i < m && i < N; ++i)
          ++ans;
        break;
      } else {
        a = m+1;
      }
    }
    fprintf(fOut, "%d\n", ans);
  }
  fclose(fIn);
  fclose(fOut);
  return 0;
}

