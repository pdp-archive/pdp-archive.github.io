#include <cstdio>

const long MAXN = 1'000'000L;
long N,S,T, ans, PS[MAXN+1], A[MAXN+1];//PS[] = prefix sums of A[]

int main(){
    FILE *in = fopen("crazyhotel.in","r");
    FILE *out = fopen("crazyhotel.out","w");
    fscanf(in,"%ld%ld%ld",&N,&S,&T);
    for(int i=1;i<=N;i++){
        fscanf(in,"%ld",&A[i]);
        PS[i] = PS[i-1] + A[i];
    }
    long left, right = 0;
    for(left=1;left<=N;left++){	
        //βρες την τελευταία μέρα right που μπορούμε να μείνουμε, 
        //ξεκινώντας από την ημέρα left και ξοδεύοντας το πολύ S χρήματα 
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

