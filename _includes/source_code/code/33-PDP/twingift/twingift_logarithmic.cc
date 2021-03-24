#include <cstdio>
#include <algorithm>

using namespace std;

const long MAXN = 1'000'000L;

long A[MAXN], NA /*N*/, B[MAXN], MB /*M*/, L,R;

long solve(long a[],long na,long b[],long nb){
    long ans = 0;
    sort(b,b+nb);
    for(long i=0;i<na;i++)
        ans += upper_bound(b,b+nb,R-a[i])-lower_bound(b,b+nb,L-a[i]);
    return ans;
}

int main(){
    freopen("twingift.in","r",stdin);
    freopen("twingift.out","w",stdout);
    
    scanf("%ld%ld%ld%ld",&NA,&MB,&L,&R);
    for(long i=0;i<NA;i++)scanf("%ld",A+i);
    for(long i=0;i<MB;i++)scanf("%ld",B+i);
    
    printf("%ld\n", (MB>NA) ? solve(A,NA,B,MB) : solve(B,MB,A,NA) );

    return 0;
}
