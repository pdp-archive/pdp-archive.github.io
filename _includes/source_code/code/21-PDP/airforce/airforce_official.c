/* Τσάτσιου Γεωργία (2ο Γυμνάσιο Καλαμπάκας) */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  FILE *eis;
  FILE *ex;
  int pos,i,j,thesh1,thesh2;
  double t,m;
  int syn[1000][3];

  t=0;
  pos=0;
  m=9999;
  if((eis = fopen("airforce.in", "r")) == NULL) exit(1);
  fscanf(eis,"%d",&pos);
  for(i=0;i<pos;i++) fscanf(eis," %d %d %d",&syn[i][0],&syn[i][1],&syn[i][2]);
  fclose(eis);
  if((ex = fopen("airforce.out", "w")) == NULL) exit(1);
  for(i=0;i<pos;i++){
    for(j=i+1;j<pos;j++){
      t=sqrt(pow((syn[i][0]-syn[j][0]),2)+
             pow((syn[i][1]-syn[j][1]),2)+
             pow((syn[i][2]-syn[j][2]),2));
      if(t<m){thesh1=i;thesh2=j;m=t;}
    }
  }
  thesh1++;
  thesh2++;
  fprintf(ex,"%d %d\n",thesh1,thesh2);
  fclose(ex);
  return(0);
}

