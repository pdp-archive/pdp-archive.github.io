#include <algorithm>
#include <cstdio>
#include <functional>
#include <vector>

using namespace std;

int main() {
#ifdef CONTEST
  freopen("erasmus.in", "r", stdin);
  freopen("erasmus.out", "w", stdout);
#endif

  int N, M;
  scanf("%d%d", &N, &M);

  vector<int> P(N);
  for (int i=0; i<N; ++i) scanf("%d", &P[i]);

  vector<pair<int, int>> S(M);
  vector<vector<int>> Q(M);
  for (int i=0; i<M; ++i) {
    int a, nQ;
    scanf("%d%d", &a, &nQ);
    S[i] = make_pair(a, i);
    Q[i].resize(nQ);
    for (int j=0; j<nQ; ++j) scanf("%d", &Q[i][j]);
  }

  sort(S.begin(), S.end(), greater<pair<int, int>>());

  vector<int> where(M, 0);
  for (auto p : S)
    for (auto q : Q[p.second])
      if (P[q-1] > 0) {
        where[p.second] = q;
        --P[q-1];
        break;
      }

  for (auto w : where)
    if (w > 0)
      printf("%d\n", w);
    else
      printf("NONE\n");
}
