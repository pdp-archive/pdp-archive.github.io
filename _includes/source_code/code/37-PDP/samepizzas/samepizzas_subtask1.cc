#include <algorithm>
#include <cstdio>
#include <vector>

int main(){
   FILE *in = fopen("samepizzas.in", "r");
   FILE *out= fopen("samepizzas.out", "w");
   long P,N,K;
   fscanf(in, "%ld\n", &P);
	fscanf(in, "%ld %ld\n", &N, &K);
	
   std::vector<long> A(N);
	for(long i = 0; i < N; i++) {
		fscanf(in, "%ld", &A[i]);
	}
    
   if (K == 1) fprintf(out, "%ld\n", std::max(A[0], A[1]));
	else fprintf(out, "%ld\n", std::min(A[0], A[1]));
   fclose(out);
   fclose(in);
   return 0;
}
