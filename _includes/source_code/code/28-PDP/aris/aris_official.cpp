#include <cstdio>
#include <algorithm>
#define MAXM 1000001
int execution[MAXM];
FILE *in, *out;
void fastGet(int &x){
	register int c=getc_unlocked(in);
	x=0;
	for (; (c<48 || c>57); c=getc_unlocked(in));
	for (; (c>47 && c<58); c=getc_unlocked(in)) { x=(x<<1) + (x<<3) + c-48;}
}
int main(){
	in=fopen("aris.in","r");
	int N,M;
	fastGet(N);
	fastGet(M);
	int team;
	while(N--){
		fastGet(team);
		execution[team-1]++;
	}
	fclose(in);
	std::sort(execution,execution+M);
	int no_use=0;
	for(int i=0; i<M; i++){
		if(execution[i]!=0){
			no_use=i;
			break;
		}
	}
	out=fopen("aris.out","w");
	fprintf(out,"%d %d %d\n",M-no_use,execution[no_use],execution[M-1]);
	fclose(out);
	return 0;
}

