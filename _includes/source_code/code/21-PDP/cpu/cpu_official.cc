/* Παναγιωτάκος Γεώργιος (1ο ΓΕΛ Σπάρτης) */

#include <iostream>
#include <fstream>

using namespace std;

int n,m;
int C[50000][2];
int ins[50000][2],outs[50000][2];
int insN=0,outsN=0;
int c[2][100000][2];
int cN[2]={0,0};

bool pos( int a1,int a2,int node ) {
  int m1,m2;
  m1 = min(a1,a2);
  m2 = max(a1,a2);
  if( node>m1 && node<m2 ) return true;
  else return false;
}

int valid(int cn,int a,int b) {
  int i=0,e;
  for(e=0;e<cN[cn];e++) {
    if( c[cn][e][0] == -1 ) continue;
    if( pos(c[cn][e][0],c[cn][e][1],a) != pos(c[cn][e][0],c[cn][e][1],b) )
      return e;
  }
  return -1;//<--valid
}

int min( int a,int b ) {
  return ((a<b)?a:b);
}

int max( int a,int b) {
  return ((a>b)?a:b);
}

bool change( int cn,int ind ) {
  int o1,o2;
  o1 = valid(1-cn,c[cn][ind][0],c[cn][ind][1]);
  if( o1 == -1 ) {
    return -2;
    c[1-cn][cN[1-cn]][0] = c[cn][ind][0];
    c[1-cn][cN[1-cn]][1] = c[cn][ind][1];
    cN[1-cn]++;
    c[cn][ind][0] = -1;
    c[cn][ind][1] = -1;
    }//<-success
  else return -1;//<--failure
}

int main() {
  ifstream fin( "cpu.in" );
  ofstream fout( "cpu.out" );
  fin >> n;
  fin >> m;
  int u,i0,i1,i2,e,a,b,sol;
  sol = m;
  for(u=0;u<m;u++) {
    fin >> a >> b;
    //cout << a << " " << b << "\n";
    C[u][0] = a;
    C[u][1] = b;
    i0 = valid(0,a,b);
    if( i0 == -1 ) { 
      c[0][cN[0]][0] = a;
      c[0][cN[0]][1] = b;
      cN[0]++;
      continue; 
    }
    //cout << u << "Not in the first\n";
    i1 = valid(1,a,b);
    if( i1 == -1 ) { 
      c[1][cN[1]][0] = a;
      c[1][cN[1]][1] = b;
      cN[1]++;
      continue; 
    }
    //cout << u << "Not in the second\n";
    i0 = change( 0, i0 );
    if( i0 == -2 ) { 
      c[0][cN[0]][0] = a;
      c[0][cN[0]][1] = b;
      cN[0]++;
      continue; 
    }
    i1 = change( 1, i1 );
    if( i1 == -2 ){ 
      c[1][cN[1]][0] = a;
      c[1][cN[1]][1] = b;
      cN[1]++;
      continue; 
    }
    
    sol = u;
    break;
  }
  fout << sol << "\n";
  //cout << sol << "\n";
  return 0;
}

