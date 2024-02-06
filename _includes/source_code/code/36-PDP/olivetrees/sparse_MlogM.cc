#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

long ans,N,M;
std::vector<std::vector<long>> rmq;
std::vector<long> H;
long logm;

void precompute_sparse(){
    logm = (long)ceil(log2(M));
    rmq.resize(M,std::vector<long>(logm+1));
    //precompute sparse array O(M*logM)
    for(long i=0;i<M;i++)rmq[i][0] = H[i];
    for(long j=1;j<=logm;j++){
        for(long i=0;i<M;i++){
            long step = 1L << (j-1);
            if(i + step<M)
                rmq[i][j] = std::min(rmq[i][j-1],rmq[i+step][j-1]);
            else
                rmq[i][j] = rmq[i][j-1];
        }
    }
}

int main(){
    FILE *in = fopen("olivetrees.in","r");
    fscanf(in,"%ld%ld",&N,&M);
    H.resize(M);
    for(long i=0;i<M;i++){
        fscanf(in,"%ld",&H[i]);
        H[i] = N - H[i];
    }
    fclose(in);
    precompute_sparse();
    for(long i=0;i<M;i++){
        long left = i, right = i;
        for(int j=logm;j>=0;j--){
            long step = 1L << j;
            //επέκταση δεξιά
            if(right+1<M && rmq[right+1][j]>=H[i])
                right=std::min(M-1,right+step);
            //επέκταση αριστερά
            if(left-step>=0 && rmq[left-step][j]>=H[i])
                left -= step;
        }
        ans = std::max(ans,(right-left+1)*H[i]);
    }
    FILE *out = fopen("olivetrees.out","w");
    fprintf(out,"%ld\n",ans);
    fclose(out);
    return 0;
}
