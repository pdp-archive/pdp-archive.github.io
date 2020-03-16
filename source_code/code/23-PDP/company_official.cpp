/* Κυριάκος Αξιώτης */ 

#include <cstdio>
#include <vector>
typedef long long ll;
using namespace std;int N,bpos,x;
vector<vector<int> > con(400001);
bool male[400001];
char buf[3610001],c;
ll tot[2];
FILE *fin,*fout;
struct st
{
  int x,y;
}tmp;

int readint ()
{
  x=0;
  while (1)
  {
    c=buf[bpos++];
    if (c>32) x=x*10+c-48;
    else return x;
  }
}

st dfs (int i)
{
  st t=(st){0,0};
  for (vector<int>::iterator J=con[i].begin();J!=con[i].end();++J)
    tmp=dfs(*J),t.x+=tmp.x,t.y+=tmp.y;
  if (male[i]) tot[1]+=t.y,++t.x;
  else tot[0]+=t.x,++t.y;
  return t;
}

int main ()
{
  fin=fopen("company.in","r");
  fout=fopen("company.out","w");
  fread(buf,1,3610000,fin);
  N=readint();
  int tmp,start,i;
  for (i=1;i<=N;++i)
  {
    tmp=readint();
    con[tmp].push_back(i);
    if (!tmp) start=i;
    male[i]=(buf[bpos]=='m'),bpos+=2;
  }
  dfs(start);
  ll res=tot[1]-tot[0];
  fprintf(fout,"%lld\n",res);
  return 0;
}
