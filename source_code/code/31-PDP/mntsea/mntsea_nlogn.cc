#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000005
typedef long long ll;
long N, sumM[MAXN], sumS[MAXN];
char str[MAXN];
map<long, long> howManyWithDiff;

long validWithFixedRight(long right) {
	long diff = sumM[right]-sumS[right];
	long ans = howManyWithDiff[diff];
	++howManyWithDiff[diff];
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
	howManyWithDiff[0] = 1;
				
	ll ans = 0;
	for(long right=1; right<=N; ++right)
		ans += validWithFixedRight(right);
	printf("%lld\n", ans);
	
	return 0;
}
