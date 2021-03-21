#include <cstdio>
#include <algorithm>

const long MAXN = 1'000'000;

struct query {
    long acc, id, x;
    char tp;
    bool operator < (const query& z) const {
        if(acc == z.acc)
            return id < z.id;
        return acc < z.acc;
    }
} Q[MAXN];

enum answers {
    FAIL = -2,
    SUCCESS = -1
};

long ans[MAXN];
    //θα αποθηκεύουμε -2 για fail, 
    //-1 για success ή
    //μη αρνητικό αριθμό για εκτύπωση υπολοίπου

int main(){
    freopen("bankacc.in", "r",stdin);
    freopen("bankacc.out","w",stdout);
    long N;
    scanf("%ld",&N);
    for(size_t i=0;i<N;i++){
        Q[i].id = i;
        scanf(" %c %ld",&Q[i].tp,&Q[i].acc);
        if(Q[i].tp != 'q')
            scanf(" %ld",&Q[i].x);
    }
    
    std::sort(Q,Q+N);
    
    long curr = 0;//υπόλοιπο τρέχοντος λογαριασμού
    for(int i=0;i<N;i++){
        if(i && Q[i].acc!=Q[i-1].acc){
            //περάσαμε στον επόμενο λογαριασμό
            curr = 0;
        }
        switch(Q[i].tp){
            case 'q':
                ans[Q[i].id] = curr;
                break;
            case 'd':
                curr += Q[i].x;
                ans[Q[i].id] = SUCCESS;
                break;
            case 'w':
                if(curr<Q[i].x){
                    ans[Q[i].id] = FAIL;
                }else{
                    ans[Q[i].id] = SUCCESS;
                    curr -= Q[i].x;
                }
                break;
        }
    }
    
    for(int i=0;i<N;i++){
        if(ans[i]>=0)
            printf("%ld\n",ans[i]);
        else if(ans[i]==FAIL)
            printf("f\n");
        else 
            printf("s\n");
    }
    
    return 0;
}
