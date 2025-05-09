#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

const ll inf = (ll)1e13;
vector<ll> A;
long n, q;
int subtask;

int FindCounter(ll x){
    long l = 1, r = n, counter = 0;
    while(l <= r){
        counter++;
        long m = (l+r)/2;
        if(A[m] == x) 
            break;
        if(A[m] < x)
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
    scanf("%ld %ld", &n, &q);
    A.resize(n+1);
    for(long i = 1; i <= n; i++)scanf("%lld",&A[i]);
    
    vector<ll> A2;//ο πίνακας A[] επαυξημένος με τα συνεχόμενα διαστήματα 
        //ανύπαρκτων αριθμών. Σε κάθε διάστημα αποθηκεύουμε μόνο το δεξιό του άκρο
        //αριστερό άκρο θα είναι ο προηγούμενος υπαρκτός αριθμός του A[]+1
    vector<int> C(2*n+2);//αρκετός χώρος για τις τιμές των FindCounter του A2
    for(long i = 1; i <= n; i++) {
        if(i==1 || A2.back()!=A[i]-1)
            A2.push_back(A[i]-1);//δεξιό άκρο ανύπαρκτου τμήματος
        C[A2.size()] = FindCounter(A[i]);//αποθήκευσε FindCounter για τις υπαρκτές τιμές
        A2.push_back(A[i]);
    }
    A2.push_back(+inf);//δεξιότερο ανύπαρκτο διάστημα
    //Tο αριστερότερο ανύπαρκτο διάστημα (-inf,a[1]) έχει
    //δεξιό άκρο το a[1]-1 και έχει προστεθεί στην αρχή του A2[] για i=1
    
    C[0] = FindCounter(A2[0]), C[A2.size()-1] = FindCounter(A2.back());
    for(long i=1;i<A2.size();i++){
        if(C[i] == 0)//τα ανύπαρκτα διαστήματα υπολογίζονται μετά από τους υπαρκτούς αριθμούς που συνορεύουν
            C[i] = max(C[i-1],C[i+1]);
    }
	
    vector<ll> PS(A2.size());//prefix sums στον C[]
    PS[0] = 0;
    for(long i=1;i<A2.size();i++)
        PS[i] = PS[i-1] + C[i] * (A2[i]-A2[i-1]);
    
    while (q--) {
        ll L, R, ans = 0;
        long j,k;
        scanf("%lld %lld", &L, &R);

        if(R<A[1]){
            ans = C[0] * (R-L+1);
        }else if(L>A[n]){
            ans = C[A2.size()-1] * (R-L+1);
        } else {
            j = lower_bound(A2.begin(), A2.end(), L) - A2.begin();
            k = prev(upper_bound(A2.begin(), A2.end(), R)) - A2.begin();
            ans += C[j] * (A2[j]-L+1);//τμήμα του αριστερότερου ανύπαρκτου διαστήματος του query
            ans += PS[k] - PS[j];//όλα τα ενδιάμεσα τμήματα υπαρκτών αριθμών και ανύπαρκτων διαστημάτων
            if(R > A2[k])//τμήμα του δεξιότερου ανύπαρκτου διαστήματος στο query
                ans += C[k+1] * (R-A2[k]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
