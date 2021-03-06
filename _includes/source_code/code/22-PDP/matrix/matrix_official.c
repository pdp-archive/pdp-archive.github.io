#include <stdio.h>  
 
int TimesFound[257], PosFound[257][1025], N;  
long int M;  
unsigned char str[65540],pat[1025];  
  
//Checks whether character c exists in pat between s and e  
//Should be returning x-st occurance of character c in pat  
int Allign(unsigned char c, int x)  
{  
   long int f=TimesFound[c], t;  
   
   if(f<x) return -1;  
   t=PosFound[c][x-1];  
   return t;  
}  

//Returns 0 if pat is found between str[s] and str[e]  
int Compare(long int s, long int e)  
{  
   long int i,j;  
   j=0;  
   for(i=s;i<e;i++)  
   {  
      if(pat[j++]!=str[i]) return -1;  
   }  
   return 0;  
}
   
int main()  
{  
   FILE *fin, *fout;  
   long int i,j,start,end,allign,found=-1;  
   unsigned char c;  
       
   for(i=0;i<256;i++) TimesFound[i]=0;  
       
   fin = fopen("matrix.in","r");  
   fout = fopen("matrix.out","w");  
   
   fscanf(fin,"%d\n",&N);  
   for(i=0;i<N;i++)  
   {  
      fscanf(fin,"%c",&c);  
      pat[i]=c;  
      PosFound[c][TimesFound[c]]=i;  
      TimesFound[c]++;  
   }  
       
   fscanf(fin,"\n%ld\n",&M);  
   for(i=0;i<M;i++)  
   {  
      fscanf(fin,"%c",&str[i]);  
   }  
   
   start=0;  
   end=N-1;  
   
   while(found==-1)  
   {  
      j=1;  
      allign=-2;  
      while(allign!=-1 && found==-1)  
      {  
         allign=Allign(str[end],j++);  
         //If we've found a match  
         if(allign!=-1) if(Compare(end-allign,end-allign+N)==0)  
         {  
            found=end-allign;  
         }  
      }  
      start+=N;  
      end+=N;  
      if(end>M && found<0) found=-2;  
   }  
   
   if(found<0) fprintf(fout,"F\n");  
   else fprintf(fout,"%ld\n",found+1);  
       
   fclose(fin);  
   fclose(fout);  
   return 0;  
}
