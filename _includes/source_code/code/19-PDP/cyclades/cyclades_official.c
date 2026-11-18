/* Ενδεικτική λύση από τον Γιώργο Μπιτζέ */

#include <stdio.h>

int matrix[1100][1100], N;


void readFile(void)
{
  int M, i, a, b, k; 
  
  FILE *in = fopen("cyclades.in", "r");
  fscanf(in, "%d %d", &N, &M);
  //we do not yet know which nodes connect,
  //so set the weights between all to infinity for now
  //so, when we get the input matrix[i][j] will contain the distance 
  //between i and j if they connect and 999999999 if they don't.
  for(i = 1; i <= N; i++)
    for(a = 1; a <= N; a++)
      matrix[i][a] = 999999999; 
      
  for(i = 1; i <= M; i++)
  {
    fscanf(in, "%d %d %d", &a, &b, &k);
    matrix[a][b] = k;
    matrix[b][a] = k;
  }
  fclose(in);
}


void output(unsigned long long val)
{
  FILE *out = fopen("cyclades.out", "w");
     
  if(val == 0)
    fprintf(out, "%d\n", -1);
  else
    fprintf(out, "%llu\n", val*4);
  fclose(out);
}


void prim(void)
{
  unsigned long long distance[1100], treeCost = 0, minD;
  int inTree[1100], treeSize = 1, i, n; 
  
  //set node1 to be in MST
  for(i = 1; i <= N; i++)
  {
    distance[i] = matrix[1][i];
    inTree[i] = 0;
  } 
  
  inTree[1] = 1; 
  
  while(treeSize < N)
  {
    minD = 999999999, n = -1;
    for(i = 1; i <= N; i++)
      if(distance[i] < minD && inTree[i] == 0)
      {
        minD = distance[i];
        n = i;
      }
      
    if(minD == 999999999 || n == -1)
    { //there is no possible set of vertices 
      //that connect all nodes...
      output(0);
      return;
    } 
    
    treeSize++;
    treeCost += distance[n];
    inTree[n] = 1; 
    
    for(i = 1; i <= N; i++)
      if(distance[i] > matrix[n][i])
        distance[i] = matrix[n][i];
  } 
  
  output(treeCost);
}


int main(void)
{
  readFile();
  prim(); 
  return 0;
}

