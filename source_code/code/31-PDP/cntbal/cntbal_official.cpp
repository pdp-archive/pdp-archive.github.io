#include <cstdio>
#include <stack>

using namespace std;

#define MAXN 1000000
int N;
char s[MAXN];

int main() {
#ifdef CONTEST
  freopen("cntbal.in", "rt", stdin);
  freopen("cntbal.out", "wt", stdout);
#endif

  scanf("%d\n", &N);
  long long int count = 0;
  stack<int> closed;
  closed.push(0);
  for (int i = 0; i < N; ++i) {
    char c = getchar();
    if (c == '(')
      closed.push(0);
    else {
      closed.pop();
      if (closed.empty())
        closed.push(0);
      else {
        int new_closed = closed.top() + 1;
        closed.pop();
        closed.push(new_closed);
        count += new_closed;
      }
    }
  }
  printf("%lld\n", count);
}
