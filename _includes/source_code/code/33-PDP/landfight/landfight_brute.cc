#include <cstdio>
#include <algorithm>

const long MAXN = 1'000'001L;

long A[MAXN];

long calcsum(long i,long j){
    long ans = 0L;
    while(i<=j)
        ans += A[i++];
    return ans;
}
int main(){
    freopen("landfight.in","r",stdin);
    freopen("landfight.out","w",stdout);
    
    long N;
    scanf("%ld",&N);
    for(long i=1;i<=N;i++)
        scanf("%ld",A+i);
    
    long ans = N;
    for(long i=1;i<=N;i++){
        for(long j=i+1;j<=N+1;j++){
            if(calcsum(1,i) == calcsum(j,N+1)){
                ans = std::min(ans,j-i-1);
                //Δεν έχει νόημα να συνεχίσουμε γιατί τα υπόλοιπα διαστήματα είναι μεγαλύτερα
                break;
            }
        }
    }

    printf("%ld\n",ans);
    return 0;
}
