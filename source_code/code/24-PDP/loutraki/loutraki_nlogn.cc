#include <bits/stdc++.h>

using namespace std;

#define MAXN	int(1e6)
#define OFFSET	int(1e5)

set<int> X[2*OFFSET+1],Y[2*OFFSET+1];

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
	for(int i=1; i<=N; ++i){
		scanf("%d%d",&hotel[i].xx,&hotel[i].yy);
		hotel[i].xx+=OFFSET;
		hotel[i].yy+=OFFSET;
		X[hotel[i].xx].insert(hotel[i].yy);
		Y[hotel[i].yy].insert(hotel[i].xx);
	}
	for(int i=1;i<=N;++i){
		if(*(X[hotel[i].xx].begin()) == hotel[i].yy && *(Y[hotel[i].yy].begin()) == hotel[i].xx)
			ans++;
		//αν η μικρότερη τιμή είναι η δικιά μας και στις δύο συντεταγμένες, 
		//τότε είμαστε προνομοιούχοι
	}
	printf("%d\n", ans);
	return 0;
}
