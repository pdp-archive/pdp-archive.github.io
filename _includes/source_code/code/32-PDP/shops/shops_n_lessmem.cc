#include <cstdio>
#include <algorithm>

const long MAXN = 2000000;
using namespace std;

long N, K, ans, Ai, s[MAXN+5], maxUpTo;

int main() {
  freopen("shops.in","r",stdin);
  freopen("shops.out","w",stdout);
  scanf("%ld %ld", &N, &K);
  for(long i=1; i<=N; ++i) {
    scanf("%ld", &Ai);
    s[i] = s[i-1] + Ai;
  }
  for(long i=K;i<=N-K;++i){
      //Δοκιμάζουμε κάθε πιθανή θέση που θα ξεκινά το δεύτερο (δεξιότερο)
      //κατάστημα. Προφανώς δεν έχει νόημα να ξεκινά πρίν τη θέση Κ διότι
      //θα επικάλυπτε το πρώτο (αριστερό) κατάστημα. Καταλαμβάνει τις 
      //θέσεις i+1,i+2,...,i+K άρα μπορεί να ξεκινά το πολύ στη θέση N-K
      //ώστε να τελειώνει στη θέση Ν
      
      maxUpTo = max(maxUpTo, s[i] - s[i-K]);
      //το maxUpTo διατηρεί το καλύτερο κέρδος για το πρώτο κατάστημα
      //όπου και αν αυτό έχει μπεί, αρκεί να τελειώνει το πολύ στη θέση i
      
      ans = max(ans, maxUpTo + s[i+K] - s[i]);
      //το s[i+K]-s[i] είναι το κέρδος του δεύτερου καταστήματος αν αυτό
      //ξεκινά στη θέση i+1 και τελειώνει στην i+K
  }

  printf("%ld\n", ans);
  return 0;
}
