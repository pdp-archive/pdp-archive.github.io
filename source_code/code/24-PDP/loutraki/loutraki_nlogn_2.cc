#include <bits/stdc++.h>

using namespace std;

const long MAXN = long(1e6);
const long OFFSET = long(1e5);

vector<long> X[2*OFFSET+1],Y[2*OFFSET+1];

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
		X[hotel[i].xx].push_back(hotel[i].yy);
		Y[hotel[i].yy].push_back(hotel[i].xx);
	}
	
	for(long x=0;x<2*OFFSET;x++)sort(X[x].begin(),X[x].end());
	for(long y=0;y<2*OFFSET;y++)sort(Y[y].begin(),Y[y].end());
	
	for(long i=1;i<=N;++i){
		if(X[hotel[i].xx][0] == hotel[i].yy && Y[hotel[i].yy][0] == hotel[i].xx)
			ans++;
		//αν η μικρότερη τιμή είναι η δικιά μας και στις δύο συντεταγμένες, 
		//τότε είμαστε προνομοιούχοι
	}
	printf("%ld\n", ans);
	return 0;
}
