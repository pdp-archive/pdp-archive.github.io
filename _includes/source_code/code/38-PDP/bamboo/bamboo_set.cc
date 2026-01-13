#include <cstdio>
#include <unordered_set>

#define MAXN 200005

using namespace std;

int n;
unordered_set<int> unique_lengths;

int main() {

  // Διαβάζουμε τα μήκη των μπαμπού και τα αποθηκεύουμε στο unordered_set
  scanf("%d", &n);
  int len;
  for (int i = 0; i < n; i++) {
    scanf("%d", &len);
    unique_lengths.insert(len);
  }

  printf("%ld\n", unique_lengths.size());
}
