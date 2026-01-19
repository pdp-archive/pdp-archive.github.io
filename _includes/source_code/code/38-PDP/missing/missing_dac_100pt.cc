#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int query(int x){
    printf("? %d",x);
    fflush(stdout);
    scanf("%d",&x);
    if(x==-1)exit(0);
    return x;
}

vector<int> m;//missing ones
void dac(int leftval,int leftpos, int rightval,int rightpos){//divide and conquer
    if(leftval>rightval)return;
    if(rightpos-leftpos+1 <= 0){//λείπουν όλοι οι αριθμοί
        for(int i=leftval;i<=rightval;i++)m.push_back(i);
        return;
    }
    if(rightpos-leftpos==rightval-leftval)return;//υπάρχουν όλοι οι αριθμοί

    int midpos = (rightpos+leftpos+1)/2, midval = query(midpos);

    dac(leftval,leftpos,midval-1,midpos-1);
    dac(midval+1,midpos+1,rightval,rightpos);
}

int main(){
    int N,M,K;
    scanf("%d",&M);
    N = query(M);
    K = N - M;
    dac(1,1,N,M);
    sort(m.begin(),m.end());
    printf("! %zd",m.size());
    for(auto u:m)printf(" %d",u);
    fflush(stdout);
    return 0;
}
