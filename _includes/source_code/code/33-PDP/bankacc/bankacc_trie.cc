#include <cstdio>
#include <cassert>

//Αποθηκεύουμε τους αριθμούς λογαριασμών σε ένα trie
//Στη ρίζα του trie ξεκινούν τα ψηφία των μονάδων,
//ακολουθούν των δεκάδων κλπ
//Στον πίνακα next[] αποθηκεύουμε τις θέσεις
//που αντιστοιχούν στις 10 πιθανές τιμές του επόμενου στοιχείου. 
//Στον κόμβο που τελειώνει κάθε αριθμός, υπάρχει 
//το amount (το ποσό του λογαριασμού)

struct trie_node {
    size_t next[10L];   //επόμενη θέση (στο trie[])
    long amount;        //ποσό λογαριασμού που τελειώνει εδώ
} trie[1'000'000];      //το trie[0] είναι το root
size_t trie_num = 1;    //πόσα trie_node είναι σε χρήση

long& findacc(long account){
    size_t root = 0;
    while(account){
        size_t& next = trie[root].next[account % 10L];
        account /= 10L;
        if(next == 0){//δημιούργησε νέο κόμβο
            //Σημείωση: είναι δυνατό να σχεδιαστούν test cases που να
            //δημιουργήσουν εξαιρετικά "φαρδύ" το δέντρο και
            //να μην αρκούν οι προ-δεσμευμένοι κόμβοι στον πίνακα
            //trie[].
            assert(trie_num<sizeof(trie)/sizeof(trie[0]));
            next = trie_num++;//χρησιμοποίησε το πρώτο ελεύθερο trie[]
        }
        root = next;
    }
    return trie[root].amount;
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
