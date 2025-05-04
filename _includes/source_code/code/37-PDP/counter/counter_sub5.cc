#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;
const int MAXN = 200'000;

ll A[MAXN+1];
long n, q;
int subtask;

ll query(ll qleft, ll qright, long leftpos=1,long rightpos=n,int counter=0){
    if(qleft > qright) return 0LL;//βγήκαμε εκτός του query
    if(leftpos>rightpos)//δεν υπάρχουν οι αριθμοί του διαστηματος [qleft,qright] στον A[]
        return (qright-qleft+1)*counter;
    ++counter;//σε κάθε σύγκριση του A[mid] με το x, αυξάνεται το counter
    long mid = (leftpos+rightpos)/2;
    ll ans = 0ll;
    if(qleft <= A[mid] && A[mid] <= qright)
        ans += counter;
    ans += query(qleft, min(qright,A[mid]-1),leftpos,mid-1, counter);
    ans += query(max(qleft,A[mid]+1),qright,mid+1,rightpos,counter);
    return ans;
}

int main(){
#ifdef CONTEST    
    freopen("counter.in", "r", stdin);
    freopen("counter.out", "w", stdout);
#endif
    scanf("%d", &subtask);
    scanf("%ld %ld", &n, &q);

    for (long i = 1; i <= n; i++) scanf("%lld", &A[i]);
        
    while (q--) {
        ll L, R;
        scanf("%lld %lld", &L, &R);
        printf("%lld\n", query(L,R));
    }
    return 0;
}
