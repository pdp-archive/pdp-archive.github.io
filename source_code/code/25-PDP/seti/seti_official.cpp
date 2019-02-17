#include<iostream>
#include<stdio.h>
#define MAXN 10005

using namespace std;

int A[MAXN],R[MAXN];
int N;

int main() {
   FILE* fin = fopen("seti.in","r");
   FILE* fout = fopen("seti.out","w");
   fscanf(fin,"%d",&N);
   for(int i=1;i<=N;i++){
      fscanf(fin,"%d",&A[i]);
   }
   
   int cnt = 0;
   for(int i=2;i<N;i++){
      for(int j=1; (i-j > 0 && i+j <= N); j++){
         if(A[i-j] == A[i+j] && A[i-j]*2 < A[i]){
            R[cnt++] = i;
            break;
		 }
      }
   }
   
   fprintf(fout,"%d\n",cnt);
   for(int i=0;i<cnt;i++){
      fprintf(fout,"%d\n",R[i]);
   }
   return 0;
}
