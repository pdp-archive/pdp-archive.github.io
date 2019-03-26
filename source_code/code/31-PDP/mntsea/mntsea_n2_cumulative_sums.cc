#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000005
typedef long long ll;
long N, sumM[MAXN], sumS[MAXN];
char str[MAXN];

long Sum(long left, long right, long sum[]) {
	return sum[right]-sum[left-1];
}

long validWithFixedRight(long right) {
	long ans=0;
	for(long left=1; left<=right; ++left)
		if(Sum(left,right,sumM)==Sum(left,right,sumS)) ++ans;

	return ans;
}

int main() {
	#ifdef CONTEST
	freopen("mntsea.in","r",stdin);
	freopen("mntsea.out","w",stdout);
	#endif

	scanf("%ld %s", &N, str+1);
	for (long i=1; i<=N; ++i) {
		if(str[i]=='m') {
			sumM[i]=sumM[i-1]+1;
			sumS[i]=sumS[i-1];
		} else {
			sumM[i]=sumM[i-1];
			sumS[i]=sumS[i-1]+1;
		}
	}
				
	ll ans = 0;
	for(long right=1; right<=N; ++right)
		ans += validWithFixedRight(right);
	printf("%lld\n", ans);
	
	return 0;
}
