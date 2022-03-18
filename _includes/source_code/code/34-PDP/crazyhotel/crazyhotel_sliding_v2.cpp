#include <cstdio>
#include <algorithm>

using namespace std;

const long MAXN = int(1e6);
long N,S,T, ans, A[MAXN+1], intsum;//interval sum = άθροισμα του segment [left,right]

int main(){
    FILE *in = fopen("crazyhotel.in","r");
    FILE *out = fopen("crazyhotel.out","w");
    fscanf(in,"%ld%ld%ld",&N,&S,&T);
    for(long i=1;i<=N;i++)
        fscanf(in,"%ld",&A[i]);

    for(long right=0,left=1;left<=N;left++){	
        //βρες το right ως την τελευταία μέρα που μπορύμε να μείνουμε
        //με S χρήματα αν ξεκινήσουμε διαμονή από την ημέρα left
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

