#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

typedef enum { UNKNOWN=0, HAPPY, UNHAPPY } happiness;

#define MAXN 1000000000
#define MAXS 10000

#define MAXD (9*9*9)
happiness seen[MAXD+1];

int multip[MAXD+1];
int bucket[MAXN/MAXS+1];

struct query {
  int A, B;
};

int main ()
{
#ifdef CONTEST
  freopen("happy.in", "rt", stdin);
  freopen("happy.out", "wt", stdout);
#endif
  // precompute numbers up to MAXD
  seen[0] = UNHAPPY;
  seen[1] = HAPPY;
  for (int n=2; n<=MAXD; n++) {
    set<int> X;
    int k = n;
    while (seen[k] == UNKNOWN && X.find(k) == X.end()) {
      X.insert(k);
      int d1 = k / 100;
      int d2 = (k % 100) / 10;
      int d3 = k % 10;
      k = d1*d1 + d2*d2 + d3*d3;
    }
    happiness h = (seen[k] == HAPPY) ? HAPPY : UNHAPPY;
    for (set<int>::iterator i=X.begin(); i!=X.end(); i++)
      seen[*i] = h;
  }
  // input
  int K;
  scanf("%d", &K);
  query Q[K];
  int maxB = 0;
  for (int i=0; i<K; i++) {
    scanf("%d %d", &(Q[i].A), &(Q[i].B));
    if (Q[i].B > maxB) maxB = Q[i].B;
  }
  // precompute first bucket
  for (int i=0; i<MAXS; i++) {
    int c = 0;
    for (int k=i; k>0; k /= 10) c += (k%10)*(k%10);
    multip[c]++;
    if (seen[c] == HAPPY) bucket[0]++;
  }
  // precompute remaining buckets
  for (int i=1; i<=maxB/MAXS; i++) {
    int c = 0;
    for (int k=i; k>0; k /= 10) c += (k%10)*(k%10);
    for (int j=0; j<=MAXD-c; j++)
      if (seen[j+c] == HAPPY) bucket[i] += multip[j];
  }
  // answer the queries
  for (int i=0; i<K; i++) {
    int curr = Q[i].A;
    int count = 0;
    while (curr % MAXS != 0 && curr <= Q[i].B) {
      int c = 0;
      for (int k=curr; k>0; k /= 10) c += (k%10)*(k%10);
      if (seen[c] == HAPPY) count++;
      curr++;
    }
    while (curr + MAXS <= Q[i].B) {
      count += bucket[curr/MAXS];
      curr += MAXS;
    }
    while (curr <= Q[i].B) {
      int c = 0;
      for (int k=curr; k>0; k /= 10) c += (k%10)*(k%10);
      if (seen[c] == HAPPY) count++;
      curr++;
    }
    printf("%d\n", count);
  }
  return 0;
}
