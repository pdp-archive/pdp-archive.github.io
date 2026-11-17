/* Ευστάθιος Ουρεϊλίδης (2ο ΓΕΛ Πολίχνης) */

#include <stdio.h>

int main(void)
{
  int i=0, j=0, L, C, Last=1;
  char c, s1[65536], s2[65536];

  FILE *fin = fopen("Alexander.in", "r");
  fscanf(fin, "%d %d\n%c", &L, &C, &c);
  fclose(fin);

  s1[0] = 'P'; s2[0] = 'V';

  for (i=1;i<C;i++) {
    if (Last==1) {
      s1[i] = 'V';
      s2[i] = 'P';
      Last = 2;
    } else
    if (Last==2) {
      s1[i] = 'P';
      s2[i] = 'V';
      Last = 1;
    }
    j = i+1;
  }

  s1[j] = '\n'; s2[j] = '\n';
  if (c=='P') Last = 1; if (c=='V') Last = 2;

  FILE *fout = fopen("Alexander.out", "w");
  for (i=1;i<=L;i++) {
    if (Last==1) {
      Last = 2;
      fwrite(s1, 1, C+1, fout);
    } else
    if (Last==2) {
      Last = 1;
      fwrite(s2, 1, C+1, fout);
    }
  }
  fclose(fout);

  return 0;
}

