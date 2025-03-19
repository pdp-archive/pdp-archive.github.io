#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int t,S,X,Y;
long ans = 1000000000;
vector<char> Z;

void add_length_w(int w){
    for(int i=0;i < (1<<w);i++)//1<<w == 2^w 
        for(int j=w-1;j>=0;j--)
            Z.push_back((i & (1<<j))?'b':'a');
}

int main(){
#ifdef CONTEST
    freopen("shroompath.in","r",stdin);
    freopen("shroompath.out","w",stdout);
#endif
    scanf("%d%d%d%d",&t,&S,&X,&Y);
    int A = (X>0) ? (S+X-1)/X : -1;
    int B = (Y>0) ? (S+Y-1)/Y : -1;
    for(int w=1;w<=max(A,B);w++)
        add_length_w(w);

    if(X>0){
        vector<char> f(A,'a');
        long pos = search(Z.begin(), Z.end(), f.begin(), f.end()) - Z.begin();
        ans = min(ans,pos+A);
    }
    if(Y>0){
        vector<char> f(B,'b');
        long pos = search(Z.begin(), Z.end(), f.begin(), f.end()) - Z.begin();
        ans = min(ans,pos+B);
    }
    
    printf("%ld\n",ans);
    return 0;
}
