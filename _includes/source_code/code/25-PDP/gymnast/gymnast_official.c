#include <stdio.h>
#include <stdlib.h>

#define MAXN 2002
#define INFTY 0x0FFFFFFF

long A[MAXN], B[MAXN], B2[MAXN], N;
long C[MAXN][MAXN], S[MAXN][MAXN];
unsigned char M[MAXN][MAXN];

void swap(long *a, long *b)
{
    long tmp = *a;
    *a = *b;
    *b = tmp;
}

long partition(long A[], long low, long up)
{
    long x = A[low], i = low - 1, j = up + 1;

    while (1) {
        do ; while (A[++i] < x);
        do ; while (A[--j] > x);
        if (i < j) swap(A+i, A+j);
        else return(j);
    }
}

void quicksort(long A[], long low, long up)
{
    long q, pos;

    if (low >= up) return;
    pos = (up+low)/2;
    swap(A+low,A+pos);
    q = partition(A, low, up);
    quicksort(A, low, q);
    quicksort(A, q+1, up);
}

long binarySearch(long A[], long k)
{
    long low = 0, up = N-1, mid;

    while (low <= up) {
        mid = (low + up)/2;
        if (A[mid] == k) return(mid);
        else if (A[mid] > k) up = mid-1;
             else low = mid+1;
    }
    return(-1);
}

long findk(long A[], long k, long last)
{
    int i;
    for (i = 0; i<=last; i++)
        if (A[i] == k) return(i);
    return(-1);
}

long howManySmaller(long A[], long elem, long k, long first, long last)
{
    int i, res = 0L;
    for (i = first; i<=last; i++)
        if ((A[i] < elem) && (A[i] > k)) res++;
    return(res);
}


long move(long A[], long x, long y)
{
    long key = A[x], i;

    if (x == y) return(0L);
    if (x < y) {
        i = x;
        while (i < y) {
            A[i] = A[i+1]; i++;
        }
        A[i] = key;
    }
    else {
        i = x;
        while (i > y) {
            A[i] = A[i-1]; i--;
        }
        A[i] = key;
    }
    return((x+1)+(y+1));
}

long cost(long A[], long k, long x)
{
    long *D, j, kpos, tmp1, tmp2 = INFTY;

    if (C[k][x+1] != -1) return(C[k][x+1]);
    if ((x <= 0) && (k > N-1)) { C[k][x+1] = 0L; return(C[k][x+1]); }

    if ((D = (long*) malloc(N*sizeof(long))) == NULL) {
        fprintf(stderr, "Out of memory!\n");
        exit(1);
    }
    kpos = findk(A, k, N-1);
    if (kpos <= x) {
        for (j = 0; j <= N-1; j++) D[j] = A[j];
        tmp1 = move(D, kpos, x) + cost(D, k+1, x-1);
        tmp2 = cost(A, k+1, kpos-1);
        for (j = kpos+1; j <= x; j++)
            tmp2 += (j+1)+S[A[j]][k];
    }
    else tmp1 = (x+2) + cost(A, k+1, x);


    free(D);
    if (tmp1 <= tmp2) {
        C[k][x+1] = tmp1; M[k][x+1] = 1;
    }
    else {
        C[k][x+1] = tmp2; M[k][x+1] = 0;
    }
    return(C[k][x+1]);
}

long res = 0L, m = 0L;

void moves(long A[], long k, long x)
{
    long kpos;
    if ((x <= 0) && (k > N-1)) return;

    kpos = findk(A, k, N-1);
    if (kpos <= x) {
        if (M[k][x+1]) {
            kpos = findk(A, k, N-1);
            if (kpos != x) {
                res += move(A, kpos, x); m++;
                printf("%ld %ld\n", kpos+1, x+1);
            }
            moves(A, k+1, x-1);
        }
        else
            moves(A, k+1, kpos-1);
    }
    else {
        if (kpos != x+1) {
            res += move(A, kpos, x+1); m++;
            printf("%ld %ld\n", kpos+1, x+2);
        }
        moves(A, k+1, x);
    }

}

int main()
{
#ifdef CONTEST
  freopen("gymnast.in", "rt", stdin);
  freopen("gymnast.out", "wt", stdout);
#endif

    long i, j;

    scanf("%ld", &N);
    for (i=0; i<N; i++) {
        scanf("%ld", (A+i));
        B[i] = A[i];
    }
    quicksort(B, 0, N-1);
    for (i=0; i<N; i++)
        if ((A[i] = binarySearch(B, A[i])) == -1) {
            fprintf(stderr, "Error in searching!\n");
            exit(1);
        }

    for (i=0; i<N; i++) {
        B2[i] = A[i];
        B[A[i]] = i;
        S[A[i]][0] = howManySmaller(A, A[i], 0, i+1, N-1);
    }

    for (i=0; i<N; i++)
        for (j=1; j<N; j++)
            if (i >= B[j]) S[A[i]][j] = S[A[i]][j-1];
            else S[A[i]][j] = S[A[i]][j-1]-1;

    for (i=0;i<N;i++) {
        for (j=0;j<=N;j++)
            C[i][j] = -1;
    }
    printf("%ld\n", cost(A, 0, N-1));

#if MOVES
    moves(B2, 0, N-1);
    printf("%ld %ld\n", res, m);
    for (i=0;i<N;i++) printf("%ld ", B2[i]); printf("\n");
#endif

    return 0;
}
