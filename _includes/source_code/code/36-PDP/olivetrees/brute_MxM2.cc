#include <cstdio>
#include <algorithm>
#include <vector>

long ans,N,M;
std::vector<long> H;

int main(){
    FILE *in = fopen("olivetrees.in","r");
    fscanf(in,"%ld%ld",&N,&M);
    H.resize(M);
    for(long i=0;i<M;i++){
        fscanf(in,"%ld",&H[i]);
        H[i] = N - H[i];
    }
    fclose(in);

    for(long i=0;i<M;i++){
        long left = i, right = i;
        while(left-1>=0 && H[i]<=H[left-1]) left--;
        while(right+1<M && H[i]<=H[right+1]) right++;
        ans = std::max(ans, (right-left+1) * H[i]);
    }

    FILE *out = fopen("olivetrees.out","w");
    fprintf(out,"%ld\n",ans);
    fclose(out);
    return 0;
}

