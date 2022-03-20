#include <algorithm>
#include <cstdio>

int main() {
   FILE *fi = fopen("lines_man.in", "r");
   long A, M;
   fscanf(fi, "%ld%ld", &A, &M);
   long x1 = A/2, total_x1 = 0, total = 0, prev_ball_pos = A/2;
   for (long i = 0; i < M; ++i) {
      long cur_ball_pos;
      fscanf(fi, "%ld", &cur_ball_pos);
      
      long new_x1 = std::min(cur_ball_pos, A/2);
      total_x1 += std::abs(new_x1 - x1);
      x1 = new_x1;
      
      total += std::abs(cur_ball_pos - prev_ball_pos);
      prev_ball_pos = cur_ball_pos;
   }
   fclose(fi);
   
   FILE *fo = fopen("lines_man.out", "w");
   fprintf(fo, "%ld %ld\n", total_x1, total - total_x1);
   fclose(fo);
   
   return 0;
}
