#include <cstdio>
#include <iterator>
#include <list>

int main() {
   long N;
   FILE *fi = fopen("rafting.in", "r");
   std::list<long> people;
   fscanf(fi, "%ld", &N);
   for (long i = 0; i < N; ++i) {
      long rank;
      fscanf(fi, "%ld", &rank);
	  std::list<long>::iterator it = people.begin();
	  std::advance(it, rank - 1);
	  people.insert(it, i + 1);
   }
   fclose(fi);
   
   FILE *fo = fopen("rafting.out", "w");
   
   std::list<long>::iterator it = people.begin();
   for (long i = 0; i < N; ++i, ++it) {
      fprintf(fo, "%ld", *it);
	  if (i < N - 1) fprintf(fo, " ");
   }
   fprintf(fo, "\n");
   fclose(fo);
   return 0;
}
