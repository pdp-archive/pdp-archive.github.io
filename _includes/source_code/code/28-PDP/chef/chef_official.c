#include <stdio.h>
#define MAXN 100000

int A[MAXN+1];

int feasible(int k, int N, int D)
{
    int i, day=0; 
    
    for (i=1; i<=N+D; i++) {
        if (i <= N) day+=A[i];
        if ((long long) day > (long long) k*(D+1)) return 0; 
        if ((long long) day > (long long) k*(N+D-i+1)) return 0; 
        if (day<=k) day=0;
        else day-=k; 
    }
    if (!day) return 1;
} 

int main()
{
#ifdef CONTEST  
    freopen("chef.in", "rt", stdin);  
    freopen("chef.out", "wt", stdout);  
#endif 

    int N, M, D, low, up, mid, x, i;
    scanf("%d %d %d", &N, &D, &M);
    for (i=1; i<=N; i++) A[i]=0;
    for (i=0; i<M; i++) {
        scanf("%d", &x); A[x]++;
    }
    low=1; up=M;
    while (low<up) {
        mid=(low+up)/2;
        if (feasible(mid, N, D)) up=mid;
        else low=mid+1;
    }
    
    printf("%d\n", low);
    return 0;
}


