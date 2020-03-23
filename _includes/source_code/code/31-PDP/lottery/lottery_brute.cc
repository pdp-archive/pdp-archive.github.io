#include <bits/stdc++.h>
const long MOD = 1e9+7;
using namespace std;

long N, K, Q;
vector<string> X;
string strQ;

long long pow2(long k) {
  if (k<=60) return (1LL<<k)%MOD;
  return ( ((1LL<<60)%MOD) * ((1LL<<(k-60))%MOD) ) % MOD;
}

int main()
{
  string tmp;
  freopen("lottery.in","r",stdin);
  freopen("lottery.out","w",stdout);
  cin >> K >> N >> Q;
  X.push_back(" ");
  for(long i=1; i<=N; ++i) {
    cin >> tmp;
    reverse(tmp.begin(), tmp.end());
    X.push_back(tmp);
  }
  
  for(long i=1; i<=Q; ++i) {
    cin >> strQ;
    reverse(strQ.begin(), strQ.end());
    
    long long s = 0;
    long nwin = 0;
    for(long j=1; j<=N; ++j) {
      long k;
      for(k=0; k<K && strQ[k] == X[j][k]; ++k);
      if (k>0) {
	s = (s+pow2(k)-1) % MOD;
	++nwin;
      }
    }
    cout << nwin << ' ' << s << '\n';
  }
  return 0;
}
