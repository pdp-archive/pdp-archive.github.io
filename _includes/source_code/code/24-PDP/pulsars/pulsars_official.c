/* NAME: GEORGIOS SAKAS
 * TASK: PULSARS
 * LANG: C
 */
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  int shmeia, i;
  FILE *fin = fopen("pulsars.in", "r");
  fscanf(fin, "%d", &shmeia);
  int *x, *y;
  x = (int *)calloc(shmeia, sizeof(int));
  y = (int *)calloc(shmeia, sizeof(int));
  for (i = 0; i < shmeia; i++)
    fscanf(fin, "%d %d", &x[i], &y[i]);
  fclose(fin);
  int min = y[0], minth = 0;
  for (i = 1; i < shmeia; i++)
  {
    if (min > y[i])
    {
      min = y[i];
      minth = i;
    }
  }
  int max = y[0], maxth = 0;
  for (i = 1; i < shmeia; i++)
  {
    if (max < y[i])
    {
      max = y[i];
      maxth = i;
    }
  }
  int *kor, shm = minth, count = 0, blocks = 50;
  kor = (int *)calloc(blocks, sizeof(int));
  kor[0] = minth;
  while (shm != maxth)
  {
    shm = maxth;
    for (i = 0; i < shmeia; i++)
    {
      if (i != kor[count] &&
          (x[shm] - x[kor[count]]) * (y[i] - y[kor[count]]) - (y[shm] - y[kor[count]]) * (x[i] - x[kor[count]]) < 0)
        shm = i;
    }
    count++;
    if (count >= blocks)
    {
      blocks += 10;
      kor = (int *)realloc(kor, blocks * sizeof(int));
    }
    kor[count] = shm;
  }
  shm = maxth;
  while (shm != minth)
  {
    shm = minth;
    for (i = 0; i < shmeia; i++)
    {
      if (i != kor[count] &&
          (x[shm] - x[kor[count]]) * (y[i] - y[kor[count]]) - (y[shm] - y[kor[count]]) * (x[i] - x[kor[count]]) < 0)
        shm = i;
    }
    count++;
    if (count >= blocks)
    {
      blocks += 10;
      kor = (int *)realloc(kor, blocks * sizeof(int));
    }
    kor[count] = shm;
  }
  free(x);
  free(y);
  FILE *fout = fopen("pulsars.out", "w");
  fprintf(fout, "%d\n", count);
  for (i = 0; i <= shmeia; i++)
  {
    int j = 0;
    while (i != kor[j] && j < count)
      j++;
    if (i == kor[j])
      fprintf(fout, "%d\n", kor[j] + 1);
  }
  fclose(fout);
  free(kor);
  return (0);
}
