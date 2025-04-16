#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 200005;

ll a[MAXN];
int n, q, subtask;

int bsearch(ll x){
    int l = 1, r = n, counter = 0;
    while(l <= r){
        counter++;
        int m = (l+r)/2;
        if(a[m] == x) 
            break;
        if(a[m] < x)
            l = m+1;
        else
            r = m-1;
    }
    return counter;
}

ll ps[MAXN];
ll c[MAXN];

int main() {
#ifdef CONTEST    
    freopen("counter.in", "r", stdin);
    freopen("counter.out", "w", stdout);
#endif
    scanf("%d", &subtask);
    scanf("%d %d", &n, &q);

    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++) c[i] = bsearch(a[i]);
    for (int i = 1; i <= n; i++) ps[i] = ps[i-1] + c[i];
    
    while (q--) {
        ll L, R;
        scanf("%lld %lld", &L, &R);
        int j = lower_bound(a+1, a+n+1, L) - a;
        int k = upper_bound(a+1, a+n+1, R) - a - 1;
        printf("%lld\n", ps[k] - ps[j-1]);
    }

    return 0;
}
