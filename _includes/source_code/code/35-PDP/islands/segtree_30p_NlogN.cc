#include <cstdio>
#include <vector>

using namespace std;

long N,Q;
vector<long> st;

long query(long si,long ss,long se,long L,long R){//υπολόγισε άθροισμα διαστήματος
	if(R<ss || se<L || R<L)
		return 0;
	if(L<=ss && se<=R)
		return st[si];
	long mid = (ss+se)/2;
	return query(si*2+1,ss,mid,L,R)+query(si*2+2,mid+1,se,L,R);
}

long query(long si,long ss,long se,long B){//βρες τη δεξιότερη θέση x, με sum[1,x]=B
	while(ss<se){ 
		long mid = (ss+se)/2;
		if(B < st[si*2+1]){//πήγαινε αριστερά
			si = si*2+1;
			se = mid;
		} else {
			//Τα εισιτήρια μας έφτασαν για να καλυφθεί το αριστερό segment
			//αλλά ίσως εξαντλήθηκαν. Ακόμα και αν εξαντλήθηκαν, θα προχωρήσουμε στο 
			//δεξιό segment (ώστε να προσπεράσουμε τα νησιά που δεν χρειάζονται εισιτήριο).
			//Φτάνοντας στο φύλλο του δέντρου, θα αποφασίσουμε αν το παρακάναμε.
			B -= st[si*2+1];//αφαίρεσε τα χρησιμοποιημένα εισιτήρια του αριστερού segment
			si = si*2+2;
			ss = mid+1;
		}
	}
	if(B<st[si])//τα εισιτήρια μας έχουν εξαντληθεί και δεν μπορούμε να φτάσουμε στο νησί ss.
		ss--;
	return ss;
}

void upd(long si,long ss,long se,long pos,long val){
	if(ss == se){
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
			b += query(0,1,N,1,a);//εισιτήρια από νησί 1 έως και a			
			printf("%ld\n",query(0,1,N,b));
		}
	}
	return 0;
}
