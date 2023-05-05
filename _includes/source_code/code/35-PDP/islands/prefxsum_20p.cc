#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(){
	freopen("islands.in","r",stdin);
	freopen("islands.out","w",stdout);
	long N,Q,qq;
	scanf("%ld%ld",&N,&Q);
	vector<vector<long>> E(N+1);//συμβάντα έναρξης-λήξης ανακοινώσεων
	vector<int> S(Q+1);//είδος ανακοίνωσης (1=έναρξη απεργίας,0=λήξη)
	
	char c;long a,b;
	for(qq=1;qq<=Q;qq++){//q=χρονική σειρά της ανακοίνωσης
		scanf(" %c%ld%ld",&c,&a,&b);
		if(c=='Q')break;//αρχίζουν τα ερωτήματα
		S[qq] = (c=='D');
		E[a+1].push_back(qq);//εδώ ξεικινά το διάστημα της ανακοίνωσης
		E[b+1].push_back(-qq);//εδώ έλειξε το διάστημα της ανακοίνωσης
	}
	//προετοίμασε τον πίνακα prefix sum
	set<long> A;//αποθηκεύουμε τις ενεργές ανακοινώσεις
	A.insert(0);//Τη χρονική στιγμή 0, οι μετακινήσεις είναι δωρεάν
	vector<long> PS(N+1,0);//prefix sum
	for(long i=1;i<=N;i++){
		for(auto ev:E[i]){
			if(ev>0)
				A.insert(ev);//ξεκινά η ανακοίνωση με αριθμό ev
			else
				A.erase(-ev);//τελείωσε η ανακοίνωση με αριθμό -ev
		}
		int z = S[*A.rbegin()];//υπολόγισε το Z[i] από την πιο πρόσφατη ανακοίνωση
		PS[i] = PS[i-1] + z;
	}
	//απάντηση ερωτημάτων. Τα c,a,b περιέχουν το 1ο ερώτημα
	while(qq++<=Q){
		//βρες τελευταία θέση με PS[x]==PS[a]+b
		long ans = upper_bound(PS.begin(),PS.end(),PS[a]+b)-PS.begin();
		printf("%ld\n",ans-1);
		if(qq<=Q){
			scanf(" %c%ld%ld",&c,&a,&b);
			if(c!='Q') break;//δεν βρισκόμαστε στο σωστό subtask
		}
	}
	return 0;
}
