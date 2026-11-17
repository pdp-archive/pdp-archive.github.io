/* Παναγιωτάκος Γεώργιος 1ο ΓΕΛ Σπάρτης */
     
#include <iostream>
#include <fstream>
#include <list>

using namespace std;

int n,m1,m2;
class Pt 
{
  public:
  int x,y;
};

bool operator<(Pt a,Pt b)
{
  if(a.x==b.x)
    return a.y<b.y;
  else
    return a.x<b.x;
}

list<Pt> L;

int main()
{
  //input
  ifstream fin("sonar.in");
  ofstream fout("sonar.out");
  fin >> n >> m1 >> m2;
  //
  //main prog
  int u,i;
  Pt a;

  for(u=0;u<m1;u++)
  {
    fin >> a.x >> i;
    a.y=n+1-i;
    L.push_back(a);
  }
  for(u=0;u<m2;u++)
  {
    fin >> a.y >> i;
    a.x=n+1-i;
    L.push_back(a);
  }
  L.sort();
  Pt last;
  last.x=-1;
  last.y=-1;
  list<Pt>::iterator l;
  for(l=L.begin();l!=L.end();l++)
  {
    if((*l).x==last.x && (*l).y==last.y)
    { l=L.erase(l);
      l--;
      continue;
    }
    last.x=(*l).x;
    last.y=(*l).y;
  }
  fout << L.size() << "\n";
  for(l=L.begin();l!=L.end();l++)
    fout << (*l).x << " " << (*l).y << "\n";
  return 0;
}

