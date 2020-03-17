#include <bits/stdc++.h>

using namespace std;

const long MAXN = long(1e6);
const long OFFSET = long(1e5);

struct hotel {
	long x,y,visibility;
	hotel(long x,long y): x(x), y(y) { visibility = 0; }
	hotel(){ x = y = visibility = 0; }
} hotel[MAXN+1];

struct coord {
	long x,y,hotel_id;
	coord(long x,long y,long hotel_id):x(x),y(y),hotel_id(hotel_id){}
	coord(){ x = y = hotel_id = 0; }
} C[MAXN+1];

long N, ans;

int main() {
#ifdef CONTEST
	freopen("loutraki.in","r",stdin);
	freopen("loutraki.out","w",stdout);
#endif
	scanf("%ld", &N);
	for(long i=1; i<=N; ++i){
		scanf("%ld%ld",&hotel[i].x,&hotel[i].y);
		hotel[i].x += OFFSET;
		hotel[i].y += OFFSET;
		C[i] = coord( hotel[i].x, hotel[i].y, i );
	}

	sort(C+1,C+N+1,[](const auto& a,const auto& b){return (a.x==b.x)?(a.y<b.y):(a.x<b.x);});
	for(long i=1;i<=N;){
		long co = C[i].x;
		hotel[C[i].hotel_id].visibility++;
		while(i<=N && C[i].x == co)
			i++;
	}

	sort(C+1,C+N+1,[](const auto& a,const auto& b){return (a.y==b.y)?(a.x<b.x):(a.y<b.y);});
	for(long i=1;i<=N;){
		long co = C[i].y;
		//hotel[C[i].hotel_id].visibility++;
		if(++hotel[C[i].hotel_id].visibility == 2) 
			ans++;
		while(i<=N && C[i].y == co)
			i++;
	}

	printf("%ld\n", ans);
	return 0;
}
