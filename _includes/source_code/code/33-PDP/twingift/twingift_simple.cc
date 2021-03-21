//O(N*M)
#include <cstdio>

const long MAXN = 1'000'000L;

long A[MAXN], NA /*N*/, B[MAXN], MB /*M*/, L,R;

int main(){
    freopen("twingift.in","r",stdin);
    freopen("twingift.out","w",stdout);
    
    scanf("%ld%ld%ld%ld",&NA,&MB,&L,&R);
    for(long i=0;i<NA;i++)scanf("%ld",A+i);
    for(long i=0;i<MB;i++)scanf("%ld",B+i);
    
    long ans = 0;
    for(long i=0;i<NA;i++){
        long LL = L-A[i], RR = R-A[i];
        for(long j=0;j<MB;j++)
            if(LL<=B[j] && B[j]<=RR)
                ans++;
    }
    
    printf("%ld\n",ans);
    return 0;
}
