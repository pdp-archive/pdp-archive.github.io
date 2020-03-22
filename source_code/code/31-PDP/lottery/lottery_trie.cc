#include <bits/stdc++.h>
const long MOD = 1e9+7;
const long MAXC = 1e6;
using namespace std;

long N, K, Q, newValue, cnt[MAXC+5];
long neib[MAXC+5][10];

long long pow2(long k) {
  if (k<=60) return (1LL<<k)%MOD;
  return ( ((1LL<<60)%MOD) * ((1LL<<(k-60))%MOD) ) % MOD;
}

int main()
{
  string tmp;
  long curr;
  freopen("lottery.in","r",stdin);
  freopen("lottery.out","w",stdout);
  cin >> K >> N >> Q;
  for(long i=1; i<=N; ++i) {
    curr = 0;
    cin >> tmp;
    reverse(tmp.begin(), tmp.end());
    for(long k=0; k<K; ++k) {
      if ( !neib[curr][ tmp[k]-'0' ] )
	neib[curr][ tmp[k]-'0' ] = ++newValue;
      curr = neib[curr][ tmp[k]-'0' ];
      ++cnt[curr];
    }
  }
  
  for(long i=1; i<=Q; ++i) {
    cin >> tmp;
    reverse(tmp.begin(), tmp.end());
    
    long long s = 0;
    long nwin = 0;
    curr = 0;
    for(long k=0; k<K; ++k) {
      if ( !neib[curr][ tmp[k]-'0' ] )
	break;
      curr = neib[curr][ tmp[k]-'0' ];
      //printf("aaa i=%d, k=%d, cnt=%d\n", i, k, cnt[curr]);
      if (k==0) nwin = cnt[curr];
      s = (s + cnt[curr]*(pow2(k+1)-pow2(k))) % MOD;
      if (s<0) s+= MOD;
    }
    cout << nwin << ' ' << s << '\n';
  }
  return 0;
}
