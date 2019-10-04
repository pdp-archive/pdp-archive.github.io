#include <cstdio>
#include <vector>

using namespace std;

class BinaryIndexedTree {
 public:
  BinaryIndexedTree(int n) : max_value(n), tree(n+1, 0) {}

  int where(int n) {
    int l = 0, r = max_value;
    while (r - l > 1) {
      int m = (l+r) / 2;
      if (n <= m - get(m)) r = m; else l = m;
    }
    return r;
  }

  int get(int idx) {
    int sum = 0;
    while (idx > 0) {
      sum += tree[idx];
      idx -= (idx & -idx);
    }
    return sum;
  }

  void set(int idx) {
    while (idx <= max_value) {
      ++tree[idx];
      idx += (idx & -idx);
    }
  }

 private:
  int max_value;
  vector<int> tree;
};

int main() {
#ifdef CONTEST
  freopen("rafting.in", "rt", stdin);
  freopen("rafting.out", "wt", stdout);
#endif
  int N;
  scanf("%d", &N);
  vector<int> x(N);
  for (int i = 0; i < N; ++i)
    scanf("%d", &x[i]);
  BinaryIndexedTree t(N);
  vector<int> ranking(N);
  for (int i = N-1; i >= 0; --i) {
    int pos = t.where(x[i]);
    //printf("%d goes to position %d\n", i+1, pos);
    t.set(pos);
    ranking[pos-1] = i+1;
  }
  for (int i = 0; i < N; ++i)
    printf("%d%c", ranking[i], (i == N-1 ? '\n' : ' '));
}
