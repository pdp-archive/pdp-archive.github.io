#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

const long MAXN = 1'000'000L;

long A[MAXN];
struct myvector {
    long head;//πρώτη θέση που δεν έχει ξεπεραστεί ακόμα
    vector<long> pos;
    myvector(){
        head = -1;//δεν υπάρχουν στοιχεία στον πίνακα
    }
    long query(long i){
        //αφαίρεσε τις θέσεις που ξεπεράστηκαν
        while(head>=0 && pos[head]<=i)
            head--;
        return (head>=0)?pos[head]:(MAXN+1);
    }
    void push(long x){
        pos.push_back(x);
        head++;//δείκτης στο τελευταίο στοιχείο
    }
};

unordered_map<int, myvector> M;

int main(){
    freopen("landfight.in","r",stdin);
    freopen("landfight.out","w",stdout);
    
    long N;
    scanf("%ld",&N);
    for(long i=1;i<=N;i++)
        scanf("%ld",A+i);
    
    M[0].push(N+1);//περίπτωση L=N,R=0
    for(long suffix=0L,i=N;i>0;i--){
        suffix +=A[i];
        M[suffix].push(i);
    }
    
    long ans = N;
    for(long prefix=0L,i=1;i<=N;i++){
        prefix += A[i];
        if(M.find(prefix) == M.end())
            continue;        
        ans = min(ans,M[prefix].query(i)-i-1);
    }
    
    printf("%ld\n",ans);
    return 0;
}
