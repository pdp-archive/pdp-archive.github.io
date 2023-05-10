#include <cstdio>
#include <vector>

using namespace std;

long N,Q;
vector<long> st;
vector<int> lazy;

void pushlazy(long si,long ss,long se){
    if(lazy[si]==-1)
        return;//no lazy here
    if(ss == se){//leaf
        st[si] = lazy[si];
        lazy[si]=-1;
        return;
    }
    long mid = (ss+se)/2;
    lazy[si*2+1] = lazy[si*2+2] = lazy[si];//σπρώξε πιο κάτω το lazy
    st[si*2+1] = (mid-ss+1)*lazy[si];//άθροισμα του διαστήματος που καλύπτει το αριστερό παιδί
    st[si*2+2] = (se-(mid+1)+1)*lazy[si];//άθροισμα του διαστήματος που καλύπτει το αριστερό παιδί
    st[si] = st[si*2+1]+st[si*2+2];//υπολόγισε το άθροισμα του τρέχοντος κόμβου
    lazy[si] = -1;//έφυγε το lazy από τον τρέχοντα κόμβο
}

void upd(long si,long ss,long se,long L,long R,int val){
    if(R<ss || se<L)
        return;
    if(L<=ss && se<=R){
        lazy[si] = val;//ακόμα και αν είχε κάποιο lazy εδώ, ας χαθεί (ακυρώνεται)
        st[si] = (se-ss+1) * val;
        return;
    }
    pushlazy(si,ss,se);//αν τα παλιά lazy δεν ακυρώνονταν, η γραμμή αυτή θα έπρεπε να μπει πριν το προηγούμενο if 
    long mid = (ss+se)/2;
    upd(si*2+1,ss,mid,L,R,val);
    upd(si*2+2,mid+1,se,L,R,val);
    st[si] = st[si*2+1]+st[si*2+2];
}

long query(long si,long ss,long se,long L,long R){//βρες το άθροισμα διαστήματος
    pushlazy(si,ss,se);
    if(L<=ss && se<=R)
        return st[si];
    if(R<ss || se<L)
        return 0;
    long mid = (ss+se)/2;
    return query(si*2+1,ss,mid,L,R)+query(si*2+2,mid+1,se,L,R);
}

int main(){
    freopen("islands.in","r",stdin);
    freopen("islands.out","w",stdout);
    scanf("%ld%ld",&N,&Q);
    st.resize(N*4,0);
    lazy.resize(st.size(),-1);
    while(Q--){
        char c;long a,b;
        scanf(" %c%ld%ld",&c,&a,&b);
        if(c=='D'){
            upd(0,1,N,a+1,b,1);
        } else if(c=='B'){
            upd(0,1,N,a+1,b,0);
        } else {            
            b += query(0,1,N,1,a);//μετέτρεψε το ταξίδι από το a σε ταξίδι από το 1
            long left = a,right = N,ans = a;
            while(left<=right){
                long mid = (left+right)/2;
                if(query(0,1,N,1,mid)>b){//πήγαινε αριστερά
                    right = mid - 1;
                } else {//φτάσαμε έως εδώ, δοκίμασε ακόμα δεξιότερα
                    ans  = mid;
                    left = mid + 1;
                }
            }
            printf("%ld\n",ans);
        }
    }
    return 0;
}
