#include <cstdio>
#include <algorithm>
using namespace std;

const long MAXN = 1'000'000L;

long A[MAXN], PS[MAXN];
pair<long,long> SS[MAXN];

int main(){
    freopen("landfight.in","r",stdin);
    freopen("landfight.out","w",stdout);
    
    long N;
    scanf("%ld",&N);
    for(long i=1;i<=N;i++){
        scanf("%ld",A+i);
        PS[i] = PS[i-1] + A[i];//prefix sum
    }
    for(long sum=0L, i=N;i>0;i--){
        sum +=A[i];
        SS[i] = {sum,i};
    }
    SS[0] = {0,N+1};//περίπτωση R=0,L=N 
    sort(SS,SS+N+1);
    
    long ans = N;
    for(long i=1;i<=N;i++){
        pair<long,long> test = {PS[i],i+1};
        size_t pos = lower_bound(SS,SS+N+1,test) - SS;
        if(pos != N+1 && SS[pos].first==PS[i])
            ans = min(ans,SS[pos].second-i-1);
    }
    
    printf("%ld\n",ans);
    return 0;
}
