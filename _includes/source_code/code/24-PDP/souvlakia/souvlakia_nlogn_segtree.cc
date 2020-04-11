#ifdef CONTEST
	#define NDEBUG	//disable assert() checks
#endif

#include <cstdio>
#include <algorithm>
#include <climits>
#include <cassert>
#include <vector>
#include <list>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

const long 
	MAXN = long(1e5),//max shops
	MAXQ = long(5e4),//max queries
	INF  = LONG_MAX; //INF for dijkstra
long	N,M,Q,C[3];

struct shop {
#define	X	d[0]
#define Y 	d[1]
#define Z	d[2]
	long d[3];//The 3 distances (X,Y,Z) from {A,B,C}
	list<long> queryid;//query ids that has to answer shop[i]
			//use list in case there are more than one queries per shop
	shop(){ X=Y=Z=INF; }//help dijsktra initial values
	bool operator <(const shop& b) const { 
		return X < b.X;
	}
} S[MAXN+1];

void dijsktra(long src,long dupd,vector<vector<pair<long,long>>>& edge){
	//src is one of {A,B,C}
	//dupd in [0,3). Update Shop[*].d[dupd] distance from src
	set<pair<long,long>> DS;//<distance,shopid>
	
	DS.insert({0,src});
	S[src].d[dupd] = 0;
	
	while(!DS.empty()){//explore
		auto x = *(DS.begin());
		DS.erase(DS.begin());
		long daddy = x.second;
		for(auto y : edge[daddy]){//expand
			long child = y.first, dist = y.second;
			if(S[daddy].d[dupd]!=INF && S[child].d[dupd] > S[daddy].d[dupd] + dist){
				if(S[child].d[dupd]!=INF)
					DS.erase(DS.find({S[child].d[dupd],child}));
				S[child].d[dupd] = S[daddy].d[dupd] + dist;
				DS.insert({S[child].d[dupd],child});
			}
		}
	}
}

inline int read_fast(){//fast IO is required for this problem due to huge io
	int x = 0;
	char c;
	while((c=getchar_unlocked())<'0');//skip blanks, CR, LF
	do
		x = x*10 + (c-'0');
	while((c=getchar_unlocked())>='0');
	return x;
}

inline void write_fast(bool f){
	const char *s = f ? "YES\n":"NO\n";
	while(*s)
		putchar_unlocked(*s++);
}

//RMQ with segment tree code starts here
long YMAX = 1;	//max value of Y
long *Zrmq;//segment tree (RangeMinQuery)for Z
void sinit(){//allocate mem for segment tree and initialize it to (almost) infinity
	for(long i=1;i<=N;++i)
		YMAX = max(YMAX, S[i].Y);
	size_t Zrmqsize = 1 << size_t(ceil(log2(YMAX+1))+1);
	Zrmq = new long[Zrmqsize];
	memset(Zrmq,0x7f,sizeof(*Zrmq) * Zrmqsize);
}

long squery(long yright,long si=0,long ss=0,long se=-1){
	//query z min value for y in [0,yright]
	if(se==-1) 
		se = YMAX;
	if(yright<ss || yright<0)
		return INF;//not involved
	if(se<=d1right) 
		return Yrmq[si];//completely included
	long mid = (ss+se)/2;
	return min(
		squery(yright, si*2+1,ss,mid),
		squery(yright, si*2+2,mid+1,se)
	);
}

void supdate(long x,long y,long si=0,long ss=0,long se=-1){
	if(se==-1) 
		se = YMAX;
	if(y<ss || se<y)
		return;//not involved
	if(ss==se){
		Zrmq[si] = min(Zrmq[si],z);
	}else {
		long mid = (ss+se)/2;
		if(y<=mid) 
			supdate(y,z,si*2+1,ss,mid);
		else
			supdate(y,z,si*2+2,mid+1,se);
		Zrmq[si] = min(Zrmq[si*2+1],Zrmq[si*2+2]);
	}
}
//RMQ with segment tree code ends here

int main(){
#ifdef CONTEST
	freopen("souvlakia.in", "r",stdin);
	freopen("souvlakia.out","w",stdout);
#endif
	N = read_fast(), M = read_fast();
	
	{//hint: edge vector below is temporary
		vector<vector<pair<long,long>>> edge(N+1);//<edge_to, distance>
		for(long a,b,d,i=0;i<M;++i){
			a = read_fast(), b = read_fast(), d = read_fast();
			edge[a].push_back({b,d});
			edge[b].push_back({a,d});
		}
		for(int i=0;i<3;i++)
			C[i] = read_fast();
		Q = read_fast();

		for(long i=0;i<3;++i)
			dijsktra(C[i],i,edge);
	}//memory of edge vector is released

	//read queries and store reference so we can answer offline
	for(long i=0;i<Q;++i)
		S[read_fast()].queryid.push_back(i);//shop[q] has to answer i-th query

	sort(S+1,S+N+1);

	vector<bool> ans(MAXQ+1,false);		//offline answers

	sinit();//construct segment tree
	for(long right = 1, left = 1; left <=N;){
		while(right<=N && S[right].X == S[left].X){
			//for all shops with equal X postpone segment tree updates
			const shop& s = S[right];
			bool capable = (squery(s.Y-1) >= s.Z);
			
			for(auto e:s.queryid)
				ans[e] = capable;
			right++;
		}
		while(left<right){//update segment tree with our Z value in segment [0,Y]
			supdate(S[left].Y, S[left].Z);
			left++;
		}
	}
	
	for(long i=0;i<Q;++i)
		write_fast(ans[i]);
	
	return 0;
}

/*
	complexity
		N=vertices, M=edges, D=valus (width of segment tree)
		dijsktra: 		O((N+M) * logN)
		sort shops: 		O(NlogN)
		answer 1 query:		O(log(20000*N))
		(20000 is the max weight of 1 edge, so max dist exists if we have all shops
		in a straigt line and we have to pass all edges in order to go from last to first)
		answer all queries:	O(Nlog(20000*N))
		print queries:		O(Q)
		
		overall complexity:	O((N+M)logN + Nlog(20000N) + Q)
*/
