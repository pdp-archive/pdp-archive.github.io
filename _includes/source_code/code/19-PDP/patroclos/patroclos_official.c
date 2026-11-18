/* Ενδεικτική λύση από τον Γιώργο Μπιτζέ */

#include <stdio.h>
#include <stdlib.h>

int S, N, stones[1100];

typedef struct states states;
struct states
{
  int pt; //possible total
  int stones[1300];
  int stoneCount;
};

states V[10100];


int compare(const void * a, const void * b) {
  return (stones[*(int*)b] - stones[*(int*)a]);
}


int main(void) {
  int i, w, k;
  FILE *in = fopen("patroclos.in", "r");
  FILE *out = fopen("patroclos.out", "w");

  fscanf(in, "%d %d", &S, &N); 

  for(i = 1; i <= N; i++)
    fscanf(in, "%d", &stones[i]); 

  fclose(in); 

  for(i = 1; i <= N; i++)
    for(w = S; w >= stones[i]; w--)
      if(w >= stones[i] && V[w-stones[i]].pt + stones[i] > V[w].pt)
      {
        V[w].stoneCount = V[w-stones[i]].stoneCount;
        V[w].pt = V[w-stones[i]].pt; 

        for(k = 1; k <= V[w].stoneCount; k++)
          V[w].stones[k] = V[w-stones[i]].stones[k];

        V[w].pt += stones[i]; 

        V[w].stoneCount++;
        V[w].stones[V[w].stoneCount] = i;
      } 

  qsort(V[S].stones+1, V[S].stoneCount, sizeof(int), compare);

  fprintf(out, "%d\n", V[S].stoneCount);
  for(i = 1; i <= V[S].stoneCount; i++)
    fprintf(out, "%d\n", V[S].stones[i]); 

  fclose(out);

  return 0;
}

