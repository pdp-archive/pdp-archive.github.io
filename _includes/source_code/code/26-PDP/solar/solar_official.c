#include <stdio.h>

int checkmx[1000000], checkmi[1000000], max, min, i, N, nums[1000000];

int main(void) {
   freopen("solar.in", "r", stdin);
   freopen("solar.out", "w", stdout);
   max = -1;
   min = 1000001;
   scanf("%d", &N);
   for(i = 0; i < N; ++i) {
      scanf("%d", &nums[i]);
   }
   for(i = 0; i < N; ++i) {
      if(nums[i] > max) {
         checkmx[i] = 1;
         max = nums[i];
      }
      if(nums[N-1-i] < min) {
         checkmi[N-1-i] = 1;
         min = nums[N-1-i];
      }
   }
   max = -1;
   for(i = 0; i < N; ++i) {
      if(checkmi[i] == 1 && checkmx[i] == 1) {
         if(nums[i] > max) {
            max = nums[i];
         }
      }
   }
   if(max == -1) {
      printf("NOT FOUND\n");
   } else {
      printf("%d\n", max);
   }
   return 0;
}
