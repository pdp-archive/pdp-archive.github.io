#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_V 100000
#define COST first
#define A second.first
#define B second.second
#define MT(X,Y,Z) make_pair(X, make_pair(Y, Z))

typedef pair<int, pair<int, int> > iii;

//***** Union Find *****
int comp[MAX_V + 1], rnk[MAX_V + 1];

void init_comp () {
    for (int i = 0; i <= MAX_V; i++)
        comp[i] = i, rnk[i] = 0;
}
int find (int v) {
    if (comp[v] == v) return v;
    else return (comp[v] = find(comp[v]));
}
void join (int u, int v) {
    u = find(u), v = find(v);

    if (rnk[u] < rnk[v]) comp[u] = v;
    else comp[v] = u;

    if (rnk[u] == rnk[v]) rnk[u]++;
}
// ********************

int main() {
#ifdef CONTEST
  freopen("airports.in", "rt", stdin);
  freopen("airports.out", "wt", stdout);
#endif
  
    int n, m, k;

    scanf("%d %d %d", &n, &m, &k);

    vector<iii> E;

    for (int i = 0; i < m; i++) {
        int city, cost;
        scanf("%d %d", &city, &cost);
        E.push_back(MT(cost, 0, city));
    }
    for (int i = 0; i < k; i++) {
        int a, b, cost;
        scanf("%d %d %d", &a, &b, &cost);
        E.push_back(MT(cost, a, b));
    }

    sort(E.begin(), E.end());

    // Allow airport
    init_comp();
    int total1 = 0;
    //int airno = 0;
    for (vector<iii>::iterator it = E.begin(); it != E.end(); it++)
        if (find(it->A) != find(it->B)) {
            join(it->A, it->B);
      //      if (it->A == 0) airno++;
            total1 += it->COST;
        }

    // Without Airport
    init_comp();
    int total2 = 0;
    for (vector<iii>::iterator it = E.begin(); it != E.end(); it++)
        if (find(it->A) != find(it->B) && it->A != 0) {
            join(it->A, it->B);
            total2 += it->COST;
        }
    printf("%d\n", min(total1, total2));

    return 0;
}
