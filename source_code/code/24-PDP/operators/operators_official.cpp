/* NAME: PANAGIOTIS KOSTOPANAGIOTIS
* TASK: OPERATORS
* LANG: C++
*/
#include <cstdio>
#include <vector>
#include <cmath>

int main() {
   freopen("operators.in","r",stdin);
   freopen("operators.out","w",stdout);
   long N,current=0,num[2] = {0, 1},min=1000000001;
   scanf("%ld",&N);
   std::vector<long> neg;
   for(int i=0; i<N; ++i) {
      scanf("%ld",&current);
      if(current>0 && !i) {
         num[0]=current;
         scanf("%ld", &num[1]);
         break;
      }
      if(current<0) neg.push_back(current);
      while (current>0 && neg.size()) {
         if(fabs(neg.back()+current)<min) {
            num[0]=neg.back();
            num[1]=current;
            min=fabs(num[0]+num[1]);
         }
         if(fabs(neg.back())>current) break;
         neg.pop_back();
      }
      if(neg.size()==0 || num[0]+num[1]==0) break;
   }
   if(neg.size()==N) {
      for(int i=0; i<2; ++i) {
         num[1-i]=neg.back();
         neg.pop_back();
      }
   }
   printf("%ld %ld\n", num[0],num[1]);
   return 0;
}

// dim131: Διορθώθηκαν τα εξής τρία λάθη:
//   1. Στην scanf: %d -> %ld
//   2. scanf(...) != EOF
//   3. num = {0, 1} (αρχικά πρέπει η συνθήκη num[0] + num[1] == 0 να είναι λάθος)
// Με κάποιους compilers οποιοδήποτε από αυτά βγάζει διαφορετικό αποτέλεσμα.
