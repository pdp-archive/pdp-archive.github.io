#include <cstdio>

typedef long long ll;
const long MAXN = 200'000;

ll A[MAXN+1];
long n, q;
int subtask;

int FindCounter(ll x){
    long l = 1, r = n, counter = 0;
    while(l <= r){
        counter++;
        long m = (l+r)/2;
        if(A[m] == x) 
            break;
        if(A[m] < x)
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
    scanf("%ld %ld", &n, &q);
    for (long i = 1; i <= n; i++) scanf("%lld", &A[i]);

    while (q--) {
        ll L, R;
        scanf("%lld %lld",&L,&R);
        printf("%d\n", FindCounter(L));
    }
    return 0;
}
