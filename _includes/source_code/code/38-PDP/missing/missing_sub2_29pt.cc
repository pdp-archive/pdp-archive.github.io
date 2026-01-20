#include <cstdio>
#include <cstdlib>
using namespace std;

int query(int x){
    printf("? %d",x);
    fflush(stdout);
    scanf("%d",&x);
    if(x==-1) exit(0);
    return x;
}

int main(){
    int N,M;
    scanf("%d",&M);
    N = M+1; //λείπει μόνο ένας αριθμός, άρα N=M+1 (δεν χρειάζεται query)
    int leftpos = 1, rightpos = M, missing=-1;
    while(leftpos<=rightpos){
        int midpos = (rightpos + leftpos + 1)/2, midval = query(midpos);
        if(midpos<midval){
            missing = midval;
            rightpos= midpos-1;
        } else {
            leftpos = midpos+1;
        }
    }
    printf("! 1 %d",missing);
    fflush(stdout);
    return 0;
}
