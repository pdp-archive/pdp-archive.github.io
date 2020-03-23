/* NAME: KONSTADINOS AGIANIS
* TASK: OPERATORS
* LANG: C
*/
#include <stdio.h>
#include <stdlib.h>

unsigned long int n,n1,n_base,n_try,up_timh_n_try,up_timh_n_base,*pinakas;

int main(void) {
   //--------------------------------------------
   FILE * in = fopen ("operators.in", "r");
   FILE * out = fopen ("operators.out", "w");
   fscanf (in , "%ld", &n);
   //--------------------------------------
   pinakas = (unsigned long int *) malloc(n * sizeof(unsigned long int));
   long int up_timh1,up_timh;
   n--;
   n1=0;
   //--------------------------------------
   fscanf(in,"%ld",&pinakas[0]);
   n1++;
read: //for (n1++;n1<=n;n1++)
   fscanf(in," %ld",&pinakas[n1]); //{
   n1++; //fscanf(in," %ld",&pinakas[n1]);
   if(n1<=n) //}

   goto read;
   //---------------------------------------

   n_try=n;
   n_base=0;
   //--------------------------------------------
   up_timh=2147483647;
   //---------------------------------------------------------------
   //----------------------------------------------------------------
   //------------------------------------------------------------
loop:
   n1=up_timh1=pinakas[n_base] + pinakas[n_try];

   if(up_timh1 < 0) n1=up_timh1*= -1;
   if(up_timh1 < up_timh) {
      up_timh=up_timh1;
      up_timh_n_try=n_try;
      up_timh_n_base=n_base;
   }

main_loop: //------------------------------------------

   n_try--;
   if (n_base == n_try)
   goto print;
   up_timh1=pinakas[n_base] + pinakas[n_try];
   if(up_timh1 < 0)
   up_timh1*= -1;

   //----------------------------------------------

   if (up_timh1 < n1) {
      if(up_timh1 < up_timh) {
         up_timh=up_timh1;
         up_timh_n_try=n_try;
         up_timh_n_base=n_base;
      }
      n1 = up_timh1;
      goto main_loop;
   }

next_base: //------------------------------------

   n_base++;
   n_try++;
   if (up_timh == 0) goto print;
   goto loop;

   //--------------------------------------------------------
   //--------------------------------------------------------
   //--------------------------------------------------------
print:
   fprintf(out,"%ld %ld\n",pinakas[up_timh_n_base],pinakas[up_timh_n_try]);

   //---------------------------------------

end:
     fclose(in); fclose(out);
   return 0;
}

// dim131: Η malloc καλούνταν με λάθος παραμέτρους και έτσι η λύση
// δεν περνούσε τα μεγάλα testcases.
