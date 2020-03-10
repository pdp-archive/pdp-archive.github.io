#include <iostream>
#include <math.h>
#include <stdio.h>
#include <fstream>

using namespace std;

int main (){
   ifstream in ("twosqr.in");
   ofstream out ("twosqr.out");
   int i, A[31622];
   for (i=0; i<31623; i++){
      A[i]=i*i;
   }
   int T;
   in >>T;
   int N, a;
   int st, end;
   for (i=0; i<T; i++){
      in >> N;
      st=0;
      end=sqrt(N);
      a=0;
      while(st<=end){
         if (A[st]+A[end]==N){
            a++;
            st++; end--;
         }
         else if (A[st]+A[end]>N) end--;
         else st++;
      }
      out << a << endl;
   }
   in.close();
   out.close();
   return 0;
}
