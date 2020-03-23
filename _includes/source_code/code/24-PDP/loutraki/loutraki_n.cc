#include <bits/stdc++.h>

using namespace std;

const long MAXN = long(1e6);
const long OFFSET = long(1e5);

bool hidden[MAXN+5];		//true if hotel i is blocked
long X[2*OFFSET+2],Y[2*OFFSET+5];//what is the frontmost id of the hotel in this axis
pair<long,long> hotel[MAXN+5];
long N, ans;
#define	xx	first
#define	yy	second

void hide_hotel(long i){//hide a previously processed hotel.
	if(!hidden[i]){
		ans--;//i is no more part of answer
		hidden[i] = true;
	}
}

int main() {
#ifdef CONTEST
	freopen("loutraki.in","r",stdin);
	freopen("loutraki.out","w",stdout);
#endif
	scanf("%ld", &N);
	for(long x,y,i=1; i<=N; ++i){
		scanf("%ld%ld",&x,&y);
		x+=OFFSET; y+=OFFSET; //make positive
		hotel[i] = {x,y};
		long visibility = 0;
		
		//will we hide some other hotel from viewing xx' axis?
		if(X[x]){//there is a hotel with same x
			if(y < hotel[X[x]].yy){	//yes, replace old one X[x]
				hide_hotel(X[x]);
				X[x] = i;
				visibility++;
			}
		} else {//first hotel in that x pos
			X[x] = i;
			visibility++;
		}
		
		//will we hide some other hotel from viewing yy' axis?
		if(Y[y]){//there is a hotel with same y
			if(x < hotel[Y[y]].xx){//yes, replace old one Y[y]
				hide_hotel(Y[y]);
				Y[y] = i;
				visibility++;
			}
		} else {//first hotel in that y pos
			Y[y] = i;
			visibility++;
		}
		
		if(visibility<2)
			hidden[i] = true;
		else
			ans++;
	}
	printf("%ld\n", ans);
	return 0;
}
