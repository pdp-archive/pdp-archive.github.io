#include<stdio.h>
#include<stdlib.h>

int main() {
   FILE *fd;
   fd = fopen("xxx.in","r");
   freopen("xxx.out","w",stdout);
   int N,*Kyl;
   fscanf(fd,"%d",&N);
   Kyl = (int *)malloc(N*sizeof(int));
   int i=0;
   while (i<N) {
     fscanf(fd, "%d", &Kyl[i]);
     i=i+1;
   }
   int p=1;
   int max=Kyl[N-1];
   i=N-2;
   while (i>=0) {
      if (Kyl[i]>max) {
         max=Kyl[i];
         p=p+1;
      }
      i=i-1;
   }
   printf("%d\n", p);
   return 0;
}