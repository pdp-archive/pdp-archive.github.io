#include <cstdio>
#include <cstdlib>
#include <list>
#define MAXN 1000100
#define mk(a, b) make_pair(a, b)
#define F first
#define S second
using namespace std;
int A[MAXN];
int main(){
list< pair<int, int> > minim, maxim;
int n, m, c;
FILE *fi = fopen("sound.in", "r");
fscanf(fi, "%d%d%d", &n, &m, &c);
for (int i = 0; i!=n; i++) fscanf(fi, "%d", &A[i]);
m--;
for (int i = 0; i<m; i++){
while(!minim.empty() && A[i]<=minim.front().F) minim.pop_front();
minim.push_front(mk(A[i], i));
while(!maxim.empty() && A[i]>=maxim.front().F) maxim.pop_front();
maxim.push_front(mk(A[i], i));
}
m++;
bool found = false;
FILE *fo = fopen("sound.out", "w");
for (int i = m-1; i<n; i++){
// Bgazoume auta pou exei perasei h epirroh tous
if (minim.back().S < i-m+1 && !minim.empty())
minim.pop_back();
if (maxim.back().S < i-m+1 && !maxim.empty())
maxim.pop_back();
// Update monotony
while(!minim.empty() && A[i]<=minim.front().F) minim.pop_front();
minim.push_front(mk(A[i], i));
while(!maxim.empty() && A[i]>=maxim.front().F) maxim.pop_front();
maxim.push_front(mk(A[i], i));
if (maxim.back().F - minim.back().F<=c) {
found = true;
fprintf(fo, "%d\n", i - m+2); // +2 gt einai bash 1
}
}
if (!found) fprintf(fo, "NULL\n");
return 0;
}