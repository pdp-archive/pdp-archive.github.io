#include "stdio.h"
#include "stdlib.h"

short i,i2;

FILE * in_file;
FILE * out_file;

unsigned short in_fn,in_ssn,letternumber=0;


int main()
{
   in_file = fopen ("matrix.in","r");
   out_file = fopen ("matrix.out","w+");

   //
   fscanf(in_file,"%d",&in_fn);
   char stf[in_fn];
   fseek(in_file,1,SEEK_CUR);
   fread (&stf,1,in_fn,in_file);

   fscanf(in_file,"%d",&in_ssn);
   fseek(in_file,1,SEEK_CUR);
   char sts[in_ssn];
   fread (&sts,1,in_ssn,in_file);
   short ltr,ltr2;
   
   
   for(i=0;i<in_ssn;i++)               
   {
      ltr=0;
      if(stf[ltr] == sts[i]) // To Prwto gramma einai sosto...
      {
         ltr++; // 2o Gramma
         for(i2=1;i2<in_fn;i2++)
         {
            ltr2 = ltr;
            if(stf[ltr] == sts[i+i2]) // An to ?? Gramma einai iso me to tou arxikou...
            {
               ltr++; // Epomeno gramma
            }            
            if(ltr==in_fn)
            {
               letternumber=i+1;
               fprintf(out_file,"%d\n",letternumber);
               fclose(in_file);
               fclose(out_file);
               return 0;
            }
            if(ltr2 == ltr) //To LTR den anevike, ara dn vrike gramma
            {               
               break;
            }
         }
      }

   }
   fprintf(out_file,"F\n",letternumber);
   
   fclose(in_file);
   fclose(out_file);
   return 0;
}
