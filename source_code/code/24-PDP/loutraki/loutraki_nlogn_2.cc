#include <bits/stdc++.h>

using namespace std;

#define MAXN	int(1e6)
#define OFFSET	int(1e5)

vector<int> X[2*OFFSET+1],Y[2*OFFSET+1];

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
		X[hotel[i].xx].push_back(hotel[i].yy);
		Y[hotel[i].yy].push_back(hotel[i].xx);
	}
	
	for(int x=0;x<2*OFFSET;x++)sort(X[x].begin(),X[x].end());
	for(int y=0;y<2*OFFSET;y++)sort(Y[y].begin(),Y[y].end());
	
	for(int i=1;i<=N;++i){
		if(X[hotel[i].xx][0] == hotel[i].yy && Y[hotel[i].yy][0] == hotel[i].xx)
			ans++;
		//αν η μικρότερη τιμή είναι η δικιά μας και στις δύο συντεταγμένες, 
		//τότε είμαστε προνομοιούχοι
	}
	printf("%d\n", ans);
	return 0;
}
