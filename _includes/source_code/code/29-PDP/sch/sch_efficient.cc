#include <algorithm>
#include <cstdio>

const int MAXS = 10000;
const std::pair<long, int> invalid_pair(0, -1);
long count[MAXS + 1];

int main() {
  FILE *fi = fopen("sch.in", "r");
  long N;
  fscanf(fi, "%ld", &N);
  
  for (long i = 0; i < N; ++i) {
    int value;
    fscanf(fi, "%d", &value); 
	++count[value];
  }
  
  // Τα μεγαλύτερα τρία συν ένα στοιχείο που αγνοούμε.
  std::pair<long /* count */, int /* value */> largest_three[] = { 
    invalid_pair, invalid_pair, invalid_pair, invalid_pair
  }; 
  for (int v = 1; v <= MAXS; ++v) {
    std::pair<long, int> current = std::make_pair(count[v], v);
	int position_found = 3;
	for (int j = 0; j < 3; ++j) {
	  if (largest_three[j].first < current.first) {
	    position_found = j;
		break;
	  }
	}
	// Μετακινούμε όλα τα στοιχεία μία θέση κάτω.
	for (int j = 2; j > position_found; --j) {
	  largest_three[j] = largest_three[j - 1];
	}
	
	// Βάζουμε το τωρινό.
	largest_three[position_found] = current;
  }
  fclose(fi);
  
  FILE *fo = fopen("sch.out", "w");  
  fprintf(fo, "%d %d %d\n", largest_three[0].second, largest_three[1].second, largest_three[2].second);
  fclose(fo);
  return 0;
}
