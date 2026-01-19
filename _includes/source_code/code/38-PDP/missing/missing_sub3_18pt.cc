#include <cstdio>
#include <cstdlib>
using namespace std;

int query(int x){
    printf("? %d",x);
    fflush(stdout);
    scanf("%d",&x);
    if(x==-1)exit(0);
    return x;
}

int main(){
    int N,M,K;
    scanf("%d",&M);
    N = query(M);
    K = N - M;

    //Αναζητούμε τη θέση που θα έπρεπε να υπάρχουν οι K αριθμοί.
    int leftpos = 1, rightpos = M, missing_gap = -1;
    while(leftpos<=rightpos){
        int midpos = (leftpos+rightpos+1)/2, midval = query(midpos);
        if(midpos < midval){
            missing_gap = midval;
            rightpos = midpos-1;
        } else {
            leftpos  = midpos+1;
        }
    }
    printf("! %d",K);
    for(int i=missing_gap-K;i<=missing_gap;i++)
        printf(" %d",i);
    fflush(stdout);
    return 0;
}
