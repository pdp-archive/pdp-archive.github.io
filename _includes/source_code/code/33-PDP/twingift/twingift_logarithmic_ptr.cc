#include <cstdio>
#include <algorithm>

using namespace std;

const long MAXN = 1'000'000L;

long A[MAXN], NA /*N*/, B[MAXN], MB /*M*/, L,R;

int main(){
    freopen("twingift.in","r",stdin);
    freopen("twingift.out","w",stdout);
    
    scanf("%ld%ld%ld%ld",&NA,&MB,&L,&R);
    for(long i=0;i<NA;i++)scanf("%ld",A+i);
    for(long i=0;i<MB;i++)scanf("%ld",B+i);
    
    sort(A,A+NA);
    sort(B,B+MB);
    
    long ans = 0, left = MB, right = MB;
    
    for(long i=0;i<NA;i++){
        long LL = L-A[i], RR = R-A[i];//όρια για υποσύνολο του B
        
        //Μετακίνησε το left όσο πιο αριστερά γίνεται 
        //παραμένοντας εντός του διαστήματος [LL,RR]
        while(left>0 && B[left-1]>=LL)left--;
        
        //Μετακίνησε το right όσο γίνεται προς τα αριστερά 
        //παραμένοντας εκτός του διαστήματος [LL,RR]
        //(ώστε να λειτουργεί παρόμοια με το upper_bound)
        while(right>0 && B[right-1]>RR)right--;

        if(!right)break;//δεν υπάρχουν άλλοι συνδυασμοί
        
        ans += right-left;
    }
    
    printf("%ld\n",ans);
    return 0;
}
