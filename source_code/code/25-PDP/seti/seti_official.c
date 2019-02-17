#include <stdio.h>

int main(void){
   int pinakas[10005],index,count,apotelesma,num,kr;
   unsigned char table[10005];
   FILE * in = fopen("seti.in", "r");
   FILE * out = fopen ("seti.out", "w");
   fscanf(in,"%d\n%d %d",&num,&pinakas[1],&pinakas[2]);
   apotelesma=0;
   table[1]=table[2]=0;
   if(num % 2) pinakas[0]=987;
      num=(num/2)*2;
      //############################################
      for(index=3;index < num;index++){
         table[index]=table[index+1]=0;
         fscanf(in," %d %d",&pinakas[index],&pinakas[index+1]);
         for(count=1,kr=index/2+1;count < index;count+=2,kr++)
            if(pinakas[count] == pinakas[index]
                  && pinakas[kr] > pinakas[count] * 2
                  && table[kr] != 255){
               table[kr]=255;
               apotelesma++;
            }
        //-----------------------------------------------
            for(index++,count=2,kr=(index+3)/2;count < index;count+=2,kr++)
               if(pinakas[count] == pinakas[index]
                     && pinakas[kr] > pinakas[count] * 2
                     && table[kr] != 255){
                  table[kr]=255;
                  apotelesma++;
               }
            }
            //###########################################
            if(pinakas[0] == 987){
               num++;
               fscanf(in," %d",&pinakas[num]);
               table[num]=0;
               for(count=1,kr=num/2+1;count < num;count+=2,kr++)
                  if(pinakas[count] == pinakas[num]
                        && pinakas[kr] > pinakas[count] * 2
                        && table[kr] != 255){
                     table[kr]=255;
                     apotelesma++;
                  }
               }
            //------------------------------------------
            fprintf(out,"%d\n",apotelesma);
            if(apotelesma > 0)
               for(count=1;count < num;count++)
                  if(table[count] == 255)
                     fprintf(out,"%d\n",count);
    fclose(in); fclose(out);
    return 0;
}