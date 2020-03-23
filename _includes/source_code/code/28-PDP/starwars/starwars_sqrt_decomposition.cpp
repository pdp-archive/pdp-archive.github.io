#include <cstdio>
#include <vector>
#include <iostream>

const size_t BUCKET_SIZE = 1000;

struct SqrtDecomposition {
   
   std::vector<bool> state;

   std::vector<bool> switch_bucket;

   std::vector<size_t> bucket_sum;

   size_t N;
   
   SqrtDecomposition(size_t n) {
     N = n;
     state = std::vector<bool>(N, false);
     switch_bucket = std::vector<bool>(N / BUCKET_SIZE + 1, false);
     bucket_sum = std::vector<size_t>(N / BUCKET_SIZE + 1, 0);
   }

   size_t start(size_t bucket_id) {
      return bucket_id * BUCKET_SIZE;
   }

   size_t end(size_t bucket_id) {
      return std::min(N - 1, (bucket_id + 1) * BUCKET_SIZE - 1);
   }

   size_t bucket_size(size_t bucket_id) {
      return end(bucket_id) - start(bucket_id) + 1;
   }

   size_t bucket(size_t i) {
      return i / BUCKET_SIZE;
   }

   void apply_state(size_t bucket_id) {
      if (!switch_bucket[bucket_id]) return;
      switch_bucket[bucket_id] = false;
      for (size_t i = start(bucket_id); i <= end(bucket_id); ++i) {
         state[i] = !state[i];
      }
   }

   void change_state(size_t bucket_id) {
      switch_bucket[bucket_id] = !switch_bucket[bucket_id];
      bucket_sum[bucket_id] = bucket_size(bucket_id) - bucket_sum[bucket_id];
   }

   void update_bucket(size_t bucket_id, size_t start_idx, size_t len) {
      apply_state(bucket_id);
      size_t end_idx = std::min(start_idx + len, end(bucket_id) + 1);
      for (size_t i = start_idx; i < end_idx; ++i) {
         state[i] = !state[i];
         bucket_sum[bucket_id] += state[i];
         bucket_sum[bucket_id] -= 1 - state[i];
      }
   }

   void update(size_t i, size_t j) {
      size_t bucket_i = bucket(i);
      size_t bucket_j = bucket(j);
      if (bucket_i == bucket_j) {
         update_bucket(bucket_i, i, j - i + 1);
         return;
      }
      
      update_bucket(bucket_i, i, BUCKET_SIZE);
      update_bucket(bucket_j, start(bucket_j), j - start(bucket_j) + 1);
      
      for (size_t bucket_id = bucket_i + 1; bucket_id < bucket_j; ++bucket_id) {
         change_state(bucket_id);
      }
   }

   size_t sum_bucket(size_t i, size_t j) {
      size_t bucket_id = bucket(i);
      apply_state(bucket_id);
      size_t sum = 0;
      size_t end_idx = std::min(i + j, end(bucket_id) + 1);
      for (size_t k = i; k < end_idx; ++k) {
         sum += state[k];
      }
      return sum;
   }

   size_t sum(size_t i, size_t j) {
      size_t bucket_i = bucket(i);
      size_t bucket_j = bucket(j);
      if (bucket_i == bucket_j) {
         return sum_bucket(i, j - i + 1);
      }
      
      size_t sm = 0;
      sm += sum_bucket(i, BUCKET_SIZE);
      sm += sum_bucket(start(bucket_j), j - start(bucket_j) + 1);
      
      for (size_t bucket_id = bucket_i + 1; bucket_id < bucket_j; ++bucket_id) {
         sm += bucket_sum[bucket_id];
      }
      return sm;
   }
};

size_t len(size_t a, size_t b) {
   return b - a + 1;
}

int main() {
   freopen("starwars.in", "r", stdin);
   freopen("starwars.out", "w", stdout);
   int T;
   scanf("%d", &T);
   while(T--) {
      int X, Y, Z, M;
      scanf("%d %d %d %d", &X, &Y, &Z, &M);
      SqrtDecomposition x_sqrt(X), y_sqrt(Y), z_sqrt(Z);
      while (M--) {
         int type;
         scanf("%d", &type);
         if (type == 0) {
            int A, B;
            scanf("%d %d", &A, &B);
            x_sqrt.update(A, B);
         } else if (type == 1) {
            int A, B;
            scanf("%d %d", &A, &B);
            y_sqrt.update(A, B);
         } else if (type == 2) {
            int A, B;
            scanf("%d %d", &A, &B);
            z_sqrt.update(A, B);
         } else if (type == 3) {
            int x1, x2, y1, y2, z1, z2;
            scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
            size_t x = x_sqrt.sum(x1, x2);
            size_t y = y_sqrt.sum(y1, y2);
            size_t z = z_sqrt.sum(z1, z2);
            
            size_t x_only = x * len(y1, y2) * len(z1, z2);
            size_t y_only = y * len(x1, x2) * len(z1, z2);
            size_t z_only = z * len(y1, y2) * len(x1, x2);
            
            size_t x_y = x * y * len(z1, z2);
            size_t y_z = y * z * len(x1, x2);
            size_t x_z = x * z * len(y1, y2);
            
            long long ans = x_only + y_only + z_only - 2 * (x_y + y_z + x_z) + 4 * x * y * z;
            printf("%lld\n", ans);
         }
      }
   }
   return 0;
}
