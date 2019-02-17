#include <stdio.h>
#include <stdlib.h>
# include <math.h>
int main(int argc, char *argv[])
{
int N,K,a,a1,r,r1;
FILE* fin;
FILE* fout;
fin=fopen("ensemble.in","r");
fout=fopen("ensemble.out","w");
fscanf(fin,"%d",&N);
fscanf(fin,"%d",&K);
float v[N],v1[N],min[K+1],max[K+1],s,t;
s=0;
for (a=0;a<N;a++)
{
fscanf(fin,"%f", & v[a]);
s=s+v[a];
v1[a]=v[a];
}
for (a1=0;a1<K+1;a1++)
{
max[a1]=0.0;
min[a1]=10.0;
for (a=0;a<N;a++)
{
if (v[a]<=min[a1])
{
min[a1]=v[a];
r=a;
}
if (v1[a]>=max[a1])
{
max[a1]=v1[a];
r1=a;
}
}
v[r]=10.0;
v1[r1]=0.0;
}
for (a1=0;a1<K;a1++)
{
s=s-min[a1];
s=s-max[a1];
}
t=s;
t=t+(K*max[K]);
t=t+(K*min[K]);
s=round((s/(N-(K*2)))*100)/100;
t=round((t/N)*100)/100;
fprintf(fout,"%2.2f ",s);
fprintf(fout,"%2.2f\n",t);
fclose(fin);
fclose(fout);
return 0;
}
