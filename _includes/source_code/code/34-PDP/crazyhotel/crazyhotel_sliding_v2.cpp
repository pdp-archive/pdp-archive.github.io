#include <cstdio>

const long MAXN = 1'000'000L;
long N,S,T,A[MAXN+1],ans;

int main(){
    FILE *in = fopen("crazyhotel.in","r");
    FILE *out = fopen("crazyhotel.out","w");
    fscanf(in,"%ld%ld%ld",&N,&S,&T);
    for(long i=1;i<=N;i++)
        fscanf(in,"%ld",&A[i]);

    long left, right=0;
    long intsum = 0;//Το άθροισμα του segment [left,right];
    for(left=1;left<=N;left++){	
        //βρες την τελευταία μέρα right που μπορούμε να μείνουμε, 
        //ξεκινώντας από την ημέρα left και ξοδεύοντας το πολύ S χρήματα 
        if(right<left-1){//πρέπει Ν>=right+1>=L
            intsum = 0;
            right=left-1;
        }
        while(right+1<=N && A[right+1]<=T && intsum+A[right+1]<=S)
            intsum += A[++right];//βάλε το right+1 στο segment
        ans += right - left + 1;
        intsum -= A[left];//το A[left] θα βγει από το segment[left,right]
    }
    fprintf(out,"%ld\n",ans);
    fclose(in);
    fclose(out);
    return 0;
}

