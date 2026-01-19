#include <cstdio>
#include <vector>
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
    vector<int> exist;
    int N,M;

    scanf("%d",&M);
    exist.resize(M+1);
    exist[M] = N = query(M);

    for(int i=1;i<M;i++)
        exist[i] = query(i);
    printf("! %d",N-M);
    //το i απαριθμεί όλους τους αριθμούς
    //το j απαριθμεί τους υπαρκτούς αριθμούς,
    //ξεκινώντας από τον 1ο
    for(int i=1,j=1;i<=N;i++){
        if(exist[j] == i)//βρέθηκε ο j-οστός υπαρκτός αριθμός
            j++;//προετοιμάσου για τον επόμενο
        else
            printf(" %d",i);
    }
    fflush(stdout);
    return 0;
}
