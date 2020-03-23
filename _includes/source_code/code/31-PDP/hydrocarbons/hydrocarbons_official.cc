#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
#ifdef CONTEST
  freopen("hydrocarbons.in", "rt", stdin);
  freopen("hydrocarbons.out", "wt", stdout);
#endif

  vector<pair<long long, int>> vect;
  int n, s=0, a, b, c;
  long long f;
  scanf("%d", &n);
  for (int i=1; i<=n; i++) {
    scanf("%d %d %d", &a, &b, &c);
    f = (long long)a*3000 - (long long)a*b - (long long)a*c*75;
    if (f > 0) vect.push_back({f,-i});
  }
  sort(vect.rbegin(), vect.rend());
  s = vect.size();
  printf("%d\n", s);
  for (int i=0; i<s; i++)
    printf("%d%c", -vect[i].second, i==s-1 ? '\n' : ' ');
}
