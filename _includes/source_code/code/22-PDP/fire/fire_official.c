#include<stdio.h>
#define ADD(a,b) if(A[a][b]==1){ \
                  A[a][b]=0;\
                  B[EndB].x = a;\
                  B[EndB].y = b;\
                  EndB++;\
               }
               
struct forest {int x, y;} B[1000000];
char T[1001*1000], A[1002][1002];

int main() {
   int N, M, StartB=0, EndB=0, x, y ,i, j, t=0;
   FILE *fin = fopen("fire.in","r");
   FILE *fout = fopen("fire.out","w");
   fscanf(fin,"%d %d %d %d", &M, &N, &y, &x);
   fread(T,sizeof(char),(M+1)*N, fin);
   for(i=1;i<=N;i++) for(t++,j=1;j<=M;j++) A[i][j] = (T[t++]=='.');
   ADD(x,y);
   while(StartB!=EndB){
      x=B[StartB].x;
      y=B[StartB].y;
      ADD(x+1,y);   ADD(x-1,y);
      ADD(x,y+1);   ADD(x,y-1);
      StartB++;
   }
   fprintf(fout,"%d\n", EndB);
   return 0;   
}
