#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("sumoffew.in", "r", stdin);
    freopen("sumoffew.out", "w", stdout);

    long n, k;
    scanf("%ld%ld", &n, &k);

    vector<long> x(n);
    for (long i = 0; i < n; i++)
        scanf("%ld", &x[i]);

    map<long, long> freq;
    long sol = 0;

    for (long i = 0; i < n; i++) {
        freq.clear();
        long sum = 0, c = 0;
        for (long j = i; j < n && c <= k; j++) {
            sum += x[j];
            c += !(freq[x[j]]++);
            // Η παραπάνω γραμμή είναι συντομογραφία του παρακάτω κώδικα:
            /*
            if (freq[x[j]] == 0)
                c++;
            freq[x[j]]++;
            */
            if (c <= k && sum > sol)
                sol = sum;
        }
    }

    printf("%ld\n", sol);
    return 0;
}
