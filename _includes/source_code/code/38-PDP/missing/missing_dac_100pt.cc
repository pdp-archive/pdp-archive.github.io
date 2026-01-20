#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int query(int x){
    printf("? %d",x);
    fflush(stdout);
    scanf("%d",&x);
    if(x==-1) exit(0);
    return x;
}

vector<int> missing;
void divide_and_conquer(int leftval,int leftpos, int rightval,int rightpos){
    if(leftval>rightval)return;//κενό διάστημα
    if(rightpos-leftpos+1 <= 0){//λείπουν όλοι οι αριθμοί
        for(int i=leftval;i<=rightval;i++)missing.push_back(i);
        return;
    }
    if(rightpos-leftpos==rightval-leftval)return;//υπάρχουν όλοι οι αριθμοί

    int midpos = (rightpos+leftpos+1)/2, midval = query(midpos);

    divide_and_conquer(leftval,leftpos,midval-1,midpos-1);
    divide_and_conquer(midval+1,midpos+1,rightval,rightpos);
}

int main(){
    int N,M,K;
    scanf("%d",&M);
    N = query(M);
    K = N - M;
    divide_and_conquer(1,1,N,M);
    printf("! %zd",missing.size());
    for(auto u:missing)printf(" %d",u);
    fflush(stdout);
    return 0;
}
