/* Γαϊτανίδης Απόστολος (Ιδ. ΓΕΛ «Μαντουλίδη») */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define inf 0x3f3f3f3f
#define MAXN 210

typedef struct{
  int x,y;
}point;

double dist(point a,point b){
  return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double min(double a,double b){
  if(a<b)return a;
  else return b;
} 

int cmp(const void *a, const void *b){
  point *c = (point *)a,*d = (point *)b;
  if(c->x >d->x)return 1;
  else return -1;
} 

int n;
point p[MAXN];
double a[MAXN][MAXN];

int main(){
  FILE *fin = fopen("evripos.in","r"),*fout = fopen("evripos.out","w");
  fscanf(fin,"%d",&n);
  p[1].x = p[1].y = 0;
  n+=2;
  for(int i=2;i<=n;i++){
    fscanf(fin,"%d %d",&p[i].x,&p[i].y);
  }
  qsort(p+1, n, sizeof(point), cmp);
  a[1][2] = dist(p[1], p[2]);
  for(int j=2;j<=n;j++){
    for(int i =1;i<=j-1;i++){
      if(i==1 && j==2)a[i][j] = dist(p[i],p[j]);
      else if(j>i+1)a[i][j] = a[i][j-1] + dist(p[j-1],p[j]);
      else {
        a[i][j] = a[1][i] + dist(p[1],p[j]);
        for(int k=1;k<=i-1;k++){
          double q= a[k][i] + dist(p[k],p[j]);
          if(q<a[i][j]){
            a[i][j] = q;
          }
        }
      }
    }
  }
 
  double m = a[n-1][n] + dist(p[n-1],p[n]);
  for (int i=1; i<n; i++) { m = min(m, a[i][n] + dist(p[i],p[n])); }
  fprintf(fout,"%d\n",(int)round(m));
  return 0;
}

