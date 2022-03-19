#include <bits/stdc++.h>

using namespace std;

const long MAXN = long(1e7);
long N;
char S[MAXN+5];

bool is_palindrome(long from){
  //check if S[from...N] is a palindrome
  //that is, if S[from...N] == reverse(S)[from...N]
  for(int i=0; i<=(N-from); ++i)
    if (S[from+i] != S[N-i]) return false;
  return true;
}

int main(){
#ifdef CONTEST
  freopen("minpali.in","r",stdin);  
  freopen("minpali.out","w",stdout);
#endif

  long from;
  scanf("%ld %s",&N,S+1); //Writing S+1 puts the first character in index 1 instead of 0
  for(from=1; from<=N && !is_palindrome(from); ++from)
    ;
  long maxPalindromicSuffix = N-from+1;
  printf("%ld\n",2*N-maxPalindromicSuffix);
  return 0;
}
