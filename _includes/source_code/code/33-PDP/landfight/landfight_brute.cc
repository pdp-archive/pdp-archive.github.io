#include <cstdio>
#include <algorithm>

const long MAXN = 1'000'002L;

long A[MAXN];

long calcsum(long i,long j){
    long sum = 0L;
    while(i<=j)
        sum += A[i++];
    return sum;
}
int main(){
    freopen("landfight.in","r",stdin);
    freopen("landfight.out","w",stdout);
    
    long N;
    scanf("%ld",&N);
    for(long i=1;i<=N;i++)
        scanf("%ld",A+i);
    
    long ans = N;
    for(long i=0;i<=N;i++){
        for(long j=i+1;j<=N+1;j++){
            if(calcsum(1,i) == calcsum(j,N+1)){
                //fprintf(stderr,"N=%ld, calcsum[%ld,%ld]=[%ld,%ld]=%ld\n",N,1,i,j,N+1,calcsum(j,N+1));
                ans = std::min(ans,j-i-1);
                //Δεν έχει νόημα να συνεχίσουμε γιατί τα υπόλοιπα διαστήματα είναι μεγαλύτερα
                break;
            }
        }
    }

    printf("%ld\n",ans);
    return 0;
}
