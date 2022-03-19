#include <stdio.h>

int N, M, sci[1000010], count[1000010];

int main() {
   freopen("scidinner.in","r",stdin);
   freopen("scidinner.out","w",stdout);
   int i, j, a, b, mx;
   scanf("%d %d", &N, &M);
   for(i=0;i<M;i++) {
      scanf("%d %d", &a, &b);
      sci[b] = a;
   }
   mx = 0;
   for(i=1;i<=N;i++) {
      count[i] = 1;
      j = i;
      while(sci[j] > 0) {
         j = sci[j];
         if( count[j] > 0 ) {
            count[i] += count[j];
            break;
         }
         count[i]++;
      }
      j = i;
      while(sci[j] > 0 && count[ sci[j] ] == 0) {
         count[ sci[j] ] = count[j] - 1;
         j = sci[j];
      }
      if(count[i] > mx) mx = count[i];
   }
   printf("%d\n",mx);
   return 0;
}
