#include <stdio.h>
#include <stdlib.h>

int checkprime (int num) {
   int counter = 2;
   while (1) {
      if (!(num % counter)) return 0; //Brethike dieretis, ara o arithmos den einai prwtos.
      if ((num/counter) < counter) return counter; //De brethike dieretis, ara o arithmos einai prwtos.
      counter ++;
   }
}

int main(){
   FILE *fp;
   int n, m, arithmos, mikros, megalos;
   int test=0;
   fp=fopen("function.in","r");
   fscanf(fp, "%d %d", &n, &m);
   fclose(fp);
   if(n>m) { //Thetei ton megalitero kai ton mikrotero arithmo apo autous pou mas dinei.
      mikros=m;
      megalos=n;
   } else {
      mikros=n;
      megalos=m;
   }

   fp=fopen("function.out","w+");
   for(arithmos=mikros+1; arithmos<megalos; arithmos++){
      if (checkprime (arithmos)){
         fprintf(fp,"%d", arithmos);
         test = 1;
         break; 
      }
   }
   for(arithmos=arithmos+1; arithmos<megalos; arithmos++){
      if (checkprime (arithmos)){
         fprintf(fp," %d", arithmos);
      }
   }
   if(test == 1){
      fprintf(fp,"\n");
   }
   fclose(fp);
}