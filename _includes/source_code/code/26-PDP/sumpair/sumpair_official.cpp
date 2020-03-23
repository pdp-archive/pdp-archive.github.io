#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAXN = 1000002;
int a[MAXN];
int main() {
freopen("sumpair.in", "r", stdin);
freopen("sumpair.out", "w", stdout);
int n, q;
scanf("%d %d", &n, &q);
for(int i=0; i<n; ++i)
scanf("%d", a+i);
sort(a, a+n);
while(q--) {
int val;
scanf("%d", &val);
int ok = 0;
int lo = 0, hi = n-1;
while(lo < hi) {
if(a[lo] + a[hi] > val) hi--;
else if(a[lo] + a[hi] < val) lo++;
else {
ok = 1;
break;
}
}
if(ok) printf("true\n");
else printf("false\n");
}
return 0;
}
