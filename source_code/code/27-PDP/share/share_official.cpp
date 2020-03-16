// Volikas Markos
# include <cstdio>
# include <algorithm>

using namespace std;

int N,cum[1000005];
bool can(int m) {
int first_cut=lower_bound(cum,cum+N,m)-cum;
if (first_cut==N || cum[first_cut]>m) first_cut--;
if (first_cut>=N-1) return true;
int second_cut=lower_bound(cum+first_cut+1,cum+N,cum[first_cut]+m)-
cum;
if (second_cut==N || cum[second_cut]>cum[first_cut]+m) second_cut--;
if (second_cut<=first_cut) return false;
if (second_cut>=N-1) return true;
if (cum[N-1]-cum[second_cut]>m) return false;
return true;
}
inline void fastScan(int &x) {
register int c=getc_unlocked(stdin);
x=0;
for (; (c<48 || c>57); c=getc_unlocked(stdin));

for (; (c>47 && c<58); c=getc_unlocked(stdin)) { x=(x<<1) + (x<<3) + c-48; }

}
int main() {
freopen("share.in","r",stdin);
freopen("share.out","w",stdout);
int i,a,lo,hi,mid,tmp,ans;
fastScan(N);
fastScan(cum[0]); lo=cum[0];
for (i=1; i<N; ++i) {
fastScan(a);
cum[i]=cum[i-1]+a;
lo=max(lo,a);
}
hi=cum[N-1];
while (lo<hi) {
mid=(lo+hi)>>1;
if (can(mid)) hi=mid;
else lo=mid+1;
}
printf("%d\n",hi);
return 0;
}
