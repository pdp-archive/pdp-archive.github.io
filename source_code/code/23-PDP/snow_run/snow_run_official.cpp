/* Κωνσταντίνος Ξανθόπουλος */

#include <iostream>
#include <fstream>
using namespace std;
#define nmax 100000

int main () { 
  ifstream fin;
  ofstream fout;
  long int ord[nmax];
  long int n, i, a1,a2;
  fin.open( "snow_run.in",ios::in); 
  fin >> n;
  fin>>ord[0];
  for (a1=1;a1<n;a1++){
    fin>>ord[a1];
    if (ord[a1]< a1+1){
      for (a2=0;a2<a1;a2++){
        if (ord[a2]>=ord[a1]) {
          ord[a2]=ord[a2]+1;
        }
      }
    }
  }
  fout.open("snow_run.out",ios::out); 
  for (i=0;i<n;i++) {
    fout<< ord[i] <<endl;
  } 
  fin.close();
  fout.close();
  
  return 0;
}
