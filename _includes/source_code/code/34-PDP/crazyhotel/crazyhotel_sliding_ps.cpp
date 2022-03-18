#include <cstdio>
#include <algorithm>

using namespace std;

const long MAXN = int(1e6);
long N,S,T, ans, PS[MAXN+1], A[MAXN+1];//PS[] = prefix sums of A[]

int main(){
    FILE *in = fopen("crazyhotel.in","r");
    FILE *out = fopen("crazyhotel.out","w");
    fscanf(in,"%ld%ld%ld",&N,&S,&T);
    for(int i=1;i<=N;i++){
        fscanf(in,"%ld",&A[i]);
        PS[i] = PS[i-1] + A[i];
    }
    for(long right=0,left=1;left<=N;left++){	
        //βρες το right ως την τελευταία μέρα που μπορούμε να μείνουμε
        //με S χρήματα αν ξεκινήσουμε διαμονή από την ημέρα left
        if(right<left-1)//πρέπει Ν>=right+1>=L
            right=left-1;
        while(right+1<=N && A[right+1]<=T && PS[right+1]-PS[left-1]<=S)
            right++;
        ans += right - left + 1;
    }
    fprintf(out,"%ld\n",ans);
    fclose(in);
    fclose(out);
    return 0;
}

