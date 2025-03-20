#include <cstdio>

typedef long long ll;
const ll mod = 1000000007;
long t,S,X,Y;

long calc_a(int A){
    ll pow2 = 1;//2^0
    ll prev=0;//άθροισμα μανιταριών που προσπεράσαμε στα προηγούμενα μήκη
    for(long i=1;;i++){
        pow2 = (pow2 * 2) % mod;//2^i
        if(A<=2*i-1) return (prev + A) % mod;
        prev = (prev + pow2*i) % mod;
    }
    return -1L;
}

int main(){
#ifdef CONTEST
    freopen("shroompath.in","r",stdin);
    freopen("shroompath.out","w",stdout);
#endif
    scanf("%ld%ld%ld%ld",&t,&S,&X,&Y);
    if(X>0)printf("%ld\n",calc_a((S+X-1)/X));
    return 0;
}
