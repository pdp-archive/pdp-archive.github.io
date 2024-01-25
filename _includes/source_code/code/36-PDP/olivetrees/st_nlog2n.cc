#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

long ans,N,M;
vector<long> st;//RMQ segment tree
vector<long> H;

long build(long si,long ss,long se){
    if(ss==se){
        return st[si] = H[ss];
    } else {
        long mid = (ss+se)/2;
        return st[si] = min(build(si*2+1,ss,mid),build(si*2+2,mid+1,se));
    }
}
long query(long si,long ss,long se,long L,long R){
    if(se<L || R<ss)return LONG_MAX;
    if(L<=ss && se<=R)return st[si];
    long mid=(ss+se)/2;
    return min(query(si*2+1,ss,mid,L,R),query(si*2+2,mid+1,se,L,R));
}

int main(){
    scanf("%ld%ld",&N,&M);
    st.resize(M*4);
    H.resize(M);
    for(long i=0;i<M;i++){
        scanf("%ld",&H[i]);
        H[i] = N-H[i];
    }
    build(0,0,M-1);

    for(long i=0;i<M;i++){
        long leftmost=i,rightmost=i;
        //binary search για επέκταση αριστερά
        long left=0,right=i;
        while(left<=right){
            long mid=(left+right)/2;
            if(query(0,0,M-1,mid,i)>=H[i]){
                leftmost = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        //επέκταση δεξιά
        left=i, right = M-1;
        while(left<=right){
            long mid=(left+right)/2;
            if(query(0,0,M-1,i,mid)>=H[i]){
                rightmost = mid;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        ans = max(ans,(rightmost-leftmost+1)*H[i]);
    }
    printf("%ld\n",ans);
    return 0;
}
