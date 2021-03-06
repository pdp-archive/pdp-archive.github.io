/*
USER: 22pdp33
LANG: C++
TASK: servers,
*/
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct site
{
   int id;
   long int hits;
};

int compare(const void *a, const void *b)
{
   site sa;
   site sb;
   sa = *(site*)a;
   sb = *(site*)b;
   return sb.hits-sa.hits;
}

int main()
{
   ifstream fin("servers.in");
   ofstream fout("servers.out");
   int M, N, K, i, s, j;
   long int h;
   site sites[10000];
   fin >> M >> N >> K;
   for(i=0;i<M;i++)
   {
      sites[i].id=i;
      sites[i].hits=0;
   }
   for(i=0;i<M;i++)
   {
      for(j=0;j<N;j++)
      {
         fin >> s >> h;
         //cout << s << ' ' << h;
         sites[s].hits+=h;
         //cout << ' ' << sites[s].id << ' ' << sites[s].hits << endl;
      }
   }
   qsort(sites,M,sizeof(site),compare);
   for(i=0;i<K;i++)
   {
      fout << sites[i].id << ' ' << sites[i].hits << '\n';
      //cout << sites[i].id << ' ' << sites[i].hits << endl;
   }
   fin.close();
   fout.close();
   return 0;
}
