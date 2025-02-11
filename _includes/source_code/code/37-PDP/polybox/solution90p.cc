#include <algorithm>
#include <cstdio>
#include <vector>

typedef long long ll;

int main(){
    freopen("polybox.in", "r", stdin);
    freopen("polybox.out", "w", stdout);
    long subtask,N;
    scanf("%ld%ld",&subtask,&N);
    std::vector<ll> w(N),h(N);
    for(long i=0;i<N;i++)
        scanf("%lld%lld",&w[i],&h[i]);
    //υπολόγισε στη μεταβλητή box την πιο πάνω και την πιο κάτω πλευρά της στοίβας
    ll box = w[0] + w[N-1];
    //πρόσθεσε στη box όλα τα ενδιάμεσα εκτεθημένα τμήματα
    for(long i=0;i<N-1;i++)
        box += abs(w[i]-w[i+1]);
    //πρόσθεσε τα ύψη όλων των κουτιών
    for(long i=0;i<N;i++)
        box += 2ll*h[i];
    printf("%lld\n",box);
    return 0;
}
