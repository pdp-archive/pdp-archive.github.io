#include "findinglib.h"

#include <map>

std::map<int, int> queries;

// Αποφεύγουμε να κάνουμε δύο φορές το ίδιο query.
int do_query(int X) {
   if (queries.find(X) == queries.end()) queries[X] = query(X);
   return queries[X];
}

int main() {
   bool more_testcases = true;
   while (more_testcases) {
      int N = getN();
      queries.clear();
      int query_1 = do_query(1);
      int st = 1, en = N - 1;
      while (st < en) {
         int md = (st + en) / 2;
         int query_md = do_query(md);
         int query_md_plus = do_query(md + 1);
         if (query_md > query_md_plus) st = md + 1; 
         else en = md;
      }
      int A = st;
      int B = query_1 + 2 - A;
      more_testcases = answer(A, B);
   }
   return 0;
}
