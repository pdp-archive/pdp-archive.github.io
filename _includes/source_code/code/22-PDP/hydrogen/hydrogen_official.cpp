#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

struct at{
  int code,a;
};

bool comp(at a, at b){
  if(a.a==b.a){ return (a.code < b.code); }
  return (a.a > b.a);
}

int main(void){
  FILE *fin=fopen("hydrogen.in","r");
  int n;
  at A;
  vector<at> v;
  fscanf(fin,"%d\n",&n);
  for(int i=0;i<n;++i){
    fscanf(fin,"%d %d\n",&A.code,&A.a);
    if(A.a!=0){
      v.push_back(A);
    }
  }
  fclose(fin);
  sort(v.begin(),v.end(),comp);
  FILE *fout=fopen("hydrogen.out","w");
  n=(int)v.size();
  fprintf(fout,"%d\n",n);
  for(vector<at>::iterator it=v.begin();it!=v.end(); it++)
    fprintf(fout,"%d\n",it->code); 

  fclose(fout);
  return 0;
}     
