#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 5;

struct Point
{
  ll x, y;
  int index;

  // Ορίζουμε τον τελεστή < ώστε να μπορούμε να το χρησιμοποιήσουμε με τo struct
  // π.χ. pointA < pointB. Πρώτα συγκρίνουμε τις τετμημένες (x) και μετά τις
  // τεταγμένες (y). Επίσης, ο τελεστής αυτό με τη συνάρτηση sort, αν δεν
  // παρέχουμε custom συνάρτηση ταξινόμησης.
  bool operator<(const Point &other)
  {
    return x < other.x || (!(other.x < x) && y < other.y);
  }
};

int N;
vector<Point> points(MAXN);
vector<Point> upperHull, lowerHull;

// Υπολογίζει την συντεταγμένη z του εξωτερικού γινομένου (b-a) x (c-a).
// Θετικό σημαίνει ότι το c είναι αριστερά του διανύσματος ab.
ll ccw(Point a, Point b, Point c)
{
  return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

// Κατασκευάζει το άνω ή το κάτω μισο της λύσης στο hull. Το `lower` καθορίζει
// αν θα είναι το άνω ή το κάτω μισό.
void makeHull(vector<Point> &hull, bool lower = true)
{
  // Το `multiplier` το χρησιμοποιούμε για να αποφύγουμε να γράφουμε δύο φορές
  // τον ίδιο κώδικα για <= και >=. Το >= χρησιμοποιείται για το άνω μισό και το
  // <= για το κάτω. Επομένως, πολλαπλασιάζοντας την αριστερή μεριά της
  // ανισότητας με -1, αλλάζουμε την φορά της σύγκρισης. Βάζουμε `multiplier` +1
  // για το κάτω μισό και -1 για το άνω.
  int multiplier = lower ? 1 : -1;
  for (int i = 0; i < points.size(); ++i)
  {
    while (hull.size() > 1 && multiplier * ccw(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0)
      hull.pop_back();
    hull.push_back(points[i]);
  }
}

int main()
{
  FILE *fin = fopen("pulsars.in", "r");
  FILE *fout = fopen("pulsars.out", "w");
  fscanf(fin, "%d", &N);
  for (int i = 0; i < N; ++i)
  {
    points[i].index = i + 1;
    fscanf(fin, "%lld %lld", &points[i].x, &points[i].y);
  }
  fclose(fin);
  points.resize(N);

  // Ταξινομούμε με βάση το x (και το y σε περίπτωση ισότητας).
  sort(points.begin(), points.end());

  makeHull(upperHull, false);
  makeHull(lowerHull, true);

  // Μπορούμε να ενώσουμε τα δύο μισά αφαιρώντας τα ακριανά σημεία ενός από τα
  // δύο μισά, αντιστρέφοντας την σειρά των σημείων του και προσθέτοντας το στο
  // άλλο μισό. Στη συγκεκριμένη περίπτωση δεν μας ενδιαφέρει η σειρά των
  // σημείων στο πολύγονο, καθώς στο τέλος θα τα ταξινομήσουμε με βάση τη σειρά
  // τους στο αρχείο εισόδου.
  for (int i = lowerHull.size() - 2; i >= 1; --i)
  {
    upperHull.push_back(lowerHull[i]);
  }

  fprintf(fout, "%ld\n", upperHull.size());

  // Ταξινομούμε τα σημεία ως προς τη θεση τους στο αρχείο εισόδου.
  sort(upperHull.begin(), upperHull.end(),
       [](const Point &a, const Point &b)
       { return a.index < b.index; });
  for (const auto &p : upperHull)
  {
    fprintf(fout, "%d\n", p.index);
  }
  fclose(fout);
}
