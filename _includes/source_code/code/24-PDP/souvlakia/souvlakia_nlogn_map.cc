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
#include <map>

using namespace std;

const long 
	MAXN = long(1e5),	//max shops
	MAXQ = long(5e4),	//max queries
	INF  = LONG_MAX;	//INF for dijkstra
	
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
	set<pair<long,long>> DS;//<distance,shopid> like a priority queue
	
	DS.insert({0,src});
	S[src].d[dupd] = 0;
	
	while(!DS.empty()){//explore
		auto x = *(DS.begin());//head of priority queue
		DS.erase(DS.begin());
		long daddy = x.second;
		for(auto y : edge[daddy]){//expand graph
			long child = y.first, dist = y.second;
			if(S[daddy].d[dupd]!=INF && S[child].d[dupd] > S[daddy].d[dupd] + dist){
				//this is an improvement
				if(S[child].d[dupd]!=INF)//was it in the queue already?
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

//Instead of a RMQ we should consider that we only need to store on the increasing 
//sequence of Y line, the corresponding descending sequence of Z values. 
//In fact forevery Y<Y' <=> Z>Z' (stricly descreasing subsequence)
//So let's make it in a map of Y values to Z
map<long,long> Zmin;
typedef map<long,long>::iterator iter;

void sinit(){
	//add some edge limits so we'll not have to check for 
	//begin()/end() limits while adjusting iterators
	Zmin.insert({-2,INF});//lower limit for optimization and queries
	Zmin.insert({INF,-1});//upper limit for optimizations
}
long squery(long y){
	iter it = Zmin.lower_bound(y-1);
	while(it->first >= y)it--;
	return it->second;
}
void supdate(long y,long z){
	iter curr = Zmin.find(y);
	if(curr == Zmin.end()){
		curr = (Zmin.insert({y,z})).first;
	} else if(curr->second > z){
		curr->second = z;
	} else 
		return;//no modification done
	//optimize. keep d2 sequence stricly descending while d1 ascends
	//optimize backward
	while(1){
		iter prev = curr; prev--;
		if(prev->second > curr->second)
			break;
		Zmin.erase(curr);
		curr = prev;
	}
	//optimize forward
	while(1){
		iter next = curr; next++;
		if(next->second < curr->second)
			break;
		Zmin.erase(next);
	}
}

int main(){
#ifdef CONTEST
	freopen("souvlakia.in", "r",stdin);
	freopen("souvlakia.out","w",stdout);
#endif
	N = read_fast(), M = read_fast();
	
	{//hint: edge vector below is temporary 
		//max mem usage: 400.000 * 2 * 3 * sizeof(long) = 2.400.000 * sizeof(long) = 19.2Mb
		//and we definitely benefit our program by releasing this mem when no more required
		//if we use a dynamic allocated scheme for implicit segment tree or use map template
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

	sinit();
	for(long right = 1, left = 1; left <=N;){
		while(right<=N && S[right].X == S[left].X){
			//for all shops with equal X postpone updates
			const shop& s = S[right];
			bool capable = (squery(s.Y-1) >= s.Z);
			
			for(auto e:s.queryid)
				ans[e] = capable;
			right++;
		}
		while(left<right){//do postponed updates
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
		answer 1 query:		O(logN)
		(we have a maximum of N distinct Y values in the map)
		answer all queries:	O(NlogN)
		print queries:		O(Q)
		
		overall complexity:	O((N+M)logN + Q)
*/
