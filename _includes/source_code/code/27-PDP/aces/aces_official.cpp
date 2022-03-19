/*
USER: u1761
LANG: C++
TASK: aces
*/
#include <cstdio>

using namespace std;

int main() {
   freopen("aces.in", "r", stdin);
   freopen("aces.out", "w", stdout);
   int N;
   scanf("%d", &N);
   int * arr = new int[N];
   int table[32];
   for (int i =0; i < 32; ++i)
      table[i] = 0;
      int cnt,
      max = 0,
      cur;
      for(int i = 0; i < N; ++i) {
         scanf("%d", &arr[i]);
         cnt = 0;
         cur = arr[i];
         while(cur != 0) {
            if ((cur % 2) == 1)
               ++cnt;
            cur /= 2;
      }
      ++table[cnt];
      if (table[cnt] > table[max])
         max = cnt;
   }
   printf("%d\n", table[max]);
   return 0;
}
