#include <cstdio>
#include <algorithm>

using namespace std;

const long MAXN = int(1e6);
long N,S,T, ans, A[MAXN+1];

int main(){
    FILE *in = fopen("crazyhotel.in","r");
    FILE *out = fopen("crazyhotel.out","w");
    fscanf(in,"%ld%ld%ld",&N,&S,&T);
    for(int i=1;i<=N;i++)
        fscanf(in,"%ld",&A[i]);
    for(long left=1;left<=N;left++){	
        //βρες το right ως την τελευταία μέρα που μπορούμε να μείνουμε
        //με S χρήματα αν ξεκινήσουμε διαμονή από την ημέρα left
        long right = left-1, intsum = 0;
        while(right+1<=N && A[right+1]<=T && intsum+A[right+1]<=S)
            intsum += A[++right];
        ans += right - left + 1;
    }
    fprintf(out,"%ld\n",ans);
    fclose(in);
    fclose(out);
    return 0;
}

