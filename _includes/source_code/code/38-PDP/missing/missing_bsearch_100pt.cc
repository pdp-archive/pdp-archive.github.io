#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

vector<int> mem(5001);
int query(int x){
    if(!mem[x]){
        printf("? %d",x);
        fflush(stdout);
        scanf("%d",&mem[x]);
        if(mem[x]==-1)exit(0);
    }
    return mem[x];
}

int main(){
    int N,M,K;
    scanf("%d",&M);
    N = query(M);
    K = N - M;

    vector<pair<int,int>> missing;    //αριθμός που λείπει, πλήθος συνεχόμενων
    for(int i=0;i<K;i++){
        //δυαδική αναζήτηση για τον αριστερότερο αριθμό
        //που βρίσκεται i θέσεις αριστερότερα από την προβλεπόμενη θέση του
        int leftpos = 1, rightpos = M, missing_gap = -1;
        while(leftpos<=rightpos){
            int midpos = (leftpos+rightpos+1)/2, midval = query(midpos);
            if(midpos+i < midval){//ο αριθμός δεν βρέθηκε στη θέση του,
                //άρα λείπουν αριθμοί εδώ ή και αριστερότερα
                missing_gap = midval;
                rightpos = midpos-1;
            } else {//midpos==midval
                leftpos  = midpos+1;
            }
        }
        if(missing.size() && missing.back().first==missing_gap)
            missing.back().second++;
        else
            missing.push_back({missing_gap,1});
    }

    printf("! %d",K);
    for(auto u:missing){
        for(int i=-u.second;i<0;i++)
            printf(" %d",u.first+i);
    }
    fflush(stdout);
    return 0;
}
