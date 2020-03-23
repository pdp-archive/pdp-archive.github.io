/* Θεοδώρα Παναγέα */

#include<stdio.h>

int main(){
  int arx[40002],tel[40002];
  int i,j=1,l,n,k=1;
  FILE *fpin;
  FILE *fpout;
  fpin = fopen("snow_run.in","r");
  fpout = fopen("snow_run.out","w");
     
  for(i<=0;i<=40000;i++){
    arx[i]=0;
    tel[i]=0; 
  }
     
  fscanf(fpin,"%d",&n);
     
  for(i=1;i<=n;i++){ 
    fscanf(fpin,"%d",&l);
    arx[i]=l;
     
    for (j=1;j<i;j++){
      if (l<=tel[j])
        tel[j]++;
    } 
    tel[i]=l;
  }
     
  for(i=1;i<=n;i++)
    fprintf(fpout,"%d\n",tel[i]);
  return 0; 
}
