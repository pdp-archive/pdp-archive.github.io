#include <bits/stdc++.h>

using namespace std;

const long MAXN = long(1e6);

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
	for(long i=1; i<=N; ++i)
		scanf("%ld%ld",&hotel[i].xx,&hotel[i].yy);
	for(long i=1;i<=N;++i){
		bool hidden = false;
		for(long j=1;j<=N && !hidden;j++){
			if(i==j)continue;
			if(hotel[j].xx == hotel[i].xx && hotel[j].yy < hotel[i].yy)
				hidden = true;
			if(hotel[j].yy == hotel[i].yy && hotel[j].xx < hotel[i].xx)
				hidden = true;
		}
		if(!hidden)
			ans++;
	}
	printf("%ld\n", ans);
	return 0;
}
