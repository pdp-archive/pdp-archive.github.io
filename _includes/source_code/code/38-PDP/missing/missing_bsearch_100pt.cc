#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 5000;
int mem[MAXN];
int query(int x){//αποθηκεύουμε στο mem[x-1] το query(x), ώστε
    if(!mem[x-1]){//να μην ξανακάνουμε δύο φορές το ίδιο ερώτημα
        printf("? %d\n",x);
        fflush(stdout);
        scanf("%d",&mem[x-1]);
        if(mem[x-1]==-1) exit(0);
    }
    return mem[x-1];
}

int main(){
    int N,M,K;
    scanf("%d",&M);
    N = query(M);
    K = N - M;

    vector<pair<int,int>> missing; //αριστερά από τη θέση first, λείπουν second συνεχόμενοι αριθμοί.
    for(int i=0;i<K;i++){
        //δυαδική αναζήτηση για τον αριθμό που βρίσκεται 
		//i θέσεις αριστερότερα από την αναμενόμενη θέση του.
        int leftpos = 1, rightpos = M, missing_gap = -1;
        while(leftpos<=rightpos){
            int midpos = (leftpos+rightpos+1)/2, midval = query(midpos);
            if(midpos+i < midval){//ο αριθμός δεν βρέθηκε στη θέση του,
                //άρα λείπουν αριθμοί εδώ ή και αριστερότερα.
                missing_gap = midval;
                rightpos = midpos-1;
            } else {
                leftpos  = midpos+1;
            }
        }
        if(missing.size() && missing.back().first==missing_gap)
            missing.back().second++;
        else
            missing.push_back({missing_gap,1});
    }

    printf("! %d",K);
    for(auto u:missing)
        for(int i=-u.second;i<0;i++)
            printf(" %d",u.first+i);
    putchar('\n');
    fflush(stdout);
    return 0;
}
