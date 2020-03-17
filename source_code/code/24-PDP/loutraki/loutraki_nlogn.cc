#include <bits/stdc++.h>

using namespace std;

const long MAXN = long(1e6);
const long OFFSET = long(1e5);

set<long> X[2*OFFSET+1],Y[2*OFFSET+1];

long N, ans;
pair<long,long> hotel[MAXN+1];
#define	xx	first
#define	yy	second

int main() {
#ifdef CONTEST
	freopen("loutraki.in","r",stdin);
	freopen("loutraki.out","w",stdout);
#endif
	scanf("%ld", &N);
	for(long i=1; i<=N; ++i){
		scanf("%ld%ld",&hotel[i].xx,&hotel[i].yy);
		hotel[i].xx+=OFFSET;
		hotel[i].yy+=OFFSET;
		X[hotel[i].xx].insert(hotel[i].yy);
		Y[hotel[i].yy].insert(hotel[i].xx);
	}
	for(long i=1;i<=N;++i){
		if(*(X[hotel[i].xx].begin()) == hotel[i].yy && *(Y[hotel[i].yy].begin()) == hotel[i].xx)
			ans++;
		//αν η μικρότερη τιμή είναι η δικιά μας και στις δύο συντεταγμένες, 
		//τότε είμαστε προνομοιούχοι
	}
	printf("%ld\n", ans);
	return 0;
}
