#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 5;

struct Point;

int N;
vector<Point> points(MAXN);
vector<bool> inHull(MAXN);

struct Point
{
  ll x, y;

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

int main()
{
  FILE *fin = fopen("pulsars.in", "r");
  FILE *fout = fopen("pulsars.out", "w");
  fscanf(fin, "%d", &N);

  // Διαβάζουμε τα δεδομένα εισόδου και βρίσκουμε το πιο αριστερό (και το πιο
  // κάτω σημείο), το οποίο είναι πάντα μέρος της λύσης.
  int startPoint = 0;
  for (int i = 0; i < N; ++i)
  {
    inHull[i] = false;
    fscanf(fin, "%lld %lld", &points[i].x, &points[i].y);
    if (points[i] < points[startPoint])
    {
      startPoint = i;
    }
  }
  fclose(fin);
  points.resize(N);

  // Ξεκινάμε από το αρχικό (ελάχιστο) σημείο.
  inHull[startPoint] = true;
  int currentPoint = startPoint;
  int totalHullPoints = 1;

  // Επαναλαμβάνουμε μέχρι να ξαναβρούμε το αρχικό (ελάχιστο) σημείο.
  while (true)
  {
    // Ελέγχουμε πάντα το startPoint εκτός από την πρώτη επανάληψη για να
    // ξέρουμε πότε να σταματήσουμε (όταν το startPoint ειναι το nextPoint στο
    // τέλος της επανάληψης).
    int nextPoint = startPoint;
    if (currentPoint == startPoint)
      nextPoint = -1;
    // Περνάμε όλα τα σημεία για να βρουμε πιο είναι το πιο δεξια ως προς το
    // currentPoint.
    for (int i = 0; i < N; ++i)
    {
      // Προσπερνάμε όλα τα σημεία που είναι ήδη στο πολύγωνο.
      if (inHull[i])
        continue;

      // Αναθέτουμε μια τιμή σε περίπτωση που δεν το κάναμε πριν.
      if (nextPoint == -1)
      {
        nextPoint = i;
        continue;
      }

      // Ελέγχουμε αν το σημείο i είναι πιο δεξιά από το nextPoint
      // και αν ειναι, ανανεώνουμε την τιμή του.
      if (ccw(points[currentPoint], points[nextPoint], points[i]) < 0)
        nextPoint = i;
    }

    // Σταματάμε αν γυρίσαμε στην αρχή.
    if (nextPoint == startPoint)
    {
      break;
    }

    // Βρήκαμε κι άλλο σημείο της λύσης, οπότε συνεχίζουμε.
    currentPoint = nextPoint;
    inHull[currentPoint] = true;
    totalHullPoints++;
  }

  fprintf(fout, "%d\n", totalHullPoints);
  for (int i = 0; i < N; ++i)
  {
    if (inHull[i])
    {
      fprintf(fout, "%d\n", i + 1);
    }
  }
  fclose(fout);
}
