#include <cstdio>

typedef long long ll;
const ll mod = 1000000007;
long t,S,X,Y,A,B;

long calc(int A, int B){
    ll pow2 = 1;
    ll prev=0;//σύνολο μανιταριων που προσπερασαμε
    for(int i=1;;i++){//για όλα τα πλάτη απο 1 έως ...
        if(A<=2*i-1) return (prev + A) % mod;
        if(i == B) return (prev + pow2*i + 1) % mod; 
        pow2 = (pow2 * 2) % mod;
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
    A = (X>0) ? (S+X-1)/X : mod;
    B = (Y>0) ? (S+Y-1)/Y : mod;
    printf("%ld\n",calc(A,B));
    return 0;
}
