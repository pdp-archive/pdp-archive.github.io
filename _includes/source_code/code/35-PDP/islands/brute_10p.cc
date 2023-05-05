#include <cstdio>
#include <vector>

using namespace std;

int main(){
	freopen("islands.in","r",stdin);
	freopen("islands.out","w",stdout);
	long N,Q,ans;
	scanf("%ld%ld",&N,&Q);
	vector<int> Z(N+1,0);//πίνακας με τα απαιτούμενα εισιτήρια
	while(Q--){
		char c;long a,b;
		scanf(" %c%ld%ld",&c,&a,&b);
		switch(c){
		case 'D':
			for(long i=a+1;i<=b;i++)
				Z[i] = 1;
			break;
		case 'B':
			for(long i=a+1;i<=b;i++)
				Z[i] = 0;
			break;
		case 'Q':
			ans = a;
			while(ans<N && (Z[ans+1]==0 || b-->0))
				ans++;
			printf("%ld\n",ans);
			break;
		}
	}
	return 0;
}
