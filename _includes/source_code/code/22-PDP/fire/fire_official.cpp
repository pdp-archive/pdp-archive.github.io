#include <stdio.h>
#include <stdlib.h>

char a[1000][1000];
int b[1000000][2];
int i,j,N,M,st,gr;
int  C,T,ex;
FILE * fin;
FILE * fout;

int main(){
   int qgr,qst;
   fin = fopen("fire.in" , "r");
   fout = fopen("fire.out" , "w");
   fscanf(fin,"%d %d %d %d",&N,&M,&st,&gr);
   for(i=0;i<=M;i++)
   {
      fscanf(fin,"%s",a[i]);
   }
   fclose(fin);
   gr=gr-1;
   st=st-1;
   b[0][0]=gr;
   b[0][1]=st;
   ex=0;
   T=1;
 
   while(ex<T)
   {
      qgr=b[ex][0];
      qst=b[ex][1];   
      a[qgr][qst]='K';
      if(qgr-1>=0){if(a[qgr-1][qst]=='.'){ b[T][0]=qgr-1; b[T][1]=qst; a[qgr-1][qst]='K'; T++;}}             
      if(qgr+1<=M+1){if(a[qgr+1][qst]=='.'){ b[T][0]=qgr+1; b[T][1]=qst; a[qgr+1][qst]='K'; T++;}}
      if(qst+1<=N+1){if(a[qgr][qst+1]=='.'){ b[T][0]=qgr; b[T][1]=qst+1; a[qgr][qst+1]='K'; T++;}}
      if(qst-1>=0){if(a[qgr][qst-1]=='.'){ b[T][0]=qgr; b[T][1]=qst-1; a[qgr][qst-1]='K'; T++; }}
      ex++;           
   }
   fprintf(fout,"%d\n" , ex);
   fclose(fout);
   return 0;   
}
