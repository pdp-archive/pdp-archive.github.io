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

long FirstWithLCP(long k) {
  long low=0, high=N+1, mid, i;
  while(low<high) {
    mid = (low+high)/2;
    for(i=0; i<k && X[mid][i] == strQ[i]; ++i);
    if(i==k || X[mid][i] > strQ[i]) high = mid;
    else low=mid+1;
  }
  return low;
}

long LastWithLCP(long k) {
  long low=0, high=N+1, mid, i;
  while(low<high) {
    mid = (low+high+1)/2;
    for(i=0; i<k && X[mid][i] == strQ[i]; ++i);
    if(i==k || X[mid][i] < strQ[i]) low = mid;
    else high=mid-1;
  }
  return low;
}

int main()
{
  string tmp;
  freopen("lottery.in","r",stdin);
  freopen("lottery.out","w",stdout);
  cin >> K >> N >> Q;
  X.push_back(" ");
  X[0][0] = '0'-1; //smaller than everything
  for(long i=1; i<=N; ++i) {
    cin >> tmp;
    reverse(tmp.begin(), tmp.end());
    X.push_back(tmp);
  }
  sort(X.begin()+1, X.begin()+N+1);
  X.push_back(" ");
  X[N+1][0] = '9'+1; //bigger than everything
  
  for(long i=1; i<=Q; ++i) {
    cin >> strQ;
    reverse(strQ.begin(), strQ.end());
    
    long long s = 0;
    long nwin = 0;
    for(long k=1; k<=K; ++k) {
      long x = FirstWithLCP(k);
      long y = LastWithLCP(k);
      if (k==1) nwin = (y-x+1);
      s = (s + (y-x+1)*(pow2(k)-pow2(k-1))) % MOD;
      if (s<0) s+= MOD;
      //cout << "K = " << k << " gives " << x << '-' << y << endl;
    }
    cout << nwin << ' ' << s << '\n';
  }
  return 0;
}
