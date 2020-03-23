/* Ευστάθιος Μποζίκας */

#include <iostream>
#include <stdio.h>

int main(int argc, char** argv){
  int n,x,min,a=0;
  double tp=1.000,p;
  FILE *read = fopen("profit.in","r");
  fscanf(read,"%d",&n);
  fscanf(read,"%d",&x);
  min = x;
  while(a<=(n-1)){
    fscanf(read," %d",&x);
    if(x>min){p=(double)x/min;if(p>tp){tp=p;}}
    else{min=x;}
    if (tp==1000.000){break;}
    a++;
  }
  fclose(read);
  FILE *write = fopen("profit.out","w");
  fprintf(write,"%.3f\n",tp);
  fclose(write);
  return 0;
}
