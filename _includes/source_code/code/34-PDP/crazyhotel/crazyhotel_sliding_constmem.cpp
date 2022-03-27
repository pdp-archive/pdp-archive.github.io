#include <cstdio>

const long MAXN = 1'000'000L;
long N,S,T, ans;

int main(){
    FILE *fleft = fopen("crazyhotel.in","r");
    FILE *fright = fopen("crazyhotel.in","r");
    FILE *out = fopen("crazyhotel.out","w");
    fscanf(fleft,"%ld%ld%ld",&N,&S,&T);
    fscanf(fright,"%ld%ld%ld",&N,&S,&T);
    
    long intsum = 0;//interval sum = άθροισμα του segment [left,right]
    long a_left, a_right;
    fscanf(fright, "%ld", &a_right);
    for(long right=0,left=1;left<=N;left++){	
        //βρες το right ως την τελευταία μέρα που μπορύμε να μείνουμε
        //με S χρήματα αν ξεκινήσουμε διαμονή από την ημέρα left
        if(right<left-1){//πρέπει Ν>=right+1>=L
            intsum = 0;
            ++right;
            if (right + 1 <= N) fscanf(fright, "%ld", &a_right);
        }
        while(right+1<=N && a_right <=T && intsum+a_right<=S) {
            intsum += a_right;//βάλε το right+1 στο segment
            ++right;
            if (right + 1 <= N) fscanf(fright, "%ld", &a_right);
        }
        ans += right - left + 1;
        fscanf(fleft, "%ld", &a_left);
        intsum -= a_left;//το A[left] θα βγει από το segment[left,right]
    }
    fprintf(out,"%ld\n",ans);
    fclose(fleft);
    fclose(fright);
    fclose(out);
    return 0;
}
