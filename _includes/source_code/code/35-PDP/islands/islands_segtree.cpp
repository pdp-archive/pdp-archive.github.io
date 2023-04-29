#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 5e5+5;

int n, q, arr[MAXN], seg[4*MAXN], lazy[4*MAXN]; //sum segment tree with range updates

void build(int i = 1, int j = n-1, int id = 1){ //build the segment tree in O(N)
    lazy[id] = -1; //denotes that I don't have any lazy update to push on that node
    if(i == j){
        seg[id] = arr[i]; //= 0
        return;
    }
    int mid = i + (j-i)/2;
    build(i, mid, 2*id);
    build(mid+1, j, 2*id+1);
    seg[id] = seg[2*id] + seg[2*id+1];
}

void push(int i, int j, int id){ //push the update of node id with lazy propagation
    if(lazy[id] == -1) return;
    int mid = i + (j-i)/2;
    lazy[2*id] = lazy[id];
    lazy[2*id+1] = lazy[id];
    seg[2*id] = lazy[id]*(mid-i+1);
    seg[2*id+1] = lazy[id]*(j-mid);
    lazy[id] = -1;
}

void update(int a, int b, int v, int i = 1, int j = n-1, int id = 1){ //make arr[i] = v for all a <= i <= b
    if(i > b || j < a) return;
    if(i >= a && j <= b){
        lazy[id] = v;
        seg[id] = v*(j-i+1);
        return;
    }
    push(i, j, id);
    int mid = i + (j-i)/2;
    update(a, b, v, i, mid, 2*id);
    update(a, b, v, mid+1, j, 2*id+1);
    seg[id] = seg[2*id] + seg[2*id+1];
}

int sum_query(int a, int b, int i = 1, int j = n-1, int id = 1){ //find Sum(a, b) = arr[a] + arr[a+1] + ... + arr[b]
    if(i > b || j < a) return 0;
    if(i >= a && j <= b) return seg[id];
    push(i, j, id);
    int mid = i + (j-i)/2;
    return sum_query(a, b, i, mid, 2*id) + sum_query(a, b, mid+1, j, 2*id+1);
}

int query(int k, int i = 1, int j = n-1, int id = 1){ //find rightmost i with Sum(1, i-1) <= k
    if(i == n-1 && seg[id] <= k) return n;
    if(i == j) return i;
    int mid = i + (j-i)/2;
    push(i, j, id);
    if(seg[2*id] > k) return query(k, i, mid, 2*id);
    else return query(k-seg[2*id], mid+1, j, 2*id+1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("islands.in", "r", stdin);
    freopen("islands.out", "w", stdout);
    scanf("%d %d", &n, &q);
    for(int i = 1; i < n; i++){ //1-indexed, [1...n-1]
        arr[i] = 0; //initially all routes work
    }
    build();
    for(int i = 0; i < q; i++){
        char option[3];
        scanf("%s", option);
        if(option[0] == 'D'){
            int a, b;
            scanf("%d %d", &a, &b);
            update(a, b-1, 1);
        }
        else if(option[0] == 'B'){
            int a, b;
            scanf("%d %d", &a, &b);
            update(a, b-1, 0);
        }
        else if(option[0] == 'Q'){
            int a, k;
            scanf("%d %d", &a, &k);
            int left = sum_query(1, a-1); //left = tickets needed from start to a
            int ans = query(k + left); //find where you can go from start with k+left tickets
            printf("%d\n", ans);
        }
    }
}
