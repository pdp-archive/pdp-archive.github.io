#include <cstdio>
#include <algorithm>
#include <vector>

long ans,N,M;
std::vector<int> H;

int main(){
    scanf("%ld%ld",&N,&M);
    H.resize(M);
    for(long i=0;i<M;i++){
        scanf("%ld",&H[i]);
        H[i] = N - H[i];
    }
    for(long i=0;i<M;i++){
        long left = i, right = i;
        while(left-1>=0 && H[i]<=H[left-1]) left--;
        while(right+1<M && H[i]<=H[right+1]) right++;
        ans = std::max(ans, (right-left+1) * H[i]);
    }
    printf("%ld\n",ans);
    return 0;
}

