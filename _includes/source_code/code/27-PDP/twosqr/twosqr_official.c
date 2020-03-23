#include <stdio.h>
#include <stdlib.h>

int pin2[1010];
int pin[1010];
int sinarthsh (int n, int c) {
   int psq, i;
   psq = c - n*n;
   if (n*n >= psq) {
      for (i=0; i*i<=psq; i++) {
         if (i*i == psq) {
            //printf("%d %d\n", n, i);
            return 1;
         }
      }
   }
   return 0;
}
int main(void) {
   freopen ("twosqr.in", "r", stdin);
   freopen ("twosqr.out", "w", stdout);
   int t, i, j, o;
   scanf("%d", &t);
   for (i=1; i<=t; i++) {
      scanf("%d",&pin[i]);
   }
   for (i=1; i<=t; i++) {
      //printf("%d\n", pin[i]);
      for (j=0; j*j<=pin[i]; j++) {
         if (sinarthsh(j, pin[i]) == 1) {
            pin2[i]++;
         }
      }
   }
   for (i=1; i<=t; i++) {
      printf("%d\n", pin2[i]);
   }
   return 0;
}
