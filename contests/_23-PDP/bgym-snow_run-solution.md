---
layout: solution
codename: snow_run
---

## 1� ���� �� Brute force

������ �������� ��� ��������� ��� ���� ����������� �� ������ ��� ��������� �� ������������ ��� ������ ��� ��������.

�������� �� ������� ���� �� �������� ��������������� �� ���������� �����������. ������������ � ������ �������� ���� ������ �� ��������� ������ ��� �� ����� ��� ������� ��� ��������� ��� ��� �������� ����� �� ��������� ������ ������ ��� ���� ��������� ���� ��������� � ��� �������� ��� ���� �� ��������� ���� $$1$$ ��� ������ ��������� ��� ������.

��� �� �� ������� ���� �������� �� ���������������� ��� ����������� for loops, ���� �� ���������� $$i$$ ��� $$j$$. ������ �� ����������� ���� ������, ���� $$A$$, ���� ����� �� ���������� ��� ������ �������� ��� ���� ������ �� ���� �� ����� ������� ��������. ������ ��� ���� ������ $$i$$ � ������ ��� �������� �� �������������� ���� �������� ��� �� ������ ��� ��������� ��� �� ��������� ���� $$1$$ � �������� ���� ������������ ������ ($$j < i$$) ��� ����� ���� ��������� ��� ���� ��� ���� � ��������� ������ �������� ($$A[j] \geq A[i]$$).

���� ��� ��� ������������ for loops ��� ���������� ��� ������ $$A$$, � ������� ������������� ����� ��� ���������� �� ����� $$O(N^2)$$. � ������������� ���� ����� ������� ��� �� ������ testcases ($$N \leq 40.000$$), ���� �� ��������� �� ���������� �� ������� ���� ��� �� ��� ������� (������ $$N \leq 100.000$$). � ������ ������������� ����� $$O(N)$$ ����� ������ �� ������������� ��� ����������� ������� ����������� (������� $$A$$).

```c++
#include <cstdio>
using namespace std;

#define MAXN 100005

long A[MAXN];

int main() {
    freopen("snow_run.in", "r", stdin);
    freopen("snow_run.out", "w", stdout);
    long N;
    scanf("%ld", &N);
    for (long i = 0; i < N; i++) {
        scanf("%ld", &A[i]);
        // ������ ������� ��������� ������������ ������� ��� ���������� ��������
        for (long j = 0; j < i; j++) {
            if (A[j] >= A[i])
                A[j]++;
        }
    }
    // �������� ������� ����������
    for (long i = 0; i < N; i++) {
        printf("%ld\n", A[i]);
    }
    return(0);
}
```

## 2� ���� �� Brute force

���� � ���� ��� �� ����� ���� ���� ��� ���� ������������� �� ��� �����������, ������ ������������ ��� ���� ����������� ���������� ��� �� ��� �������� �� �������������� ��� �������� �� �������� ����. ���� ������ ��� ��� ����������� ���������, � ������ �������� ���� ������ ��������� ���� ��� ��� ���������� ��� ������� ���� ��� ����� ��� ��� ��� �������� ��� �� ������ ��� ���������. �������� �� ������� ��� ���������� ��� ��������� ��� ��� ����� ��� �������� �� �������� ��� ���������� ���� ����������� ���������.

**����������**: ��������� �������� �� ������������� ���� ��������� ��� ��� ������ ������� (����� �� ��������� ��� ������ ���� ��������) �� ����� �������� ������� ���������, ����� � �������� ����������� ��� ������ �� ����� ��� �� ��� ������ (���� �� �� �������� �������������). ���� �� � ������ ������� �� ������ ����������� ��� ���� �������� ��� �� $$a$$, ���� ���� ��� ���� ��� $$a$$-����� ����� ��� ������� ��������� ��� ��������� ��� ���� ��������� ������� ���� ������ ��� ������� ������� ������ �� ��������������� ��� ��� ����.

�������� ������ �� ������ ���� boolean ������, ���� $$B$$, �������������� �� $$\mathit{false}$$. ����� ����������� ���� ������� ��� �� ����� ���� ��� ���� �� ������������ ��� ������ ���� ��������. �� � $$i$$-����� ������� ���� �������� ��� �� $$a$$ �� ������ ����������� ���, ���� �� �������� �������� �� $$a$$-���� $$\mathit{false}$$ ��� ������ $$B$$. �� ���� ��������� ��� ���� $$b$$ ���� ���� �� ����� � ������ �������� ��� $$i$$-����� ������, ����� �� ������� �� $$B[b]$$ ��� �� $$\mathit{true}$$ ��� �� $$A[i]$$ ��� �� $$b$$. ������ � ������� $$A$$ �� �������� �� ������������.

������ ��� ���� ������ ������� �������� �������� ��� ������ $$B$$, � ������� ������������� �� ����� $$O(N^2)$$. � ������ ������������� ����� ��� ���� $$O(N)$$. �� ��� ����� � ���������� ���� ��� ���� ������� ������������� �� ��� �����������, �������� ����� �� ���������� ����������� ������� ����� ��� ������� ������� �� �� ���������� �� ����������� ���� ��� ������ $$B$$. ������ ��� ���� ��� ���������� testcases ���� � ���� ���������� �� ������� ����.

```c++
#include <cstdio>
using namespace std;

#define MAXN 100005

long A[MAXN];
bool B[MAXN];

int main() {
    freopen("snow_run.in", "r", stdin);
    freopen("snow_run.out", "w", stdout);
    long N;
    scanf("%ld", &N);
    // �������� ���������� �� ������ ����������� ���� ������
    for (long i = 0; i < N; i++) {
        scanf("%ld", &A[i]);
    }
    for (long i = N - 1; i >= 0; i--) {
        long a = A[i];
        long b = 0;
        // ������ a-����� ����� ��� ���� b
        while (a) {
            if (!B[++b])
                a--;
        }
        // �� b ����� � ������ �������� ��� ��������� ������
        B[b] = true;
        A[i] = b;
    }
    // �������� ������� ����������
    for (long i = 0; i < N; i++) {
        printf("%ld\n", A[i]);
    }
    return(0);
}
```


## �������� ���� �� Segment tree

���� �� �������� ������ �� ����� ��� ������� ��� ������������ �� ���������� ������� ��� $$a$$-����� ����� ���� ������ ����������. ���� ������ �� �� ������� ���� ����� �� �� ������� ���� ����� ��������� ��� ���������� [segment tree](https://en.wikipedia.org/wiki/Segment_tree). ���� ���� ����������� ��� �� segment trees �� ������, ������������ ������ ��� ���������� ����� ��� ����� ��� ���������� ��� �������� �� ������ [���](https://kallinikos.github.io/Segment-Trees).

�������� �� ���������� ���� ������ $$C$$ ��� �� ���� $$1$$ ���� ������ ��� ������������ �� �� ������������� ������ ��� ��������� ��� $$0$$ ���� �������������. �� ����������� ��� ���������� segment tree ���� ���� ������ $$C$$ �������� �� �� �������������� ��� �� ��������� �� ��������� ���� (query) ��� �� ������� �������� ���� (update). ������ ������� update ���� ������� ��� ���������� ��� �� query �������� �� ����������� ����� ��� ��� �����������.

� ������ ��� �� ����������� �� $$k$$-���� ���� ��� ������ ���������, ������ ��� $$k$$-���� $$1$$ ��� ������ $$C$$, ����� �� ����������� ������ ���� ������ ��� ������� �������� ��� ������� �� ����������� ��� $$k$$-���� $$1$$ ��� ����������� ��� ������ $$C$$ ��� ����������� ��� ��������� ���, ������ �� ��� �� ������. ���� ������ ����������� �� ���� ����� ��� ������� �� ����������� ��� $$k$$-���� $$1$$ ��� ����������� ��� ������ $$C$$ ��� ����������� ��� ��������� ��� ����������� ��� ���� ��� ��������� ������� ��� ������ ���, ���� $$c$$, �� �� $$k$$ ��� ������� �� ����:
* �� $$c \geq k$$, ���� �� $$1$$ ��� �������� ����� �� $$k$$-���� $$1$$ ��� ����������� ��� ����������� ��� ��������� ��� ��������� ��� �������.
* �� $$c < k$$, ���� �� $$1$$ ��� �������� ����� �� $$(k - c)$$-���� $$1$$ ��� ����������� ��� ����������� ��� ��������� ��� ������ ��� �������.

�� ������ ��� ���� ������� ����������� ������ �� ���������� ������ ����� ���� $$1$$ ����� ���������� ��� ���� ��� ��������� ����.

������ ��� ���� ������ � ����������� ��� ������� ��� ��������� �� �� segment tree ������� �� ����� $$O(logN)$$ � ������� ������������� ����� ��� ���������� ����� $$O(NlogN)$$. � ������ ������������� ����� $$O(N)$$. ����� � ���������� ����� ������� ��� �� testcases.

```c++
#include <cstdio>
using namespace std;

#define MAXN 100005

long A[MAXN];
// �������� ��� segment tree
long C[MAXN], tree[4 * MAXN];

void build(long node, long start, long end) {
    if(start == end)
        tree[node] = C[start];
    else {
        long mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

// ������������ ���������� 1 ��� ��������� segment tree
long query(long node, long start, long end, long k) {
    tree[node]--;
    if(start == end) {
        C[start] = 0;
        return(start);
    }
    long mid = (start + end) / 2;
    long c = tree[2 * node];
    // ������� ���������� ����������
    if (c >= k)
        return(query(2 * node, start, mid, k));
    return(query(2 * node + 1, mid + 1, end, k - c));
}

int main() {
    freopen("snow_run.in", "r", stdin);
    freopen("snow_run.out", "w", stdout);
    long N;
    scanf("%ld", &N);
    // �������� ���������� �� ������ ����������� ���� ������
    // ��� ������������ ������ C
    for (long i = 1; i <= N; i++) {
        scanf("%ld", &A[i]);
        C[i] = 1;
    }
    // ��������� segment tree
    build(1, 1, N);
    // ����������� ������� ���������� �� ��������� 1
    for (long i = N; i; i--) {
        A[i] = query(1, 1, N, A[i]);
    }
    // �������� ������� ����������
    for (long i = 1; i <= N; i++) {
        printf("%ld\n", A[i]);
    }
    return(0);
}
```