#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 5;

struct Point;

int N;
vector<Point> points(MAXN);
vector<Point> hull;

struct Point
{
  ll x, y;
  int index;

  bool operator<(const Point &other)
  {
    return x < other.x || (!(other.x < x) && y < other.y);
  }
};

// Υπολογίζει την συντεταγμένη z του εξωτερικού γινομένου (b-a) x (c-a).
// Θετικό σημαίνει ότι το c είναι αριστερά του διανύσματος ab.
ll ccw(Point a, Point b, Point c)
{
  return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

// Κλάση για το σορτάρισμα των σημείων ώς προς το αρχικό σημείο startPoint.
struct AngleSorter
{
  Point startPoint;
  AngleSorter(Point startPoint) : startPoint(startPoint) {}

  bool operator()(Point a, Point b)
  {
    return ccw(startPoint, a, b) > 0;
  }
};

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

  // Βρίσκουμε το πιο αριστερό (και το πιο κάτω σημείο), το οποίο είναι πάντα
  // μέρος της λύσης.
  int startPoint = 0;
  for (int i = 0; i < points.size(); ++i)
  {
    if (points[i] < points[startPoint])
      startPoint = i;
  }

  // Μετακινούμε το startPoint στην αρχή της λίστας για να μην το σορτάρουμε
  // μαζί με τα υπόλοιπα.
  Point tmp = points[0];
  points[0] = points[startPoint];
  points[startPoint] = tmp;

  // Σορτάρουμε ως προς τη γωνία με το αρχικό σημείο.
  sort(points.begin() + 1, points.end(), AngleSorter(points[0]));

  // Αφαιρούμε σημεία από τη στοίβα hull έως ότου το καινούργιο σημείο να
  // δημιουργεί αριστερή στροφή.
  for (int i = 0; i < points.size(); ++i)
  {
    while (hull.size() > 1 && ccw(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0)
      hull.pop_back();
    hull.push_back(points[i]);
  }

  fprintf(fout, "%ld\n", hull.size());

  // Ταξινομούμε τα σημεία ως προς τη θεση τους στο αρχείο εισόδου.
  sort(hull.begin(), hull.end(),
       [](const Point &a, const Point &b)
       { return a.index < b.index; });
  for (const auto &p : hull)
  {
    fprintf(fout, "%d\n", p.index);
  }
  fclose(fout);
}
