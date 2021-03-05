#include <stdio.h>
#include <string.h>

using namespace std;

#ifdef _WIN32
inline int getchar_unlocked() { return getchar(); }
#endif
#define MAXN 1000005

int a[MAXN];

inline int ReadInt() {
   int c=getchar();
   int out=0;
   while(c=='\n' || c==' ')
      c=getchar();
   while(c!='\n' && c!=' ' && c!=-1) {
      out*=10;
      out+=(c-'0');
      c=getchar();
   }
   return out;
}

inline void PrintInt(int now) {
   FILE*write=fopen("domes.out","wt");
   fprintf(write,"%d",now);
   fclose(write);
}

int main() {
   freopen("domes.in","rt",stdin);
   int N=ReadInt(),M=ReadInt(),from,to,correct=0;
   memset(a,0,sizeof(int)*(N+5));
   for(int i=0;i<M;++i) {
      from=ReadInt();
      to=ReadInt();
      if(from!=to) {
         ++a[to];
         ++a[from];
      }
      if(a[from]==2)
         ++correct;
      if(a[to]==2 && from!=to)
         ++correct;
   }
   fclose(stdin);
   PrintInt(N-correct);
   return 0;
}
