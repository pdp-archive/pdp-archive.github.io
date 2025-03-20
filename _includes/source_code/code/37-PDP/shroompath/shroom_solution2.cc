#include <cstdio>

typedef long long ll;
const ll mod = 1000000007;
long t,S,X,Y,A,B;

long calc_a(long A){
    ll pow2 = 1, prev = 0;
    for(long i=1;2*i-1<A;i++){
        pow2 = (pow2 * 2) % mod;
        prev = (prev + pow2*i) % mod;
    }
    return (prev + A)%mod;
}

long calc_b(int B){
    ll pow2 = 1, prev = 0;
    for(long i=1;i<B;i++){
        pow2 = (pow2 * 2) % mod;
        prev = (prev + pow2*i) % mod;
    }
    return (prev + pow2*B+1)%mod;
}

long calc(int s,int x,int y){
    long A = x ? ((s+x-1)/x) : mod;
    long B = y ? ((s+y-1)/y) : mod;
    if(B*2-1>=A)
        return calc_a(A);
    else 
        return calc_b(B);
}

int main(){
#ifdef CONTEST
    freopen("shroompath.in","r",stdin);
    freopen("shroompath.out","w",stdout);
#endif
    scanf("%ld%ld%ld%ld",&t,&S,&X,&Y);
    printf("%ld\n",calc(S,X,Y));
    return 0;
}
