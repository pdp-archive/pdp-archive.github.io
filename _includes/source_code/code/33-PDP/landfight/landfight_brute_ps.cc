#include <cstdio>
#include <algorithm>

const long MAXN = 1'000'001L;

long A[MAXN];

//Στον υπολογισμό των prefix sums χρησιμοποιούμε το προηγούμενο 
//στοιχείο για να υπολογίσουμε το τρέχον. Στον πίνακα A
//χρησιμοποιούνται τα στοιχεία 1 έως και N άρα στον PS 
//χρησιμοποιούνται τα στοιχεία από τη θέση 0 έως και τη N
long PS[MAXN];

//Στον υπολογισμό των suffix sums χρησιμοποιούμε το επόμενο
//στοιχείο για να υπολογίσουμε το τρέχον. Στον πίνακα A
//χρησιμοποιούνται τα στοιχεία 1 έως και N άρα στον SS
//χρησιμοποιούνται τα στοιχεία από τη θέση 1 έως και την N+1
long SS[MAXN+1];

int main(){
    freopen("landfight.in","r",stdin);
    freopen("landfight.out","w",stdout);
    
    long N;
    scanf("%ld",&N);
    for(long i=1;i<=N;i++){
        scanf("%ld",A+i);
        PS[i] = PS[i-1] + A[i];
    }
    for(long i=N;i>0;i--)
        SS[i] = SS[i+1] + A[i];
    
    long ans = N;
    for(long i=1;i<=N;i++){
        for(long j=i+1;j<=N+1;j++){
            //Το j==N+1 αντιστοιχεί στην περίπτωση L=N και R=0, 
            //δηλαδή κανένα χωράφι στον δεξιό τσιφλικά)
            if(PS[i] == SS[j]){
                ans = std::min(ans, j-i-1);
                break;
                //Δεν έχει νόημα να συνεχίσουμε γιατί τα υπόλοιπα διαστήματα είναι μεγαλύτερα
            }
        }
    }
    printf("%ld\n",ans);
    return 0;
}
