#include <cstdio>
using namespace std;
typedef long long ll;
#define MAXX 1000000000

int Q;
struct node {
	int L, R;
	node *l, *r;
	int cnt;
	ll sum;
	void add (int i) {
		if (L == R) {
			++cnt;
			sum += L;
			return;
		}
		int M = (L+R)/2;
		if (i <= M) {
			if (l == NULL) l = new node, *l = (node){L,M,0,0,0,0};
			l->add(i);
		}
		else {
			if (r == NULL) r = new node, *r = (node){M+1,R,0,0,0,0};
			r->add(i);
		}
		cnt = sum = 0;
		if (l) cnt = l->cnt, sum = l->sum;
		if (r) cnt += r->cnt, sum += r->sum;
	}
	void rem (int i) {
		if (L == R) {
			--cnt;
			sum -= L;
			return;
		}
		int M = (L+R)/2;
		if (i <= M) l->rem(i);
		else r->rem(i);
		cnt = sum = 0;
		if (l) cnt = l->cnt, sum = l->sum;
		if (r) cnt += r->cnt, sum += r->sum;
	}
	int getcnt (int i,int j) {
		if (i <= L && R <= j) return cnt;
		int M = (L+R)/2, ret = 0;
		if (i <= M && l) ret += l->getcnt(i,j);
		if (j > M && r) ret += r->getcnt(i,j);
		return ret;
	}
	ll getsum (int i,int j) {
		if (i <= L && R <= j) return sum;
		int M = (L+R)/2;
		ll ret = 0;
		if (i <= M && l) ret += l->getsum(i,j);
		if (j > M && r) ret += r->getsum(i,j);
		return ret;
	}
	int kth (int k) {
		if (L == R) return L;
		int M = (L+R)/2;
		int cntl = 0;
		if (l) cntl = l->cnt;
		if (k <= cntl) return l->kth(k);
		return r->kth(k-cntl);
	}
};

int main () {
	#ifdef CONTEST
	freopen("bicycle.in","r",stdin);
	freopen("bicycle.out","w",stdout);
	#endif
	node T = (node){1,MAXX,0,0,0,0};
	int N = 0;
	scanf("%d",&Q);
	while (Q--) {
		int t, x, y;
		scanf("%d",&t);
		if (t == 1) {
			scanf("%d",&x);
			++N;
			T.add(x);
		}
		else if (t == 2) {
			scanf("%d",&x);
			--N;
			T.rem(x);
		}
		else {
			scanf("%d %d",&x,&y);
			ll k = T.kth((N * y + x + y - 1) / (x+y));
			printf("%lld\n", x * (T.getcnt(0,k-1) * k - T.getsum(0,k-1)) + y * (T.getsum(k+1,MAXX+1) - T.getcnt(k+1,MAXX+1) * k));
		}
	}
	return 0;
}
