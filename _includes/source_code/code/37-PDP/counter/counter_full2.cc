#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

const ll inf = (ll)1e13;
vector<ll> a;
int n, q, subtask;

int bsearch(ll x){
    int l = 1, r = n, counter = 0;
    while(l <= r){
        counter++;
        int m = (l+r)/2;
        if(a[m] == x) 
            break;
        if(a[m] < x)
            l = m+1;
        else
            r = m-1;
    }
    return counter;
}

int main(){
#ifdef CONTEST    
    freopen("counter.in", "r", stdin);
    freopen("counter.out", "w", stdout);
#endif
    scanf("%d", &subtask);    
    scanf("%d %d", &n, &q);
    a.resize(n+1);
    for(int i = 1; i <= n; i++)scanf("%lld",&a[i]);
    
    vector<ll> A2;//ο πίνακας a[] επαυξημένος με τα συνεχόμενα διαστήματα 
        //ανύπαρκτων αριθμών. Σε κάθε διάστημα αποθηκεύουμε μόνο το δεξιό του άκρο
        //αριστερό άκρο θα είναι ο προηγούμενος υπαρκτός αριθμός του a[] +1
    vector<int> c(2*n+2);//αρκετός χώρος για τις τιμές των counter
    for(int i = 1; i <= n; i++) {
        if(i==1 || A2.back()!=a[i]-1)
            A2.push_back(a[i]-1);//δεξιό άκρο ανύπαρκτου τμήματος
        c[A2.size()] = bsearch(a[i]);//αποθήκευσε counter για τις υπαρκτές τιμές
        A2.push_back(a[i]);
    }
    A2.push_back(+inf);//δεξιότερο ανύπαρκτο διάστημα
    //Παρατηρήστε ότι το αριστερότερο ανύπαρκτο διάστημα (-inf,a[1]) έχει
    //δεξιό άκρο το a[1]-1 και έχει προστεθεί στην αρχή του A2[]
    
    c[0] = bsearch(A2[0]), c[A2.size()-1] = bsearch(A2.back());
    for(int i=1;i<A2.size();i++){
        if(c[i] == 0)//τα ανύπαρκτα διαστήματα θα ανακαλυφθούν μετά από τους υπαρκτούς αριθμούς που συνορεύουν
            c[i] = max(c[i-1],c[i+1]);
    }
	
    vector<ll> ps(A2.size());//prefix sums στον A2[]
    ps[0] = 0;
    for(int i=1;i<A2.size();i++)
        ps[i] = ps[i-1] + c[i] * (A2[i]-A2[i-1]);
    
    while (q--) {
        ll L, R, ans = 0;
        int j,k;
        scanf("%lld %lld", &L, &R);

        if(R<a[1]){
            ans = c[0] * (R-L+1);
        }else if(L>a[n]){
            ans = c[A2.size()-1] * (R-L+1);
        } else {
            j = lower_bound(A2.begin(), A2.end(), L) - A2.begin();
            k = prev(upper_bound(A2.begin(), A2.end(), R)) - A2.begin();
            ans += c[j] * (A2[j]-L+1);//τμήμα του αριστερότερου ανύπαρκτου διαστήματος του query
            ans += ps[k] - ps[j];//όλα τα ενδιάμεσα τμήματα υπαρκτών αριθμών και ανύπαρκτων διαστημάτων
            if(R > A2[k])//τμήμα του δεξιότερου ανύπαρκτου διαστήματος στο query
                ans += c[k+1] * (R-A2[k]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
