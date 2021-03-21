#include <cstdio>
#include <algorithm>
#include <cstring>

const long MAXN = 1'000'000;

//Αποθηκεύμε τους αριθμούς λογαριασμών σε ένα Trie
//Στη ρίζα του trie ξεκινούν τα ψηφία των μονάδων,
//ακολουθούν των δεκάδων κλπ
//Στον πίνακα next[] αποθηκεύουμε δείκτες στους 
//κόμβους που συνεχίζουν στα 10 επόμενα ψηφία. 
//Στον κόμβο που τελειώνει κάθε αριθμός, υπάρχει 
//το amount (το ποσό του λογαριασμού)

struct trie_node {
    trie_node *next[10];
    long amount;
    trie_node(){
        memset(this,0,sizeof(*this));
    }
} trie_root;

long& findacc(long account){
    trie_node *root = &trie_root;
    while(account){
        long idx = account % 10L;
        account /= 10L;
        if(root->next[idx] == NULL)
            root->next[idx] = new trie_node();
        root = root->next[idx];
    }
    return root->amount;
}

int main(){
    freopen("bankacc.in", "r",stdin);
    freopen("bankacc.out","w",stdout);
    long N;
    scanf("%ld",&N);
    for(long i=0;i<N;i++){
        long acc,x; char tp;
        scanf(" %c %ld",&tp,&acc);
        long& amount = findacc(acc);
        switch(tp){
            case 'q':
                printf("%ld\n",(long)amount);
                break;
            case 'd':
                scanf("%ld",&x);
                amount += x;
                printf("s\n");
                break;
            case 'w':
                scanf("%ld",&x);
                if(x>amount){
                    printf("f\n");
                }else{
                    amount -= x;
                    printf("s\n");
                }
                break;
        }
    }
    return 0;
}
