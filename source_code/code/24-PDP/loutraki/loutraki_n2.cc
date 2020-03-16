#include <bits/stdc++.h>

using namespace std;

#define MAXN	int(1e6)

int N, ans;
pair<int,int> hotel[MAXN+1];
#define	xx	first
#define	yy	second

int main() {
#ifdef CONTEST
	freopen("loutraki.in","r",stdin);
	freopen("loutraki.out","w",stdout);
#endif
	scanf("%d", &N);
	for(int i=1; i<=N; ++i)
		scanf("%d%d",&hotel[i].xx,&hotel[i].yy);
	for(int i=1;i<=N;++i){
		bool hidden = false;
		for(int j=1;j<=N && !hidden;j++){
			if(i==j)continue;
			if(hotel[j].xx == hotel[i].xx && hotel[j].yy < hotel[i].yy)
				hidden = true;
			if(hotel[j].yy == hotel[i].yy && hotel[j].xx < hotel[i].xx)
				hidden = true;
		}
		if(!hidden)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}
