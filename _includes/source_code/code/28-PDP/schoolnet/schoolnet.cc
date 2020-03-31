#include <bits/stdc++.h>
using namespace std;
const long MAXN = 1000000;

long weight[MAXN+5], vc_with[MAXN+5], vc_without[MAXN+5];
vector<vector<long> > con(MAXN+5);

long VC_with(long i, long par);

long VC_without(long i, long par) {
  if (vc_without[i] == -1 ) {
    vc_without[i]=0;
    for (long j=0;j<con[i].size();++j) {
      long x = con[i][j];
      if (x == par) continue;
      vc_without[i] += VC_with(x,i);
    }
  }
  return vc_without[i];
}

long VC_with (long i, long par) {
  if (vc_with[i] == -1) {
    vc_with[i] = weight[i];
    for (long j=0;j<con[i].size();++j) {
      long x = con[i][j];
      if (x == par) continue;
      vc_with[i] += min(VC_with(x,i),VC_without(x,i));
    }
  }
  return vc_with[i];
}

int main () {
  freopen("schoolnet.in","r",stdin);
  freopen("schoolnet.out","w",stdout);
  long N;
  scanf("%ld",&N);
  for (long i=1;i<=N;++i) scanf("%ld",&weight[i]);
  for (long i=1;i<N;++i) {
    long x,y;
    scanf("%ld %ld",&x,&y);
    con[x].push_back(y);
    con[y].push_back(x);
  }
  memset(vc_with,-1,sizeof(vc_with));
  memset(vc_without,-1,sizeof(vc_without));  
  printf("%ld\n",min(VC_with(1,-1), VC_without(1,-1)));
  return 0;
}
