#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

long ans,N,M;
struct rect {
    long height;//ύψος height
    long left;//αριστερή συντεταγμένη παραλληλογράμου 
    rect(long height,long left):height(height),left(left){}
};

int main(){
    FILE *in = fopen("olivetrees.in","r");
    fscanf(in,"%ld%ld",&N,&M);
    std::stack<rect> S;
    for(long h,i=0;i<M;i++){
        fscanf(in,"%ld",&h);
        h = N - h;
        rect p(h,i);
        while(!S.empty() && S.top().height>=h){
            ans = std::max(ans, (i-S.top().left)*S.top().height);
            p.left = S.top().left;
            S.pop();
        }
        S.push(p);
    }
    fclose(in);
    while(!S.empty()){
        ans = std::max(ans,(M-S.top().left)*S.top().height);
        S.pop();
    }
    FILE *out = fopen("olivetrees.out","w");
    fprintf(out,"%ld\n",ans);
    fclose(out);
    return 0;
}
