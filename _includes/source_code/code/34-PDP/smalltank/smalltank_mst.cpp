#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

struct edge {
	int u,v,w;
	edge(){u=v=w=0;}
	edge(int v,int u,int w):w(w),v(v),u(u){}
	bool operator < (const edge& x) const { return w < x.w; }
};
int N,M,ans;
vector<edge> E;

struct djset {
	int head, height;
	djset(){head=-1;height=1;}
};
vector<djset> dj;

int find(int u){
	if(dj[u].head==-1 || dj[u].head==u)
		return dj[u].head = u;
	return dj[u].head =  find(dj[u].head);//compress
}

void join(int v,int u){
	v = find(v), u = find(u);
	if(v!=u){
		if(dj[v].height>dj[u].height)//balance
			swap(v,u);
		if(dj[v].height==dj[u].height){
			dj[v].height++;
			dj[v].head = u;
		} else {//dj[v].height<dj[u].height
			//dj[u].height unchainged
			dj[u].head = v;
		}
	}
}

int main(){
    freopen("smalltank.in","r",stdin);
    freopen("smalltank.out","w",stdout);
	scanf("%d%d",&N,&M);
	dj = vector<djset>(N+1);
	
	for(int a,b,w,i=0;i<M;i++){
		scanf("%d%d%d",&a,&b,&w);
		E.push_back(edge(a,b,w));
	}
	
	//kruskal MST
	sort(E.begin(),E.end());
	int nedges = 0;
	for(const auto& e: E){
		int head1 = find(e.u);
		int head2 = find(e.v);
		if(head1!=head2){
			nedges++;
			ans = max(ans, e.w);
			join(head1,head2);
		}
	}
	assert(nedges == N-1);//tree
	
	printf("%d\n",ans);
	return 0;
}
