#include <algorithm>
#include <cstdio>
#include <vector>

int main(){
    FILE *in = fopen("allthatjazz.in", "r");
    FILE *out= fopen("allthatjazz.out", "w");
    long N,Q;
    fscanf(in, "%ld\n", &N);
    std::vector<long> D(N);
    for(long i = 0; i < N; i++)fscanf(in, "%ld", &D[i]);
    std::sort(D.begin(), D.end());
    fscanf(in, "%ld\n", &Q);
    while(Q-- > 0){
        long K;
        fscanf(in, "%ld", &K);
        long ans = 0;
        for(long i = 0; i < N; i++){
            if(i && D[i]==D[i-1])continue;//υπολογίσαμε ξανά αρχή από την ημέρα αυτή
            for(long m = i; m<N && D[m]-D[i]<K; m++)
                ans = std::max(ans, m-i+1);
        }
        fprintf(out, "%ld\n", ans);
    }
    fclose(out);
    fclose(in);
    return 0;
}
