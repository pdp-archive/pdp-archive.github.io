#include <stdio.h>
#include <stdlib.h>
#define  MAXN 1000000

int A[MAXN][3];

long max(long a, long b)
{
    if (a > b) return(a);
    else return(b);
}

int main()
{
    int i, N;
    long p0, p10, p11, q;
    freopen("restaurants.in", "r", stdin);
    scanf("%d\n", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &(A[i][0]));
    for (i = 0; i < N; i++)
        scanf("%d", &(A[i][1]));
    A[0][2] = A[N-1][2] = 0L; 
    for (i = 1; i < N-1; i++)
        scanf("%d", &(A[i][2]));
        
    p0 = 0L; p10 = (long) A[0][0]; p11 = (long) A[0][1];
    for (i = 1; i < N; i++) {
        q = p10; 
        p10 = max(p0 + (long) A[i][0], p11 + (long) A[i][1]);
        p11 = max(p0 + (long) A[i][1], p11 + (long) A[i][2]);
        p0  = max(q, p0);
//        printf("i = %d, p0 = %ld, p10 = %ld, p11 = %ld\n", i, p0, p10, p11);  
    }
    freopen("restaurants.out", "w", stdout);
    printf("%ld\n", max(p0, p10)); 
}
