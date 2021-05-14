#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

const long MAXN = 1'000'001L;

long A[MAXN];
unordered_map<int, vector<long> > M;

int main(){
    freopen("landfight.in","r",stdin);
    freopen("landfight.out","w",stdout);
    
    long N;
    scanf("%ld",&N);
    for(long i=1;i<=N;i++)
        scanf("%ld",A+i);
    
    M[0].push_back(N+1);//περίπτωση L=N,R=0
    for(long suffix=0L,i=N;i>0;i--){
        suffix +=A[i];
        M[suffix].push_back(i);
    }
    
    long ans = N;
    for(long prefix=0L,i=1;i<=N;i++){
        prefix += A[i];
        if(M.find(prefix) == M.end())
            continue;
        vector<long>& V = M[prefix];
        //διέγραψε τα ξεπερασμένα
        while(!V.empty() && V.back()<=i)
            V.pop_back();
        if(!V.empty())
            ans = min(ans,V.back()-i-1);
    }
    
    printf("%ld\n",ans);
    return 0;
}
