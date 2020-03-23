#include <cstdio>

const size_t MAXN = 500000;

long A[MAXN + 1];
long rank[MAXN + 1];
long seg_tree[4*(MAXN + 1)];

long N;

void init(long n, long b, long e) {
   if (b == e) {
      seg_tree[n] = 1;
	  return;
   }
   long mid = (b + e) / 2;
   init(2 * n, b, mid);
   init(2 * n + 1, mid + 1, e);
   seg_tree[n] = seg_tree[2*n] + seg_tree[2*n + 1];
}

long find_first_position_where_sum_equals(long rem) {
   long n = 1, b = 1, e = N;
   while (b != e) {
	  long mid = (b + e)/2;
      if (seg_tree[2*n] >= rem) {
	     n = 2 * n;
		 e = mid;
	  } else {
		 rem -= seg_tree[2*n];
	     n = 2 * n + 1;
		 b = mid + 1;
	  }
   }
   return b;
}

void minus_one_at(long idx) {
   long n = 1, b = 1, e = N;
   while (b != e) {
	  long mid = (b + e)/2;
      --seg_tree[n];
	  if (idx <= mid) {
	     n = 2 * n;
		 e = mid;
	  } else {
	     n = 2 * n + 1;
		 b = mid + 1;
	  }
   }
   --seg_tree[n];
}



int main() {
   FILE *fi = fopen("rafting.in", "r");
   fscanf(fi, "%ld", &N);
   for (long i = 0; i < N; ++i) {
      fscanf(fi, "%ld", &A[i]);
   }
   fclose(fi);
   
   init(1, 1, N);
   
   for (long i = N - 1; i >= 0; --i) {
	  long final_rank = find_first_position_where_sum_equals(A[i]);
      rank[final_rank] = i + 1;
	  minus_one_at(final_rank);
   }
   
   FILE *fo = fopen("rafting.out", "w");
   for (long i = 1; i <= N; ++i) {
      fprintf(fo, "%ld", rank[i]);
	  if (i < N) fprintf(fo, " ");
   }
   fprintf(fo, "\n");
   fclose(fo);
   return 0;
}