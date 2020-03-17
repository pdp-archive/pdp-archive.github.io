#include <bits/stdc++.h>

using namespace std;

#define MAXN	int(1e6)
#define OFFSET	int(1e5)

struct hotel {
	int x,y,visibility;
	hotel(int x,int y): x(x), y(y) { visibility = 0; }
	hotel(){ x = y = visibility = 0; }
} hotel[MAXN+1];

struct coord {
	int x,y,hotel_id;
	coord(int x,int y,int hotel_id):x(x),y(y),hotel_id(hotel_id){}
	coord(){ x = y = hotel_id = 0; }
} C[2*OFFSET+1];

int N, ans;

int main() {
#ifdef CONTEST
	freopen("loutraki.in","r",stdin);
	freopen("loutraki.out","w",stdout);
#endif
	scanf("%d", &N);
	for(int i=1; i<=N; ++i){
		scanf("%d%d",&hotel[i].x,&hotel[i].y);
		hotel[i].x += OFFSET;
		hotel[i].y += OFFSET;
		C[i] = coord( hotel[i].x, hotel[i].y, i );
	}

	sort(C+1,C+N+1,[](const auto& a,const auto& b){return (a.x==b.x)?(a.y<b.y):(a.x<b.x);});
	for(int i=1;i<=N;){
		int co = C[i].x;
		hotel[C[i].hotel_id].visibility++;
		while(C[i].x == co)
			i++;
	}

	sort(C+1,C+N+1,[](const auto& a,const auto& b){return (a.y==b.y)?(a.x<b.x):(a.y<b.y);});
	for(int i=1;i<=N;){
		int co = C[i].y;
		hotel[C[i].hotel_id].visibility++;
		while(C[i].y == co)
			i++;
	}

	for(int i=1;i<=N;i++)
		if(hotel[i].visibility==2)
			ans++;
		
	printf("%d\n", ans);
	return 0;
}
