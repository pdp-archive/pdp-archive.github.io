#include <cstdio>
#include <algorithm>

const long MAXN = 1'000'000L;

long A[MAXN], PS[MAXN], SS[MAXN+1];
//Στον πίνακα SS (suffix sum) χρησιμοποιούνται τα στοιχεία
//από τη θέση 1 έως και την N+1
//Στον πίνακα PS (prefix sum) χρησιμοποιούνται τα στοιχεία
//από τη θέση 0 έως και τη N

int main(){
    freopen("landfight.in","r",stdin);
    freopen("landfight.out","w",stdout);
    
    long N;
    scanf("%ld",&N);
    for(long i=1;i<=N;i++){
        scanf("%ld",A+i);
        PS[i] = PS[i-1] + A[i];//prefix sum
    }
    for(long i=N;i>0;i--)
        SS[i] = SS[i+1] + A[i];
    
    long ans = N;
    for(long i=1;i<=N;i++){
        for(long j=i+1;j<=N+1;j++){
            //Στη θέση SS[N+1] υπάρχει αποθηκευμένο το 0
            //(περίπτωση R=0, κανένα χωράφι στον δεξιό τσιφλικά)
            if(PS[i] == SS[j]){
                ans = std::min(ans, j-i-1);
                break;//δεν έχει νοήμα να συνεχίσουμε 
                //διότι θα βρούμε χειρότερο αποτέλεσμα
            }
        }
    }
    printf("%ld\n",ans);
    return 0;
}
