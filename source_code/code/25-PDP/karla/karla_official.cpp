#include <iostream>
#include <fstream>
using namespace std;
bool lake[102][102];
int left1;
void flood(int a, int b)
{
if (lake[a][b])
{
lake[a][b]=false;
left1--;
flood(a-1,b);
flood(a+1,b);
flood(a,b-1);
flood(a,b+1);
}
}
int main()
{
int n,high,i,j,temp,cnt=0;
ifstream data("karla.in");
data>>n;
data>>high;
for (i=0;i<=n+1;i++)
{
lake[i][0]=false;
lake[0][i]=false;
lake[n+1][i]=false;
lake[i][n+1]=false;
}
left1=n*n;
for (i=1;i<=n;i++)
{
for (j=1;j<=n;j++)
{
data>>temp;
if (temp>high) lake[i][j]=true;
else {lake[i][j]=false; left1--;}
}
}
cnt=0;
while (left1>0)
{
for (i=1;i<=n;i++)
for (j=1;j<=n;j++)
if (lake[i][j]){ flood(i,j);cnt++;}
}
ofstream outdata("karla.out");
outdata<<cnt << endl;
return 0;
}
