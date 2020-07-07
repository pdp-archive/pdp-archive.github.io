#include <bits/stdc++.h>

using namespace std;

// Fun fact: Από τη C++14 και μετά επιτρέπεται να χρησιμοποιούμε το
// χαρακτήρα ' για το διαχωρισμό των ψηφίων ενός αριθμού για
// ευκολότερη ανάγνωση!
const long MAX = 1'000'000;
long freq[MAX+1] = {0};

int main() {
    freopen("sumoffew.in", "r", stdin);
    freopen("sumoffew.out", "w", stdout);

    long n, k;
    scanf("%ld%ld", &n, &k);

    vector<long> x(n);
    for (long i = 0; i < n; i++)
        scanf("%ld", &x[i]);

    long sol = 0;

    for (long i = 0; i < n; i++)
        for (long j = i; j < n; j++) {
            long c = 0, sum = 0;
            for (long l = i; l <= j; l++) {
                sum += x[l];
                if (freq[x[l]] == 0)
                    c++;
                freq[x[l]]++;
            }
            if (c <= k && sum > sol)
                sol = sum;

            // Clear frequency array
            for (long l = i; l <= j; l++)
                freq[x[l]] = 0;
        }

    printf("%ld\n", sol);
    return 0;
}
