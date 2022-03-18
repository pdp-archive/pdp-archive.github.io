#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

const int MAXN = 10001;

int N,M,left=int(1e9),right=0;
vector<pair<int,int>> adj[MAXN];
vector<bool> visit;

int dfs(int u,int lim){
	visit[u] = true;
	int cnt = 0;
	for(auto e:adj[u])
		if(!visit[e.first] && e.second<=lim)
			cnt += dfs(e.first,lim);
	return cnt+1;
}

int main(){
    freopen("smalltank.in","r",stdin);
    freopen("smalltank.out","w",stdout);
	scanf("%d%d",&N,&M);
	for(int a,b,w,i=0;i<M;i++){
		scanf("%d%d%d",&a,&b,&w);
		adj[a].push_back({b,w});
		adj[b].push_back({a,w});
		right = max(right,w);
		left  = min(left, w);
	}
	while(left<right){
		int mid = (left+right)/2;
		visit = vector<bool>(N+1,false);
		if(dfs(1,mid)==N)
			right = mid;
		else
			left = mid+1;
	}
	printf("%d\n",left);
	return 0;
}
