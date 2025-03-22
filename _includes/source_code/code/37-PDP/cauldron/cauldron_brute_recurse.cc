#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

long t, N, K, c;
long w[20];
ll ans;

void calc(long Krem,int i,ll csum=0){//Krem=μαγικό νερο στο καζάνι, csum=κέρδος από τα c
    if(i==N){
        ans = max(ans, K + csum);
        return;
    }
    calc(Krem,i+1,csum);//αν δεν πάρουμε το i
    if(Krem>=w[i])//έχουμε αρκετό μαγικό νερό;
        calc(Krem-w[i],i+1,csum+c);//αν πάρουμε το i
}

int main(){
#ifdef CONTEST
    freopen("cauldron.in","r",stdin);
    freopen("cauldron.out","w",stdout);
#endif
    scanf("%ld%ld%ld%ld",&t,&N,&K,&c);
    if(t==1){
        for(int i=0;i<N;i++)
            scanf("%ld",&w[i]);
        calc(K,0);
    }
    printf("%lld\n",ans);
    return 0;
}
