#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;
const int MAXN = 200005;

ll a[MAXN];
int n, q, subtask;

ll query(ll qleft, ll qright, int leftpos=1,int rightpos=n,int counter=0){
    if(qleft > qright) return 0LL;//βγήκαμε εκτός του query
    if(leftpos>rightpos)//δεν υπάρχουν οι αριθμοί του διαστηματος [qleft,qright] στον a[]
        return (qright-qleft+1)*counter;
    ++counter;//σε κάθε σύγκριση του a[mid] με το x, αυξάνεται το counter
    int mid = (leftpos+rightpos)/2;
    ll ans = 0ll;
    if(qleft <= a[mid] && a[mid] <= qright)
        ans += counter;
    ans += query(qleft, min(qright,a[mid]-1),leftpos,mid-1, counter);
    ans += query(max(qleft,a[mid]+1),qright,mid+1,rightpos,counter);
    return ans;
}

int main(){
#ifdef CONTEST    
    freopen("counter.in", "r", stdin);
    freopen("counter.out", "w", stdout);
#endif
    scanf("%d", &subtask);
    scanf("%d %d", &n, &q);

    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        
    while (q--) {
        ll L, R;
        scanf("%lld %lld", &L, &R);
        printf("%lld\n", query(L,R));
    }
    return 0;
}
