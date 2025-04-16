#include <cstdio>

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

int main() {
#ifdef CONTEST    
    freopen("counter.in", "r", stdin);
    freopen("counter.out", "w", stdout);
#endif
    scanf("%d", &subtask);
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);

    while (q--) {
        ll L, R;
        scanf("%lld %lld",&L,&R);
        printf("%d\n", bsearch(L));
    }
    return 0;
}
