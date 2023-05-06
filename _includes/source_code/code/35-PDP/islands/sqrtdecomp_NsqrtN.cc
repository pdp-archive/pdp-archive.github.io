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
	/* εναλλακτικός μικρότερος κώδικας της ίδιας συνάρτησης
	for(long id=bucket_no(a),zid=bucket_no(b);id<=zid;id++){
		long x=bucket_begin(id), y=bucket_end(id);
		if(a<=x && y<=b){
			S[id] = val * (y-x+1), L[id] = val;
			//οι τιμές Z[i] του bucket δεν ενημερώθηκαν. Ισχύει το L[id]
		} else {
			S[id] = 0;
			for(long i=x;i<=y;i++){
				if(a<=i && i<=b)
					Z[i] = val;
				else if(L[id]!=-1)
					Z[i] = L[id];
				S[id]+=Z[i];
			}
			L[id]=-1;
			//Οι τιμές Z[i] του bucket ενημερώθηκαν.
		}
	}*/
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
	//ξεκινώντας από το νησί a, προσπέρνα νησιά μέχρι να ξοδέψουμε b εισιτήρια
	//Είμαστε ήδη στο a, οπότε αρχίζουμε έλεγχο από το a+1
	long ans = a, id = bucket_no(a+1), l_id=bucket_no(N-1);
	long x = bucket_begin(id), y = bucket_end(id);
	
	if(x < a+1){//Στο πρώτο bucket χρειαζόμαστε μόνο τμήμα του (κάνε brute force στο bucket)
		while(ans+1<=y && ((L[id]==0 || (L[id]==-1 && Z[ans+1]==0)) || b-->0))
			ans++;
		if(ans<y) 
			id = l_id+1; //Δεμ φτάσαμε μέχρι το τέλος του bucket. Εξαντλήσαμε εισιτήρια
		else 
			id++;//ολοκληρώσαμε το bucket αυτό και συνεχίζουμε
	}
	while(id<=l_id && (S[id]<=b)){//προσπέρνα γρήγορα ολόκληρα buckets
		b -= S[id];
		ans = bucket_end(id);
		id++; 
	}
	x=bucket_begin(id), y=bucket_end(id);		
	if(id<=l_id){//brute force στο bucket που δεν μπορούμε να προσπεράσουμε ολόκληρο
		while(ans+1<=y && ((L[id]==0 || (L[id]==-1 && Z[ans+1]==0)) || b-->0))
			ans++;
	}
	return ans;
}
	
int main(){
	freopen("islands.in","r",stdin);
	freopen("islands.out","w",stdout);
	scanf("%d%d",&N,&Q);
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
			printf("%ld\n",query(a,b)+1);//κάνε την απάντηση 1 based
		}
	}
	return 0;
}
