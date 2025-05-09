#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;
const long MAXN = 200'000;

ll A[MAXN+1];
int C[MAXN+1];//FindCounter τιμές
ll PS[MAXN+1];//prefix sums στον C
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
    for (long i = 1; i <= n; i++) C[i] = FindCounter(A[i]);
    int leftout = FindCounter(A[1]-1), rightout = FindCounter(A[n]+1);
    for (long i = 1; i <= n; i++) PS[i] = PS[i-1] + C[i];
    
    while (q--) {
        ll L, R, ans=0;
        scanf("%lld %lld", &L, &R);

        if(R<A[1]){//Ολόκληρο το query βρίσκεται αριστερά του A[]
            ans = (R-L+1)*leftout;
        }else if(L>A[n]){//Ολόκληρο το query βρίσκεται δεξιά του A[]
            ans = (R-L+1)*rightout;
        }else {
            if(L<A[1]){//έχουμε μερικά στοιχεία αριστερά του A[]
                ans += ((A[1]-1) - L + 1) * leftout;
                L = A[1];
            }
            if(A[n]<R){//και μερικά δεξιά του A[]
                ans += (R - (A[n]+1) + 1) * rightout;
                R = A[n];
            }
            long j = lower_bound(A+1, A+n+1, L) - A;
            long k = upper_bound(A+1, A+n+1, R) - A - 1;
            ans += PS[k] - PS[j-1];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
