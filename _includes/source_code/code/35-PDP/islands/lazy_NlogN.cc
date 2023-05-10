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

long query(long si,long ss,long se,long L,long R){//return range sum
    pushlazy(si,ss,se);
    if(L<=ss && se<=R)
        return st[si];
    if(R<ss || se<L)
        return 0;
    long mid = (ss+se)/2;
    return query(si*2+1,ss,mid,L,R)+query(si*2+2,mid+1,se,L,R);
}

long query(long si,long ss,long se,long k){//return pos that spend k tickets
    while(ss<se){
        pushlazy(si,ss,se);
        long mid = (ss+se)/2;
        if(st[si*2+1] >= k){//πήγαινε αριστερά
            si = si*2+1;
            se = mid;
        } else {//πήγαινε δεξιά και αφαίρεσε τα χρησιμοποιημένα εισιτήρια των αριστερών νησιών
            k -= st[si*2+1];
            si = si*2+2;
            ss = mid+1;
        }
    }
    return ss;
}

int main(){
    freopen("islands.in","r",stdin);
    freopen("islands.out","w",stdout);
    scanf("%ld%ld",&N,&Q);
    st.resize((N+1)*4,0);
    lazy.resize(st.size(),-1);
    while(Q--){
        char c;long a,b;
        scanf(" %c%ld%ld",&c,&a,&b);
        if(c=='D'){
            upd(0,1,N+1,a+1,b,1);
        } else if(c=='B'){
            upd(0,1,N+1,a+1,b,0);
        } else {
            long p = query(0,1,N+1,1,a);//μετέτρεψε το ταξίδι από το a σε ταξίδι από το 1
            printf("%ld\n",query(0,1,N+1,b+p+1)-1);
        }
    }
    return 0;
}
