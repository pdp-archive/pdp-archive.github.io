#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <list>
using namespace std;

const long MAXN = 1'000'001L;

long A[MAXN];
unordered_map<long, list<long> > M;

int main(){
    freopen("landfight.in","r",stdin);
    freopen("landfight.out","w",stdout);
    
    long N;
    scanf("%ld",&N);
    for(long i=1;i<=N;i++)
        scanf("%ld",A+i);
    
    M[0].push_front(N+1);
    for(long suffix=0L,i=N;i>0;i--){
        suffix +=A[i];
        M[suffix].push_front(i);
    }
    
    long ans = N;
    for(long prefix=0L,i=0;i<=N;i++){
        prefix += A[i];
        if(M.find(prefix) == M.end())
            continue;
        
        list<long>& S = M[prefix];
        
        //αφαίρεσε τις θέσεις που ξεπεράστηκαν
        while(!S.empty() && S.front()<=i)
            S.pop_front();
        
        if(!S.empty())
            ans = min(ans,S.front()-i-1);
    }
    
    printf("%ld\n",ans);
    return 0;
}
