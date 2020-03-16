#include <bits/stdc++.h>

using namespace std;

#define MAXN	int(1e6)
#define OFFSET	int(1e5)

int N, ans;
bool hidden[MAXN+1];		//true if hotel i is blocked
int X[2*OFFSET+2],Y[2*OFFSET+2];//what is the frontmost id of the hotel in this axis
pair<int,int> hotel[MAXN+1];
#define	xx	first
#define	yy	second

void hide_hotel(int i){//hide a previously processed hotel.
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
	scanf("%d", &N);
	for(int x,y,i=1; i<=N; ++i){
		scanf("%d%d",&x,&y);
		x+=OFFSET; y+=OFFSET; //make positive
		hotel[i] = {x,y};
		int visibility = 0;
		
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
	printf("%d\n", ans);
	return 0;
}
