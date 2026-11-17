/* Αρσένης Γεράσιμος 2ο ΓΕΛ Μοσχάτου */

#include <stdio.h>
#include <stdlib.h>
#define MAX 70000

int comp(const void *i, const void *j) {
  return *(long *)i-*(long *)j;
}


int main() {
  FILE *fin=fopen("blocks.in", "r"), *fout=fopen("blocks.out", "w");
  long blocks[MAX], n, i, j;
  fscanf(fin, "%ld", &n);
  fclose(fin);
  for (i=2, j=0; i*i<=n; i++)
    if (n%i==0) { 
      blocks[j]=i; 
      j++; 
      if (i!=n/i) { 
        blocks[j]=n/i;
        j++; 
      } 
    }
  blocks[j]=1; j++;
  qsort(blocks, j, sizeof(long), comp);
  fprintf(fout, "%ld\n", j);
  for (i=0; i<j; i++)
    fprintf(fout, "%ld\n", blocks[i]);
  fclose(fout);
  return 0;
}

