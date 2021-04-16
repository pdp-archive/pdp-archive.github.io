#include <cstdio>
#include <algorithm>

const long MAXN = 1'000'001L;

long A[MAXN];

int main(){
    freopen("landfight.in","r",stdin);
    freopen("landfight.out","w",stdout);
    
    long N;
    scanf("%ld",&N);
    for(long i=1;i<=N;i++)
        scanf("%ld",A+i);
    
    long ans=N,prefix=0,suffix=0,lptr=0,rptr=N+1;
    while(lptr<rptr){
        if(prefix == suffix){
            ans = std::min(ans,rptr-lptr-1);
            prefix += A[++lptr];
            suffix += A[--rptr];
        }
        while(prefix < suffix && lptr<rptr)
            prefix += A[++lptr];
        while(suffix < prefix && lptr<rptr)
            suffix += A[--rptr];
    }

    printf("%ld\n",ans);
    return 0;
}
