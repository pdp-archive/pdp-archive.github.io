#include <cstdio>

#define MAX 1000000
int count[MAX+1];

using namespace std;

int main ()
{
#ifdef CONTEST
  freopen("sumx.in", "rt", stdin);
  freopen("sumx.out", "wt", stdout);
#endif

  int N, X;
  scanf("%d %d", &N, &X);
  int pairs = 0;
  for (int i=0; i<N; i++) {
    int a;
    scanf("%d", &a);
    if (0 <= X-a && X-a <= MAX) pairs += count[X-a];
    count[a]++;
  }
  printf("%d\n", pairs);  
  return 0;
}
