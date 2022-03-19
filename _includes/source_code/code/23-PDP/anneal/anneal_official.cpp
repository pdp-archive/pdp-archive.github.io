/*
USER : pdp23u29
LANG : C++
TASK : annealing
*/
#include<stdio.h>
#include<algorithm>

using namespace std;

int temp[26000], N;
long long sum, dp[26000];

int main() {
   freopen("anneal.in","r",stdin);
   freopen("anneal.out","w",stdout);
   int i, j;
   scanf("%d", &N);
   for(i=0;i<N;i++) scanf("%d", &temp[i]);
   for(i=N-1;i>=0;i--) {
      sum = 0;
      for(j=N-1;j>i;j--) {
         if(temp[j]>temp[i]) sum += temp[j]-temp[i];
         else {
            if(2*temp[j]<dp[j]-sum) sum += 2*temp[j];
            else sum += dp[j]-sum;
         }
      }
      dp[i] = sum;
   }
   sum = 0;
   for(j=N-1;j>=0;j--) {
      if(2*temp[j]<dp[j]-sum) sum += 2*temp[j];
      else sum += dp[j]-sum;
   }
   printf("%lld\n", sum);
   return 0;
}
