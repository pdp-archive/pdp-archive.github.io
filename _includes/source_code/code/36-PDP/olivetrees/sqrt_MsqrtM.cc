#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

long ans,N,M,SQRTN;
std::vector<long> bucket;
std::vector<long> H;

inline long bucket_id(long x) { return x/SQRTN; }//id του bucket που περιέχει τη στήλη x
inline long bucket_first(long bid) { return bid*SQRTN; }//πρώτη στήλη στο bucket bid
inline long bucket_last(long bid) { return std::min(bid*SQRTN+SQRTN-1,M-1); }//τελευταία στήλη

long expand_left(long left){
    //αναζήτησε τις συμβατές στήλες αριστερά
    long bid = bucket_id(left), height=H[left], bf = bucket_first(bid);
    if(left<bucket_last(bid)){//δεν ξεκινάμε με ολόκληρο bucket
        while(left-1>=bf && H[left-1]>=height)left--;
        bid--;
        if(left>bf)//δεν φτάσαμε μέχρι το τέλος του bucket
            return left;
    }
    //προσπέρασε ολόκληρα buckets αριστερά
    while(bid>=0 && bucket[bid]>=height)
        left = bucket_first(bid--);
    if(bid>=0){//ας ψάξουμε το επόμενο bucket σειριακά
        bf = bucket_first(bid);
        while(left-1>=bf && H[left-1]>=height)left--;
    }
    return left;
}

long expand_right(long right){
    long bid = bucket_id(right), height=H[right], bl = bucket_last(bid);
    if(right>bucket_first(bid)){
        while(right+1<=bl && H[right+1]>=height)right++;
        bid++;
        if(right<bl)
            return right;
    }
    while(bid<bucket.size() && bucket[bid]>=height)
        right = bucket_last(bid++);
    if(bid<bucket.size()){
        bl = bucket_last(bid);
        while(right+1<=bl && H[right+1]>=height)right++;
    }
    return right;
}

int main(){
    FILE *in = fopen("olivetrees.in","r");
    fscanf(in,"%ld%ld",&N,&M);
    SQRTN = (long)std::ceil(sqrt(M));
    bucket.resize((M+SQRTN-1)/SQRTN,LONG_MAX);
    H.resize(M);
    for(long j=0,bid=0,i=0;i<M;i++,j++){
        if(j==SQRTN){//ξεκινά το επόμενο  bucket
            j=0;
            bid++;
        }
        fscanf(in,"%ld",&H[i]);
        H[i] = N-H[i];
        bucket[bid] = std::min(bucket[bid],H[i]);
    }
    fclose(in);
    for(long i=0;i<M;i++){
        long left = expand_left(i);
        long right= expand_right(i);
        ans = std::max(ans,(right-left+1)*H[i]);
    }
    FILE *out = fopen("olivetrees.out","w");
    fprintf(out,"%ld\n",ans);
    fclose(out);
    return 0;
}
