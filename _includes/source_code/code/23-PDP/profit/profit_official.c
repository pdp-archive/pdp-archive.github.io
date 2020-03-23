/* Νίκος Τζάμος */

#include<stdio.h>
#define BSIZE 1<<15

FILE *fin;
char buffer[BSIZE];
int bpos=0, bsize=0;

int readInt() {
  int d = 0,x = 0;
  char c;
  while(1) {
    if(bpos >= bsize) {
      bpos = 0;
      if(feof(fin)) return x;
      bsize = fread(buffer, 1, BSIZE, fin);
    }
    c = buffer[bpos++];
    if(c>='0' && c<='9') {
      x = x*10 + (c-'0');
      d = 1;
    } else if(d==1) return x;
  }
  return -1;
}

main(){
  double N,M = 0,a,m=1e6;
  fin = fopen("profit.in","r");
  freopen("profit.out","w",stdout);
  N = readInt();
  while(N--)a=readInt(),m=(m<a)?m:a,M=(M>a/m)?M:a/m;
  printf("%.3lf\n", M);
}
