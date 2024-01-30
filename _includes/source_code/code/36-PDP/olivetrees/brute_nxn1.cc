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
        long min_height=H[i];//ελάχιστο ύψος από i έως και j
        for(long j=i;j<M;j++){
            min_height = std::min(min_height,H[j]);
            ans = std::max(ans, (j-i+1) * min_height);
        }
    }
    FILE *out = fopen("olivetrees.out","w");
    fprintf(out,"%ld\n",ans);
    fclose(out);
    return 0;
}

