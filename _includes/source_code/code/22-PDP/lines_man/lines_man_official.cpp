/*
USER: 22pdp19
LANG: C++
TASK: lines_man
*/
#include <fstream>
#include <vector>
// #include <math.h>

using namespace std;

int abs (int n) {
   return (n >= 0?n:n * -1);
}

int main() {
   ifstream in("lines_man.in");
   ofstream out("lines_man.out");
   int A; //court size
   in >> A;
   int M; //phases
   in >> M;

   // vector <int> width;

   int firstdude = 0, seconddude = 0;
   int firstdudepos = A / 2, seconddudepos = A / 2;
   for (int i = 0; i < M; i++) {
      int x;
      in >> x;
      if (x <= firstdudepos || x >= firstdudepos && x <= A/2) {
         firstdude += abs(firstdudepos - x);
         firstdudepos = x;
      }
      else {
         firstdude += abs (firstdudepos - A/2);
         firstdudepos = A/2;
      }
      if (x >= seconddudepos || x <= seconddudepos && x >= A/2) {
         seconddude += abs(seconddudepos - x);
         seconddudepos = x;
      }
      else {
         seconddude += abs (seconddudepos - A/2);
         seconddudepos = A/2;
      }
   }
   out << firstdude << " " << seconddude << endl;
   return 0;
}
