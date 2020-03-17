#include <cstdio>
#include <vector>
#include <iostream>

struct SegTree {
   
   std::vector<bool> state;

   std::vector<bool> switch_node;

   std::vector<long> node_sum;

   size_t N;
   
   SegTree(size_t n) {
      N = n;
      state.resize(4 * N + 1, false);
      switch_node.resize(4 * N + 1, false);
      node_sum.resize(4 * N + 1, 0);
   }
   
   void propagate(size_t n, long b, long e) {
      if (switch_node[n]) {
         switch_node[2*n] = !switch_node[2*n];
         node_sum[2*n] = ( (b+e)/2 - b + 1 ) - node_sum[2 * n];
         switch_node[2*n + 1] = !switch_node[2*n + 1];
         node_sum[2*n + 1] = ( e - (b+e)/2 ) - node_sum[2*n + 1];
         switch_node[n] = false;
      }
   }

   void update(size_t n, long b, long e, long i, long j) {
      if (b > j || e < i) return;
      if (i <= b && e <= j) {
         switch_node[n] = !switch_node[n];
         node_sum[n] = (e - b + 1) - node_sum[n];
         return;
      }
      propagate(n, b, e);
      
      update(2*n, b, (b+e)/2, i, j);
      update(2*n+1, (b+e)/2+1, e, i, j);
      node_sum[n] = node_sum[2*n] + node_sum[2*n+1];
   }
   
   void update(long i, long j) {
      update(1, 0, N-1, i, j);
   }
   
   long sum(size_t n, long b, long e, long i, long j) {
      if (b > j || e < i) return 0;
      if (i <= b && e <= j) {
         return node_sum[n];
      }
      
      propagate(n, b, e);
      
      long sum1 = sum(2*n, b, (b+e)/2, i, j);
      long sum2 = sum(2*n+1, (b+e)/2+1, e, i, j);
      
      return sum1 + sum2;
   }
   
   long sum(long i, long j) {
      return sum(1, 0, N-1, i, j);
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
      SegTree x_ds(X), y_ds(Y), z_ds(Z);
      while (M--) {
         int type;
         scanf("%d", &type);
         if (type == 0) {
            int A, B;
            scanf("%d %d", &A, &B);
            x_ds.update(A, B);
         } else if (type == 1) {
            int A, B;
            scanf("%d %d", &A, &B);
            y_ds.update(A, B);
         } else if (type == 2) {
            int A, B;
            scanf("%d %d", &A, &B);
            z_ds.update(A, B);
         } else if (type == 3) {
            int x1, x2, y1, y2, z1, z2;
            scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
            size_t x = x_ds.sum(x1, x2);
            size_t y = y_ds.sum(y1, y2);
            size_t z = z_ds.sum(z1, z2);
            
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
