#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

long ans,N,M;
vector<long> st;//RMQ segment tree
vector<long> H;

long build(long si,long ss,long se){
    if(ss==se) return st[si] = H[ss];
    long mid = (ss+se)/2;
    return st[si] = min(build(si*2+1,ss,mid),build(si*2+2,mid+1,se));
}
long query(long si,long ss,long se,long L,long R){
    if(se<L || R<ss)return LONG_MAX;
    if(L<=ss && se<=R)return st[si];
    long mid=(ss+se)/2;
    return min(query(si*2+1,ss,mid,L,R),query(si*2+2,mid+1,se,L,R));
}

int main(){
    FILE *in = fopen("olivetrees.in","r");
    fscanf(in,"%ld%ld",&N,&M);
    st.resize(M*4);
    H.resize(M);
    for(long i=0;i<M;i++){
        fscanf(in,"%ld",&H[i]);
        H[i] = N - H[i];
    }
    fclose(in);
    build(0,0,M-1);

    for(long i=0;i<M;i++){
        long left=i,right=i;//άκρα παραλληλογράμμου
        //binary search για επέκταση αριστερά
        long lo=0,hi=i;
        while(lo<hi){
            long mid=(lo+hi)/2;
            if(query(0,0,M-1,mid,i)>=H[i])
                hi = mid;
            else
                lo = mid+1;
        }
        left = hi;
        //επέκταση δεξιά
        lo=i, hi = M-1;
        while(lo<hi){
            long mid=(lo+hi+1)/2;
            if(query(0,0,M-1,i,mid)>=H[i])
                lo = mid;
            else
                hi = mid-1;
        }
        right = lo;
        ans = max(ans,(right-left+1)*H[i]);
    }
    FILE *out = fopen("olivetrees.out","w");
    fprintf(out,"%ld\n",ans);
    fclose(out);
    return 0;
}
