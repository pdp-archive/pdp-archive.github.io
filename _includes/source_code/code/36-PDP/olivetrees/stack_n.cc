#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

long ans,N,M;
struct rect {
    long height;
    long left;//left position of rectangle with heught, height
    rect(long height,long left):height(height),left(left){}
};

int main(){
    scanf("%ld%ld",&N,&M);
    std::stack<rect> S;
    for(long h,i=0;i<M;i++){
        scanf("%ld",&h);
        h = N - h;
        rect p(h,i);
        while(!S.empty() && S.top().height>=h){
            ans = std::max(ans, (i-S.top().left)*S.top().height);
            p.left = S.top().left;
            S.pop();
        }
        S.push(p);
    }
    while(!S.empty()){
        ans = std::max(ans,(M-S.top().left)*S.top().height);
        S.pop();
    }
    printf("%ld\n",ans);
    return 0;
}
