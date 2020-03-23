#include <stdio.h>
int *p1,*f1,*m;
char *c1;

void go(int i)
{
  if(p1[i])
  {
    if(f1[p1[i]-1]==-1)go(p1[i]-1);
    f1[i]=f1[p1[i]-1]+1;
    m[i]=m[p1[i]-1];
    if(c1[p1[i]-1]=='m')
    {
      m[i]++;
      f1[i]--;
    }
  }
  else
  {
    f1[i]=0;
    m[i]=0;
  }
}

int main()
{
  int N,i,r=0;
  FILE *f;
  f=fopen("company.in","r");
  fscanf(f,"%d",&N);
  int ma[N],fa[N],p[N];
  f1=fa;
  m=ma;
  p1=p;
  char c[N],t[3];
  c1=c;
  for(i=0;i<N;i++)
  {
    ma[i]=-1;
    fa[i]=-1;
    fscanf(f,"%d",p+i);
    fscanf(f,"%s",t);
    c[i]=t[0]; 
  }
  fclose(f);
  for(i=0;i<N;i++)
  {
    if(fa[i]==-1) go(i);
    if(c[i]=='m')
    {
      r-=fa[i];
    }
    else
    {
      r+=ma[i];
    }
  }
  f=fopen("company.out","w");
  fprintf(f,"%d\n",r); 
  return 0;
}
