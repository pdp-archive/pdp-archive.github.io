/* Ιωάννης Χατζημίχος (8ο ΓΕΛ Λαρίσης) */
      
#include <stdio.h>
#include <stdlib.h>
#define MSIZE 1000000

int cnt[26];
char a[MSIZE+1];

int main(void) {
  freopen("friktories.in", "r", stdin);
  freopen("friktories.out", "w", stdout);
  unsigned char c;
  int i, j, vis=0, m;
  cnt[25] = -1;
  
  while(gets(a)) {
    for (i=0; a[i]!='\0'; i++) {
      c = a[i];
      if ( c >= 128 && c <= 151 ) cnt[c-128]++;
      else if ( c == 32 ) cnt[24]++;
    }
  }
  
  for (i=0; i<25; i++) {
    m = 25;
    for (j=0; j<25; j++) {
     if ( ( vis|(1<<j) ) != vis && cnt[j] > cnt[m] ) m = j;
    }
    vis |= (1<<m);
    printf("%c %d\n", (m==24?' ':m+128), cnt[m]);
  }
  
  return 0;
}

