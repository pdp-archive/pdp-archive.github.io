#include <cmath>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

bool prime (int a) {
   int count;
   bool is_it=true;
   if (a % 2 ==0)
      is_it=false;
   else {
      for (count=2; count<=sqrt(a); count++) {
         count++;
         if (a % count == 0)
            is_it=false;
      }
   }
   return (is_it);
}

int main() {
   int prim;
   bool pr;
   int st;
   int en;
   bool t;
   ifstream in ("function.in");
   ofstream out ("function.out");
   in >> st >> en;
   if (st > en) {
      prim=st;
      st=en;
      en=prim;
   }
   t=false;
   for (prim=st+1; prim<en; prim++) {
      if (prime(prim)) {
         if (t)
            out << " " << prim ;
         else
            out << prim;
         t=true;
      }
   }
   if(t)
      out << endl;
   in.close(); out.close();
   return 0;
}
