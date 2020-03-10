#include <bits/stdc++.h>
#define MAXN 1000000
using namespace std;


int t, n;
char word[MAXN +5];
bool Q1left[MAXN +5], Q2left[MAXN +5], Q1right[MAXN +5], Q2right[MAXN+5];

int main()
{
	freopen("symstr.in","r",stdin);
	freopen("symstr.out","w",stdout);
	scanf("%d%d",&t,&n);
	while (t--)
	{
		scanf("%s",word+1);
		bool left, right, middle;
		left = right = false;
		middle = true;
		Q1left[0] = Q1right[0] = Q2left[0] = Q2right[0] = 1;

		//middle knows whether the left and the right part are equal
		//Q1 and Q2 are as described in the solution
		//printf("word: %s\n", word+1);
		for(int i=1; i<=n/2; ++i) {
			Q1left[i] = Q1right[i] = Q2left[i] = Q2right[i] = 0;
			if(word[i] != word[n/2+1+i]) middle = false;
			if(Q1right[i-1] && word[i] == word[n/2+i]) Q1right[i] = 1;
            		if(Q2right[i-1] && word[n/2+1-i] == word[n+1-i]) Q2right[i] = 1;
            		if(Q1left[i-1] && word[i] == word[n/2+1+i]) Q1left[i] = 1;
            		if(Q2left[i-1] && word[n/2+2-i] == word[n+1-i]) Q2left[i] = 1;
		}

		for(int i=1; i<=n/2; ++i) {
			if (Q1left[i-1] && Q2left[n/2-i+1]) left = true;
            		if (Q1right[i] && Q2right[n/2-i]) right = true;
		}

		if (middle) printf("%s\n",word+n/2+2);
		else if (left && right) printf("1\n");
		else if (right) word[n/2+1] = '\0', printf("%s\n",word+1); //hack to avoid copying the left half and then print :)
		else if (left) printf("%s\n",word+n/2+2);
		else printf("0\n");
	}
}
