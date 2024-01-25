#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

long ans,N,M;
vector<vector<long>> rmq;
vector<long> H;
long logm;

int main(){
    scanf("%ld%ld",&N,&M);
    logm = (long)ceil(log2(M));
    rmq.resize(M,vector<long>(logm+1));
    H.resize(M);
    for(long i=0;i<M;i++){
        scanf("%ld",&H[i]);
        H[i] = N-H[i];
        rmq[i][0] = H[i];
    }
    //precompute sparse array O(M*logM)
    for(long j=1;j<=logm;j++){
        for(long i=0;i<M;i++){
            long step = 1L << (j-1);
            if(i + step<M)
                rmq[i][j] = min(rmq[i][j-1],rmq[i+step][j-1]);
            else
                rmq[i][j] = rmq[i][j-1];
        }
    }
    for(long i=0;i<M;i++){
        long left = i, right = i;
        for(int j=logm;j>=0;j--){
            long step = 1L << j;
            //επέκταση δεξιά
            if(right+1<M && rmq[right+1][j]>=H[i])
                right=min(M-1,right+step);
            //επέκταση αριστερά
            if(left-step>=0 && rmq[left-step][j]>=H[i])
                left -= step;
        }
        ans = max(ans,(right-left+1)*H[i]);
    }
    printf("%ld\n",ans);
    return 0;
}
