/* Γαϊτανίδης Απόστολος (Ιδ. ΓΕΛ Εκπ/τηρίων Μαντουλίδη) */

#include <stdio.h>
#include <algorithm>
#include <math.h>

#define di 1000000

using namespace std;
typedef unsigned long long ll;
ll a,b,n,m,vr,fj[30],fg[30];
double f[30],fh[30];
FILE *fin = fopen("hydrologis.in","r"), *fout = fopen("hydrologis.out","w");

int main(){
  f[10] = 3.6288;
  fg[10] = 3628800;
  for(ll i = 11;i<=20;i++){
    f[i] = f[i-1] * i;
    fg[i] = fg[i-1]*i;
    fj[i] = (ll)(round(f[i]));
    fh[i] = (double)fg[i]/(double)1000000;
  }
  fscanf(fin,"%llu %llu %llu %llu %llu",&n,&m,&vr,&a,&b);
  double s = (double)(m*(m+1))/(double)(2);
  double ans = (double)vr + (double)a*fh[n] - (double)b*s;
  fprintf(fout,"%llu\n",(ll)round(ans));
  return 0;
}

