#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[1010];
int ans[10010];
pair<int,int> B[10010];
vector <int> P[10010];

int main() {
  #ifdef CONTEST
    freopen("erasmus.in", "r", stdin);
    freopen("erasmus.out", "w", stdout);
  #endif
    scanf("%d %d", &N, &M);

    int i, j, pan, S, K, in;
    for(i=0;i<N;i++) scanf("%d", &A[i]);
    for(i=0;i<M;i++) {
        scanf("%d %d", &S, &K);
        for(j=0;j<K;j++) {
            scanf("%d", &pan);
            P[i].push_back(pan-1);
        }
        B[i] = make_pair(S, i);
    }
    sort(B, B+M, greater< pair<int,int> >());
    
    bool gotin = false;
    for(i=0; i<M; i++) {
      in = B[i].second;      
      gotin = false;
      for(j=0;j<P[in].size();j++) {
	if( A[ P[in][j] ]>0){
	  A[ P[in][j] ]--;
	  ans[in] = P[in][j];
	  gotin = true;
	  break;
	}
      }
      if(!gotin) ans[in] = -1;
    }

    for(i=0;i<M;i++) {
        if(ans[i]!=-1)
            printf("%d\n", ans[i]+1);
        else
            printf("NONE\n");
    }
}
