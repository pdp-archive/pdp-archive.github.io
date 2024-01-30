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
        for(long j=i;j<M;j++){
            long min_height=H[i];//βρες το ελάχιστο ύψος από i εως και j
            for(long k=i+1;k<=j;k++)
                min_height = std::min(min_height,H[k]);
            ans = std::max(ans, (j-i+1) * min_height);
        }
    }
    FILE *out = fopen("olivetrees.out","w");
    fprintf(out,"%ld\n",ans);
    fclose(out);
    return 0;
}

