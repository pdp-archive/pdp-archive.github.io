#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const long MAXN = long(10e6);
long N,S,T,A[MAXN+1],PS[MAXN+1];//prefix sum του πίνακα A
long long ans;

void solve(long L,long R){
    //βρέθηκε ένα συνεχόμενο διάστημα ημερών [L,R] όπου 
    //καμία μέρα δεν ξεπερνα το κόστος T
    for(long intsum=0,right=L-1,lastright=L-1,left=L;left<=R;left++){
        while(right+1<=R && intsum+A[right+1]<=S)
            intsum += A[++right];
        long n = right-left+1;
        //το άθροισμα n όρων αριθμητικής προόδου με α1=1 και ω=1 είναι n*(n+1)/2
        ans += 1LL*n * (1LL+n)/2LL;
        if(lastright>=L){//αφαίρεσε το διπλομετρημένο διάστημα [lastright,left]
            n = lastright-left+1;
            ans -= 1LL*n*(1LL+n)/2LL;
        }
        lastright = right;
        intsum -= A[left];
    }
}

int main(){
    FILE *in = fopen("crazyhotel.in","r");
    FILE *out = fopen("crazyhotel.out","w");
    fscanf(in,"%ld%ld%ld",&N,&S,&T);

    long L = 1;
    for(long x,i=1;i<=N;i++){
        fscanf(in,"%ld",&x);
        A[i] = x;
        if(x>T){
            solve(L,i-1);
            L = i + 1;
        }
    }
    solve(L,N);
    fprintf(out,"%lld\n",ans);
    fclose(in);
    fclose(out);
	return 0;
}
