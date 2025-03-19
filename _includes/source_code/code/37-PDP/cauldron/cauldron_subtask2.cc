#include <cstdio>
using namespace std;

int main(){
#ifdef CONTEST
    freopen("cauldron.in","r",stdin);
    freopen("cauldron.out","w",stdout);
#endif
    long t, N, K, c;
    scanf("%ld%ld%ld%ld",&t,&N,&K,&c);
    printf("%ld\n",K);
    return 0;
}
