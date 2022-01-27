#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAXN 200
#define SIZE(X) ((int)(X.size()))
#define LENGTH(X) ((int)(X.length()))

class IngredientProportions
{
public:
  int A[MAXN],B[MAXN],P[MAXN],Q[MAXN];
  vector <double> getMasses(vector <string> vs)
  {
    int n=SIZE(vs)+1;
    for (int i=0;i<n-1;i++)
    {
      string str=vs[i];
      istringstream sin(str);
      string s0;
      sin>>A[i]>>B[i]>>P[i]>>Q[i];
    }
    for (int i=0;i<n-1;i++)
    {
      A[n-1+i]=B[i];
      B[n-1+i]=A[i];
      P[n-1+i]=Q[i];
      Q[n-1+i]=P[i];
    }
    vector<double> R(n,-1);
    R[0]=1;
    while (1)
    {
      bool ok=true;
      	for (int i=0;i<n;i++) if (R[i]>=0) {
        	for (int k=0;k<2*(n-1);k++) {
        		if (A[k]==i && R[B[k]]<0) {
            		ok=false;
            		R[B[k]] = R[i]*Q[k]/P[k];
          		}
			}
		}
      if (ok) break;
    }
    double sum=0;
    for (int i=0;i<n;i++) sum += R[i];
    for (int i=0;i<n;i++) R[i] = R[i] * 100 / sum;
    return R;
  }
};

int main() {
	int i,N;
   freopen("cocktails.in", "r", stdin);
   freopen("cocktails.out", "w", stdout);
	vector <string> vs;
	char str[100];
	scanf("%d\n",&N);
	for(i=0;i<N-1;i++) {
		gets(str);
		string s(str);
		vs.push_back(s);
	}
	IngredientProportions x;
	vector<double> vd = x.getMasses(vs);
	for(i=0;i<N;i++) printf("%.2lf\n",vd[i]);
	return 0;
}

