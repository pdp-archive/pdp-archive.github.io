#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

long ans,N,M;
struct rect {
    long height;//ύψος height
    long left;//αριστερή ακμή του ορθογωνίου 
    rect(long height,long left):height(height),left(left){}
};

int main(){
    FILE *in = fopen("olivetrees.in","r");
    fscanf(in,"%ld%ld",&N,&M);
    std::stack<rect> S;
    for(long h,i=0;i<M;i++){
        fscanf(in,"%ld",&h);
        h = N - h;
        rect p(h,i);//το ύψος h ξεκινά στη στήλη i
        //αφαίρεσε τα μεγαλύτερα ύψη της στοίβας (αν υπάρχουν)
        while(!S.empty() && S.top().height>=h){
            //υπολόγισε εμβαδό ορθογωνίου που καταργείται
            ans = std::max(ans, (i-S.top().left)*S.top().height);
            p.left = S.top().left;//το ύψος h ξεκινά από τη θέση του ύψους που κατήργησε
            S.pop();
        }
        S.push(p);
    }
    fclose(in);

    //αφαίρεσε από τη στοίβα όσα ορθογώνια φτάνουν μέχρι το δεξιό άκρο M-1
    while(!S.empty()){
        //υπολόγισε εμβαδό ορθογωνίου που καταργείται
        ans = std::max(ans,(M-S.top().left)*S.top().height);
        S.pop();
    }
    FILE *out = fopen("olivetrees.out","w");
    fprintf(out,"%ld\n",ans);
    fclose(out);
    return 0;
}
