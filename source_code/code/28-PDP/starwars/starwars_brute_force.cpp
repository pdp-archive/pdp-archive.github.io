#include <cstdio>
#include <vector>
#include <iostream>

const size_t MAXD = 100;

bool a[MAXD][MAXD][MAXD];

int X, Y, Z;

void init() {
   for (int i = 0; i < X; ++i) {
      for (int j = 0; j < Y; ++j) {
         for (int k = 0; k < Z; ++k) {
            a[i][j][k] = 0;
         }
      }
   }
}

void update_x(int l, int r) {
   for (int i = l; i <= r; ++i) {
      for (int j = 0; j < Y; ++j) {
         for (int k = 0; k < Z; ++k) {
            a[i][j][k] = !a[i][j][k];
         }
      }
   }
}

void update_y(int l, int r) {
   for (int i = l; i <= r; ++i) {
      for (int j = 0; j < X; ++j) {
         for (int k = 0; k < Z; ++k) {
            a[j][i][k] = !a[j][i][k];
         }
      }
   }
}

void update_z(int l, int r) {
   for (int i = l; i <= r; ++i) {
      for (int j = 0; j < X; ++j) {
         for (int k = 0; k < Y; ++k) {
            a[j][k][i] = !a[j][k][i];
         }
      }
   }
}

int sum(int x1, int y1, int z1, int x2, int y2, int z2) {
   int sm = 0;
   for (int i = x1; i <= x2; ++i) {
      for (int j = y1; j <= y2; ++j) {
         for (int k = z1; k <= z2; ++k) {
            sm += a[i][j][k];
         }
      }
   }
   return sm;
}

int main() {
   freopen("starwars.in", "r", stdin);
   freopen("starwars.out", "w", stdout);
   int T;
   scanf("%d", &T);
   while(T--) {
      int M;
      scanf("%d %d %d %d", &X, &Y, &Z, &M);
      init();
      while (M--) {
         int type;
         scanf("%d", &type);
         if (type == 0) {
            int A, B;
            scanf("%d %d", &A, &B);
            update_x(A, B);
         } else if (type == 1) {
            int A, B;
            scanf("%d %d", &A, &B);
            update_y(A, B);
         } else if (type == 2) {
            int A, B;
            scanf("%d %d", &A, &B);
            update_z(A, B);
         } else if (type == 3) {
            int x1, x2, y1, y2, z1, z2;
            scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
            printf("%d\n", sum(x1, y1, z1, x2, y2, z2));
         }
      }
   }
   return 0;
}
