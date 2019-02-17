#include <stdio.h>
int N,a[1000009],r[1000009],l[1000009],cmin=1000009,cmax=-
1,num=-1;
int main () {
freopen("solar.in","r",stdin);
freopen("solar.out","w",stdout);
scanf("%d",&N);
for (int i=1;i<=N;i++) {
scanf("%d",&a[i]);
l[i]=a[i]>cmax?1:0;
cmax=a[i]>cmax?a[i]:cmax;
} for (
int i=N;i>=1;i--) {
r[i]=cmin>a[i]?1:0;
num=(l[i]==1&&r[i]==1&&num<a[i])?a[i]:num;
cmin=cmin>a[i]?a[i]:cmin;
}
num==-1?printf("NOT FOUND\n"):printf("%d\n",num);
return 0;
}
