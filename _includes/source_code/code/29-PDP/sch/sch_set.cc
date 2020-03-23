#include <algorithm>
#include <cstdio>
#include <set>

typedef std::pair<long, int> Candidate;

const int MAXS = 10000;
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
   
  std::set<Candidate, std::greater<Candidate>> candidates;
  for (int v = 1; v <= MAXS; ++v) {
    candidates.insert(std::make_pair(count[v], v));
  }
  fclose(fi);
  
  FILE *fo = fopen("sch.out", "w");  
  fprintf(fo, "%d %d %d\n", 
    candidates.begin()->second, 
	std::next(candidates.begin())->second,
    std::next(std::next(candidates.begin()))->second);
  fclose(fo);
  return 0;
}
