#include "findinglib.h"

int main() {
   bool more_testcases = true;
   while (more_testcases) {
      int N = getN();
      int query_1 = query(1);
      int st = 1, en = N;
      while (st < en) {
         int md = (st + en + 1) / 2;
         int query_md = query(md);
         if (query_md == query_1 - 2 * (md - 1)) st = md; 
         else en = md - 1;
      }
      int A = st;
      int B = query_1 + 2 - A;
      more_testcases = answer(A, B);
   }
   return 0;
}
