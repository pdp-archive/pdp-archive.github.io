#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("sumoffew.in", "r", stdin);
    freopen("sumoffew.out", "w", stdout);

    long n, k;
    scanf("%d%d", &n, &k);

    vector<long> x(n);
    for (long i = 0; i < n; i++)
        scanf("%d", &x[i]);

    unordered_map<long, long> freq;
    long c = 0, sum = 0, sol = 0;

    long i = 0, j = 0;
    while (j < n) {
        sum += x[j];
        c += !(freq[x[j++]]++);
        while (c > k) {
            sum -= x[i];
            c -= !(--freq[x[i++]]);
        }
        sol = max(sol, sum);
    }

    printf("%d\n", sol);
    return 0;
}
