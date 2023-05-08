#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long N,Q,SQ;
vector<int> Z;//1 ή 0 (Z[i]==1 αν χρειαζόμαστε εισιτήριο για να φτάσουμε στο νησί i)
vector<long> S;//άθροισμα του bucket
vector<int> L;//Lazy τιμές των buckets. L[id]==-1 αν δεν έχουμε lazy τιμή. 

inline long bucket_no(long pos){ return pos / SQ; }//ποιος ο αριθμός bucket του νησιού pos
inline long bucket_begin(long id){ return (id)*SQ; }//πρώτο νησί του bucket id 
inline long bucket_end(long id) { return min(N-1,bucket_begin(id+1)-1); }//τελευταίο νησί του bucket id

void upd(long a,long b,int val){
    long b_id=bucket_no(a),l_id=bucket_no(b);//πρώτο και τελευταίο bucket που επηρεάζονται
    long x=bucket_begin(b_id), y=bucket_end(b_id);
    if(x<a){//από το πρώτο bucket επηρεάζεται τμήμα του μόνο
        S[b_id] = 0;//θα επανυπολογίσουμε το άθροισμα
        for(long i=x;i<=y;i++){
            if(i<a||i>b){
                if(L[b_id]!=-1)Z[i]=L[b_id];//κράτα τις τιμές Z[i] που δεν επηρεάζονται
            }else {
                Z[i]=val;//ενημέρωσε τις τιμές Z[i] που επηρεάζονται 
            }
            S[b_id]+=Z[i];
        }
        L[b_id]=-1;//δεν υπάρχει κοινή τιμή για όλα τα Z[i] στο bucket
        b_id++;
    }
    while(b_id<=l_id && (y=bucket_end(b_id))<=b){//ενημέρωση ολόκληρων buckets
        L[b_id] = val; 
        S[b_id] = (y-bucket_begin(b_id)+1)*val;
        b_id++;
    }    
    if(b_id==l_id){//ενημέρωση τμήματος bucket στο τελευταίο bucket
        x = bucket_begin(b_id), y=bucket_end(b_id);
        S[b_id]=0;
        for(long i=x;i<=y;i++){
            if(i<=b)
                Z[i] = val;
            else if(L[b_id]!=-1)
                Z[i] = L[b_id];
            S[b_id]+=Z[i];
        }
        L[b_id]=-1;
    }
}

long query(long a,long b){
    long ans = 0;
    for(long id=bucket_no(a),zid=bucket_no(b);id<=zid;id++){
        long x=bucket_begin(id), y=bucket_end(id);
        if(a<=x && y<=b){//μέτρησε ολόκληρο το bucket
            ans += S[id];
        } else {//μέτρησε τμήμα του bucket
            for(long i=max(x,a),z=min(y,b);i<=z;i++)
                ans += (L[id]==-1) ? Z[i] : L[id];
        }
    }
    return ans;
}

int main(){
    freopen("islands.in","r",stdin);
    freopen("islands.out","w",stdout);
    scanf("%ld%ld",&N,&Q);
    SQ = max(1L,(long)sqrt(N));
    Z.resize(N+1,0);
    S.resize(N/SQ+1,0);
    L.resize(N/SQ+1,0);
    while(Q--){
        char c;long a,b;
        scanf(" %c%ld%ld",&c,&a,&b);
        if(c=='D'){
            a--,b--;//τα Z[i] στα buckets είναι zero based
            upd(a+1,b,1);
        } else if(c=='B'){
            a--,b--;//τα Z[i] στα buckets είναι zero based
            upd(a+1,b,0);
        } else {
            a--;//τα Z[i] στα buckets είναι zero based
            b += query(0,a);//μετέτρεψε το ταξίδι από το a σε ταξίδι από το 0
            long left = a, right = N-1, ans = a;
            while(left<=right){
                long mid = (left+right)/2;
                if(query(0,mid) > b){
                    right = mid - 1;//δεν αρκούν τα εισιτήρια για να φτάσουμε στο mid
                } else {
                    ans = mid;//το δεξιότερο νησί που φτάσαμε έως τώρα
                    left = mid + 1;//ας δοκιμάσουμε ακόμα δεξιότερα
                }
            }
            printf("%ld\n",ans+1);//κάνε απάντηση 1 based
        }
    }
    return 0;
}
