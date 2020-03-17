/*
USER:pdp24u226
TASK:loutraki
LANG:C++
*/
#include<bitset>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<algorithm>
#include<stack>
using namespace std;
#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"assert.h"
FILE *fin,*fout;
int minx[200001],miny[200001];
int minx_bel[200001],miny_bel[200001];
bool bouno[1000001],paralia[1000001];
int N;
int main(){
	int i,j,k;
	fin=fopen("loutraki.in","r");
	assert(fin);
	fscanf(fin,"%d",&N);
	for(i=1;i<=N;i++){
		fscanf(fin,"%d %d",&j,&k);
		//printf("check (%d,%d)->(%d,	%d)\n",j,k,j+100000,k+100000);

		j+=100000;
		k+=100000;
		//min x for row
		if(minx_bel[k]==0||minx[k]>j){
			minx_bel[k]=i;
			minx[k]=j;
		}
		//min y for row
		if(miny_bel[j]==0||miny[j]>k){
			miny_bel[j]=i;
			miny[j]=k;
		}
	}
	fclose(fin);
	for(i=0;i<=200000;i++){
		if(minx_bel[i]!=0){
			//printf("minx for row %d is %d, belongs to %d\n",i-100000,minx[i]-100000,minx_bel[i]);
			bouno[minx_bel[i]]=true;
		}
	}
	for(i=0;i<=200000;i++){
		if(miny_bel[i]!=0){
			//printf("miny for col %d is %d, belongs to %d\n",i-100000,miny[i]-100000,miny_bel[i]);
			paralia[miny_bel[i]]=true;
		}
	}

	j=0;
	for(i=1;i<=N;i++){
		if(bouno[i]&&paralia[i]){
			//printf("%d wins\n",i);
			j++;
		}
	}
	fout=fopen("loutraki.out","w");
	fprintf(fout,"%d\n",j);
	fclose(fout);
	return 0;
}
