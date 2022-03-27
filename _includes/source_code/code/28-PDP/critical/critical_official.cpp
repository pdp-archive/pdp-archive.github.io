#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define MAXN 100001

int N, M;
vector<vector<int> > con(MAXN), cost(MAXN);
int dist[MAXN], INF = 2000000000, cnt[MAXN];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > Q;

int main () {

#ifdef CONTEST  
    freopen("critical.in", "rt", stdin);  
    freopen("critical.out", "wt", stdout);  
#endif  

	scanf("%d %d",&N,&M);
	while (M--) {
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		con[x].push_back(y);
		cost[x].push_back(z);
	}
	for (int i=2;i<=N;++i) dist[i] = INF;
	Q.push(make_pair(0,1));
	while (!Q.empty()) {
		pair<int,int> t = Q.top(); Q.pop();
		if (t.first > dist[t.second]) continue;
		for (int j=0;j<con[t.second].size();++j) {
			int x = con[t.second][j];
			if (dist[x] > t.first + cost[t.second][j]) {
				cnt[x] = 0;
				dist[x] = t.first + cost[t.second][j];
				Q.push(make_pair(dist[x], x));
			}
			else if (dist[x] == t.first + cost[t.second][j]) ++cnt[x];
		}
	}
	int a = 0, b = 0;
	for (int i=1;i<=N;++i) for (int j=0;j<con[i].size();++j) {
		int x = con[i][j];
		if (dist[x] == dist[i] + cost[i][j]) {
			++a;
			if (!cnt[x]) ++b;
		}
	}
	printf("%d %d\n",a,b);
	return 0;
}
