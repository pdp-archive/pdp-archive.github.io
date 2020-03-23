#include<stdio.h>
#include<string.h>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
#define MAXN 1005
#define f first
#define s second
#define mp make_pair
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define BASE 256
#define MOD 7293847562347896LL
int N,dp[MAXN][MAXN],back[MAXN][MAXN];
void Read () {
scanf("%d",&N);
for (int i=1;i<=N;i++) {
for (int j=1;j<=i;j++) {
scanf("%d",&back[i][j]);
}
}
}
void Solve() {
dp[1][1]=back[1][1]; // base cases of dp
for (int i=2;i<=N;i++) {
for (int j=1;j<=i;j++) {
if (j!=i)
dp[i][j]=max(dp[i][j],dp[i-1][j]+back[i][j]);
if (j!=1)
dp[i][j]=max(dp[i][j],dp[i-1][j-1]+back[i]

[j]);
}
}
int ans=0;
for (int i=1;i<=N;i++)
ans=max(dp[N][i],ans);
printf("%d\n",ans);
}
int main () {
freopen("triangle.in","r",stdin);
freopen("triangle.out","w",stdout);
Read();
Solve();
return 0;
}