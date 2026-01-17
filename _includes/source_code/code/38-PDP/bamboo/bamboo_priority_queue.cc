#include <cstdio>
#include <queue>

using namespace std;

long N;
priority_queue<long> lengths;

int main() {
  // Διαβάζουμε τα μήκη των μπαμπού
  scanf("%ld", &N);
  long len;
  for (long i = 0; i < N; i++) {
    scanf("%ld", &len);
    lengths.push(len);
  }

  long current = 0;
  long days = 0;
  while (!lengths.empty()) {
    long top = lengths.top();
    lengths.pop();
    if (top != current) {
      days++;
      current = top;
    }
  }

  printf("%ld\n", days);
}
