/* Από το μαθητή Καγιά Άρη */
          
#include <stdio.h>
#include <stdlib.h>
long int d;
FILE *fp;
void sinart(void);
long int c[9000000][2], f[9000000][2], fpos = 0, heap;


int main(void)
{
  fp = fopen("seaview.in", "r");
  fscanf(fp, "%ld", &d);
  sinart();
  return 0;
}


void sinart(void)
{
  long int i, j, num;
  short int found = 0;
  for(i=0; i<d; i++) fscanf(fp, "%ld%ld", &c[i][0], &c[i][1]);
  fclose(fp);
  fp = fopen("seaview.out", "w");
  for(i=0; i<d; i++)
  {
    found = 0;
    for(j=0; j<d; j++) 
      if(c[i][0]<c[j][0] && c[i][1]<c[j][1]) {
        found++;
        break;
      }
    if (!found)
    {
      f[fpos][0] = c[i][0];
      f[fpos++][1] = c[i][1];
    }
  }
  for(i=0; i<fpos; i++) 
    for(j=i+1; j<fpos; j++) 
      if(f[i][0]>f[j][0]) {
        num = f[i][0];
        f[i][0] = f[j][0];
        f[j][0] = num;
        num = f[i][1];
        f[i][1] = f[j][1];
        f[j][1] = num;
      }
  for(i=0; i<fpos; i++) fprintf(fp, "%ld %ld\n", f[i][0], f[i][1]);
  fclose(fp);
}

