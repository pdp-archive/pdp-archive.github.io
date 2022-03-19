#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long hasht;
const hasht MOD = hasht(1e9)+7;   //It is imperative that MOD*MOD fit hasht typedef
const long  MAXN = long(1e7);
const long  C = long(256); //number of characters in C++
long        N;
char        S[MAXN+5];

int main(){
#ifdef CONTEST
   freopen("minpali.in", "r",stdin);
   freopen("minpali.out","w",stdout);
#endif
   scanf("%ld %s",&N,S+1); //S+1 makes our string start from 1 instead of 0
   
   long maxPalindromicSuffix;
   hasht left_right = 0, right_left = 0, expC=1;
   for(long i=N;i>=1;i--){
      left_right = ( left_right + ((S[i]*expC)%MOD) ) % MOD;
      right_left = (((right_left*C)%MOD) + S[i] ) % MOD;
      expC = (expC * C) % MOD;
      if(left_right == right_left){
         maxPalindromicSuffix = N-i+1;
      }
   }
   printf("%ld\n",2*N-maxPalindromicSuffix);
   return 0;
}
