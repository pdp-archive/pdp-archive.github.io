#include <cstdio>
using namespace std;

typedef long long ll;
const ll mod = 1000000007;
long t,S,X,Y;

long calc_b(int B){
    ll pow2 = 1;//2^0
    ll prev=0;//άθροισμα μανιταριών που προσπεράσαμε στα προηγούμενα μήκη
    for(long i=1;;i++){
        if(i==B) return (prev + pow2*i + 1) % mod;
        pow2 = (pow2 * 2) % mod;//2^i
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
    if(Y>0)printf("%ld\n",calc_b((S+Y-1)/Y));
    return 0;
}
