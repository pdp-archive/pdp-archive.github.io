#include<stdio.h>
#define MAXM 1000002
int freq[MAXM];
int read_int()
{
	int cc = getc(stdin);
	for (;cc < '0' || cc > '9';)
		cc = getc(stdin);
	int ret = 0;
	for (;cc >= '0' && cc <= '9';){
		ret = ret * 10 + cc - '0';
		cc = getc(stdin);
	}
	return ret;
}
int main()
{
	freopen("aris.in","r",stdin);
	freopen("aris.out","w",stdout);
	int N=read_int();
	int M=read_int();
	int i=1,d;
	int K=0,X=MAXM,Y=0;
	for(; i<=N; ++i)
	{
		d = read_int();
		if(freq[d] == 0)
			K++;
		freq[d]++;
	}
	for(i=1; i<=N; i++)
	{
		if(freq[i] && freq[i] < X)
			X = freq[i];
		Y = (freq[i] > Y)?freq[i]:Y;
	}
	printf("%d %d %d\n",K,X,Y);
	return 0;
}
