#include <cstdio>
#include <vector>

using namespace std;

long N,Q;
vector<long> st;

long query(long si,long ss,long se,long L,long R){//υπολόγισε άθροισμα διαστήματος [L,R]
    if(R<ss || se<L || R<L)
        return 0;//βγήκαμε εκτός διαστήματος {L,R]
    if(L<=ss && se<=R)
        return st[si];//το διάστημα [ss,se] περιέχεται στο [L,R]
    long mid = (ss+se)/2;
    return query(si*2+1,ss,mid,L,R)+query(si*2+2,mid+1,se,L,R);
}

void upd(long si,long ss,long se,long pos,long val){//ενημέρωσε τη θέση pos με την τιμή val
    if(ss == se){//φτάσαμε στο φύλλο pos
        st[si] = val;
        return;
    }
    long mid = (ss+se)/2;
    if(pos<=mid)
        upd(si*2+1,ss,mid,pos,val);
    else
        upd(si*2+2,mid+1,se,pos,val);
    st[si] = st[si*2+1]+st[si*2+2];
}

int main(){
    freopen("islands.in","r",stdin);
    freopen("islands.out","w",stdout);
    scanf("%ld%ld",&N,&Q);
    st.resize(N*4,0);
    while(Q--){
        char c;long a,b;
        scanf(" %c%ld%ld",&c,&a,&b);
        if(c=='D'){
            if(b!=a+1)break;//wrong subtask
            upd(0,1,N,b,1);
        } else if(c=='B'){
            if(b!=a+1)break;//wrong subtask
            upd(0,1,N,b,0);
        } else {
            b += query(0,1,N,1,a);
            long left = a, right = N, ans = a;
            while(left<=right){
                long mid = (left+right)/2;
                if(query(0,1,N,1,mid) > b){
                    right = mid - 1;//δεν φτάσαμε μέχρι το mid με b εισιτήρια
                } else {
                    ans = mid;//το δεξιότερο όριο έως τώρα με b εισιτήρια
                    left = mid + 1;//ας δοκιμάσουμε ακόμα δεξιότερα
                }
            }
            printf("%ld\n",ans);
        }
    }
    return 0;
}
