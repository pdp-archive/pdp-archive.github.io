#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const long MAXN = long(10e6);
long N,S,T,ans;

long A[MAXN+1],PS[MAXN+1];//prefix sum του πίνακα A

void solve(long L,long R){
    //βρέθηκε ένα συνεχόμενο διάστημα ημερών [L,R] όπου 
    //καμία μέρα δεν ξεπερνα το κόστος T
    while(L<=R){
        long left = L, right = R, pos = -1, target = S + PS[L-1];
        //pos θα είναι η δεξιότερη μέρα όπου PS[pos]<=target
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
            ans += (pos - L + 1);
        L++;
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
        PS[i] = PS[i-1] + x;
        if(x>T){
            solve(L,i-1);
            L = i + 1;
        }
    }
    solve(L,N);
    fprintf(out,"%ld\n",ans);
    fclose(in);
    fclose(out);
    return 0;
}
