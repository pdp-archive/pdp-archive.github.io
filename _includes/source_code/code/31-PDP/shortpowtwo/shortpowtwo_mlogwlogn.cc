#include <bits/stdc++.h>
using namespace std;
const long MAXN = 100000;
const long MAXM = 100000;
const long MAXNODES = 2000000;
const long INF = 0x3f3f3f3f;
const long MAXW = 100000;
const long MOD = 1e9+7;

typedef long long ll;

long N, M, pow2[MAXW+30], parent[MAXN+5], nextFreePosition;
vector<long> e[MAXN+5], w[MAXN+5];

struct SegTreeNode {
  ll hash;
  long left, right, lazy;
  SegTreeNode() {
    hash = left = right = lazy = 0;
  }
  long Left() {
    if (left==0) left = ++nextFreePosition;
    return left;
  }
  long Right() {
    if (right==0) right = ++nextFreePosition;
    return right;
  }
} nodes[MAXNODES+5]; //just give maximum memory available when working with persistency

void LazyPropagate(long v, long x, long y) {
  if (nodes[v].lazy) {
    nodes[v].lazy = 0;
    if (x==y) return;

    long mid = (x+y)/2, l, r;

    l = ++nextFreePosition;
    nodes[l] = nodes[ nodes[v].left ];
    nodes[l].lazy ^= 1;
    nodes[l].hash = (pow2[ mid-x+1 ] - 1 - nodes[l].hash) % MOD;
    if (nodes[l].hash < 0) nodes[l].hash += MOD;
    nodes[v].left = l;
    
    r = ++nextFreePosition;
    nodes[r] = nodes[ nodes[v].right ];
    nodes[r].lazy ^= 1;
    nodes[r].hash = (pow2[ y-mid ] - 1 - nodes[r].hash) % MOD;
    if (nodes[r].hash < 0) nodes[r].hash += MOD;
    nodes[v].right = r;
  }
}

bool Smaller(long root1, long root2, long x, long y) {
  LazyPropagate(root1,x,y);
  LazyPropagate(root2,x,y);
  if (x==y) return nodes[root1].hash < nodes[root2].hash;
  long mid  = (x+y)/2;
  if ( nodes[ nodes[root1].Right() ].hash != nodes[ nodes[root2].Right() ].hash ) {
    return Smaller (nodes[root1].Right(), nodes[root2].Right(), mid+1, y);
  }
  return Smaller (nodes[root1].Left(), nodes[root2].Left(), x, mid);
}

struct BigNum {
  bool isInf;
  long root;
  BigNum() {
    isInf = root = 0;
  }
  bool operator < (const BigNum &A) const {
    if (isInf) return false;
    if (A.isInf) return true;
    return Smaller(root, A.root, 0, MAXW+30-1);
  }
} dist[MAXN+5];

long Flip(long v, long x, long y, long qx, long qy) {
  LazyPropagate(v,x,y);
  long ret = ++nextFreePosition;
  nodes[ret] = nodes[v];
  if (x==qx && y==qy) {
    nodes[ret].lazy = 1;
    nodes[ret].hash = (pow2[y-x+1] - 1 - nodes[ret].hash) % MOD;
    if (nodes[ret].hash < 0) nodes[ret].hash += MOD;
    return ret;
  }
  long mid=(x+y)/2;
  if(qy<=mid) {
    nodes[ret].left = Flip(nodes[v].Left(), x, mid, qx, qy);
  } else if (qx>mid) {
    nodes[ret].right = Flip(nodes[v].Right(), mid+1, y, qx, qy);
  } else {
    nodes[ret].left = Flip(nodes[v].Left(), x, mid, qx, mid);
    nodes[ret].right = Flip(nodes[v].Right(), mid+1, y, mid+1, qy);
  }
  nodes[ret].hash = ((ll)nodes[ nodes[ret].Left() ].hash + (ll)pow2[mid-x+1] * nodes[ nodes[ret].Right() ].hash) % MOD;
  return ret;
}

long Next0(long v, long x, long y, long qx, long qy) {
  LazyPropagate(v,x,y);
  long mid = (x+y)/2;
  if (x==qx && y==qy) {
    if (nodes[v].hash == (pow2[y-x+1]-1)) return MAXW+30-1;
    if (x==y) return x;
    if (nodes[ nodes[v].Left() ].hash == (pow2[mid-x+1]-1)) return Next0(nodes[v].Right(),mid+1,y,mid+1,qy);
    return Next0(nodes[v].Left(),x,mid,x,mid);
  }

  if (qy <= mid ) return Next0( nodes[v].Left(), x, mid, qx, qy);
  else if (qx > mid) return Next0( nodes[v].Right(), mid+1, y, qx, qy);
  long left = Next0(nodes[v].Left(), x, mid, qx, mid);
  if (left < MAXW+30-1) return left;
  return Next0(nodes[v].Right(), mid+1, y, mid+1, qy);
}

BigNum Add(BigNum x, long exp) {
  long next0 = Next0(x.root, 0, MAXW+30-1, exp, MAXW+30-1);
  BigNum y;
  y.root = Flip(x.root, 0, MAXW+30-1, exp, next0);
  return y;
}

void Dijkstra(long S, long T) {
  set< pair<BigNum,long> > Set;
  for(long i=1; i<=N; ++i)
    dist[i].isInf = true;
  dist[S].isInf = false;
  parent[S] = 0;
  Set.insert( {dist[S],S} );
  while(!Set.empty()) {
    long curr = (*Set.begin()).second;
    if (curr==T) {
      break;
    }
    Set.erase ( Set.begin() );

    for(long i=0; i<e[curr].size(); ++i) {
      long to = e[curr][i], d=w[curr][i];
      BigNum tmp = Add(dist[curr],d);
      if ( tmp < dist[to] ) {
	if ( !dist[to].isInf ) {
	  Set.erase ( Set.find ( {dist[to],to} ));
	}
	dist[to] = tmp;
	parent[to] = curr;
	Set.insert( {dist[to],to} );
      }
    }
  }

  if (Set.empty())
    printf("-1\n");
  else {
    long ans = 0, curr = T, i;
    while (curr != S) {
      for(i=0; e[parent[curr]][i] != curr; ++i);
      ans = (ans + pow2[ w[parent[curr]][i] ]) % MOD;
      curr = parent[curr];
    }
    printf("%ld\n", ans);
  }
}

int main() {
  freopen("shortpowtwo.in","r",stdin);
  freopen("shortpowtwo.out","w",stdout);
  long a, b, c, S, T;
  scanf("%ld %ld", &N, &M);
  for(long i=1; i<=M; ++i) {
    scanf("%ld %ld %ld", &a, &b, &c);
    e[a].push_back(b);
    w[a].push_back(c);
  }
  scanf("%ld %ld", &S, &T);

  pow2[0] = 1;
  for(long i=1; i<MAXW+30; ++i)
    pow2[i] = (2*pow2[i-1]) % MOD;

  Dijkstra(S,T);
  return 0;
}
