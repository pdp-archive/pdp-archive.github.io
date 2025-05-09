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

int main(){
#ifdef CONTEST    
    freopen("counter.in", "r", stdin);
    freopen("counter.out", "w", stdout);
#endif
    scanf("%d", &subtask);
    scanf("%ld %ld", &n, &q);

    for (long i = 1; i <= n; i++) scanf("%lld", &A[i]);
    for (long i = 1; i <= n; i++) C[i] = FindCounter(A[i]);
    for (long i = 1; i <= n; i++) PS[i] = PS[i-1] + C[i];
    int outside = FindCounter(A[1]-1);//Η επιστρεφόμενη τιμή της FindCounter για ανύπαρκτα x
    
    while (q--) {
        ll L, R, ans;
        scanf("%lld %lld", &L, &R);
        long j = lower_bound(A+1, A+n+1, L) - A;
        long k = upper_bound(A+1, A+n+1, R) - A - 1;
        if(j>n || A[j]>R || k<1){//Όλο το [L,R] εκτός του A[]
            ans = outside * (R-L+1);
        } else {
            ans = PS[k] - PS[j-1];//Τα στοιχεία του Α εντός του ερωτήματος
            ans += outside * ((R-L+1) - (k-j+1));//και τα εκτός ερωτήματος
        }
        printf("%lld\n",ans);
    }
    return 0;
}
