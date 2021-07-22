#include <algorithm>
#include <cstdio>

int main() {
   FILE *fi = fopen("lines_man.in", "r");
   long A, M;
   fscanf(fi, "%ld%ld", &A, &M);
   long x1 = A/2, x2 = A/2, total_x1 = 0, total_x2 = 0;
   for (long i = 0; i < M; ++i) {
      long cur_ball_pos;
      fscanf(fi, "%ld", &cur_ball_pos);
      
      long new_x1 = std::min(cur_ball_pos, A/2);
      total_x1 += std::abs(new_x1 - x1);
      x1 = new_x1;
      
      long new_x2 = std::max(cur_ball_pos, A/2);
      total_x2 += std::abs(new_x2 - x2);
      x2 = new_x2;
   }
   fclose(fi);
   
   FILE *fo = fopen("lines_man.out", "w");
   fprintf(fo, "%ld %ld\n", total_x1, total_x2);
   fclose(fo);
   
   return 0;
}
