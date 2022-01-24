#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 1000001

int N, A[MAXN], B[MAXN], maxdp[MAXN];
vector<pair<int,int> > mx[MAXN];
pair<int,int> v[MAXN];
bool cmp (const int &a, const int &b) {
	return a - A[a] < b - A[b];
}
int main () {
	#ifdef CONTEST
	freopen("bookeaters.in","r",stdin);
	freopen("bookeaters.out","w",stdout);
	#endif
	scanf("%d",&N);
	for (int i=1;i<=N;++i) scanf("%d",&A[i]), B[i] = i;
	sort(A+1,A+N+1);
	sort(B+1,B+N+1,cmp);
	mx[0].push_back(make_pair(0,0));
	for (int i=1;i<=N;++i) {
		if (A[i] <= i) maxdp[i] = max(maxdp[i-1], maxdp[i-A[i]] + 1);
		else maxdp[i] = maxdp[i-1];
	}
	for (int _i=1,j=1;_i<=N;++_i) {
		int i = B[_i];
		if (A[i] <= i) {
			for (;j<=i-A[i];++j) if (v[j].first) {
				while (!mx[v[j].first].empty() && mx[v[j].first].back().first >= v[j].second) mx[v[j].first].pop_back();
				mx[v[j].first].push_back(make_pair(v[j].second,j));
			}
			int dp = maxdp[i-A[i]];
			int l = 0, r = mx[dp].size()-1;
			while (l < r) {
				int m = (l+r)/2;
				int a = max(mx[dp][m].first, i - mx[dp][m].second), b = max(mx[dp][m+1].first, i - mx[dp][m+1].second);
				if (a < b) r = m;
				else if (a > b) l = m+1;
				else l = r = m;
			}
			int get = max(mx[dp][l].first, i - mx[dp][l].second);
			if (i == N) printf("%d %d\n", dp + 1, get);
			else v[i] = make_pair(dp + 1, get);
		}
	}
	return 0;
}
