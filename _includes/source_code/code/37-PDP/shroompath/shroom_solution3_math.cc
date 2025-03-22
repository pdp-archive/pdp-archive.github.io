#include <cstdio>

typedef long long ll;
const ll mod = 1000000007;
long t,S,X,Y,A,B;

ll pow2(long a){
    if(a == 0)return 1;
    ll z = pow2(a/2);
    z = (z * z) % mod;
    if(a&1)
        z = (z * 2) % mod;
    return z;
}

ll f(long w){ return (pow2(w)*w)%mod; }

ll p(long w){ return (pow2(w+1)*(w-1)+2) % mod; }

long calc(int s,int x,int y){
    long A = x ? ((s+x-1)/x) : mod;
    long B = y ? ((s+y-1)/y) : mod;
    if(B*2-1>=A){
        return (p(A/2) + A)%mod;
    }else{
        ll w = f(B);
        //το w πρέπει να είναι άρτιος ώστε να μπορεί να διαιρεθεί με το 2
        if(w & 1)w+=mod;//αν w περιττός, μετέτρεψε το σε ισοδύναμο (ως προς mod) άρτιο
        return (p(B-1) + w/2+1)%mod;
    }
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
