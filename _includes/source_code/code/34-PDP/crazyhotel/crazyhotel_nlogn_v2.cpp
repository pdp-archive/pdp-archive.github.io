#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const long MAXN = long(10e6);
long N,S,T,A[MAXN+1],ans;

//θα αντικατασταθούν οι τιμές που ξεπερνούν το T με (S+1) οπότε
//θέλουμε 64bit για να αποθηκεύσουμε prefix sum πίνακα με 
// 10^6 μέρες κόστους (10^9+1) έκαστη (αν όλες οι μέρες
//ξεπερνούν το T).

long long PS[MAXN+1];//prefix sum του πίνακα A

int main(){
    FILE *in = fopen("crazyhotel.in","r");
    FILE *out = fopen("crazyhotel.out","w");
    fscanf(in,"%ld%ld%ld",&N,&S,&T);

    for(long i=1;i<=N;i++){
        fscanf(in,"%ld",&A[i]);
        if(A[i]>T)
            A[i] = S+1;
        PS[i] = PS[i-1] + A[i];
    }
    for(int i=1;i<=N;i++){
        long left = i, right = N, pos = -1, target = S + PS[i-1];
        while(left<=right){
            int mid = (left+right)/2;
            if(PS[mid]<=target){
                pos = mid;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        if(pos>=0)
            ans += (pos - i + 1);
    }
    fprintf(out,"%ld\n",ans);
    fclose(in);
    fclose(out);
    return 0;
}
