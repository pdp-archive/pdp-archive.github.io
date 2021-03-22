#include <cstdio>
#include <algorithm>
#include <cstring>

//Αποθηκεύμε τους αριθμούς λογαριασμών σε ένα trie
//Στη ρίζα του trie ξεκινούν τα ψηφία των μονάδων,
//ακολουθούν των δεκάδων κλπ
//Στον πίνακα next[] αποθηκεύουμε δείκτες στους 
//που αντιστοιχούν στις 10 πιθανές τιμές του επόμενου στοιχείου. 
//Στον κόμβο που τελειώνει κάθε αριθμός, υπάρχει 
//το amount (το ποσό του λογαριασμού)

struct trie_node {
    trie_node *next[10];
    long amount;
    //Ακολουθεί ο constructor του αντικειμένου που θα κάνει και αρχικοποίηση
    trie_node(){
        //μηδένισε το περιεχόμενο του αντικειμένου (μηδένισε τα sizeof *this 
        //bytes του αντικειμένου)
        memset(this,0,sizeof(*this));
    }
    //Ακολουθεί ο destructor του αντικειμένου που ελευθερώνει τη μνήμη
    //που δεσμέυσαμε (αναδρομικά για όλους τους απογόνους του κόμβου).
    //Σε περιβάλλον διαγωνισμού, δεν είναι απαραίτητο να ελευθερώσουμε
    //τη μνήμη που δεσμεύσαμε, ειδικά όταν αποτελείται από μικρά τμήματα
    //όπως εδώ, ώστε να μην χάσουμε τον σχετικό χρόνο.
    //Η μνήμη ελευθερώνεται αυτόματα από το λειτουργικό σύστημα όταν 
    //το πρόγραμμα μας τερματιστεί με αποδοτικότερο τρόπο.
    ~trie_node(){//destructor: ελευθέρωσε όλη τη μνήμη του δέντρου trie
        for(int i=0;i<10;i++)
            delete next[i];
    }
} *trie_root;

long& findacc(long account){
    trie_node *root = trie_root;
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
    trie_root = new trie_node();
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
    delete trie_root;
    return 0;
}
