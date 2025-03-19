#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
#ifdef CONTEST
    freopen("cauldron.in","r",stdin);
    freopen("cauldron.out","w",stdout);
#endif
    long t, N, K, c;
    scanf("%ld%ld%ld%ld",&t,&N,&K,&c);
    vector<long> w(N);
    ll ans = 0;
    for(auto& x:w)
        scanf("%ld",&x);
    if(N<=20){
        for(long s=0,m=(1L<<N);s<m;s++){
            long Krem = K;//πόσο μαγικό νερό παραμένει στο καζάνι
            ll test = 0;
            for(int i=0;i<N;i++){
                if((s&(1L<<i)) && Krem>=w[i]){
                    test += w[i] + c;
                    Krem -= w[i];
                }
            }
            test += Krem;
            ans = max(ans,test);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
