#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;
float pin[100000];
void readfile();
void printfile();
void prwti_methodos();
void deyteri_methodos();
void createfile();
int k,n,i;
double mo1,mo2,sum;
int main()
{
readfile();
sort(pin,pin+n);
prwti_methodos();
deyteri_methodos();
createfile();
//printfile();
return 0;
} ////////////////////////////////////////
void readfile() {
int i;
ifstream infile ("ensemble.in");
infile>>n>>k;
for(i=0;i<n;i++)
infile>>pin[i];
infile.close();
}

/////////////////////////////////////////
void printfile() {
int i;
for(i=0;i<n;i++)
cout<<pin[i]<<endl;
} //////////////////////////////////////////
void prwti_methodos() {
sum=0;
for(i=0;i<k;i++)
pin[i]=0;
for(i=(n-k);i<n;i++)
pin[i]=0;
for(i=0;i<n;i++)
sum=sum+pin[i];
mo1=sum/(n-k*2);
//cout<<fixed<<setprecision(2)<<mo1<<endl;
} /////////////////////////////////////////
void deyteri_methodos() {
sum=sum+(pin[k]*k)+(pin[n-k-1]*k);
mo2=sum/n;
//cout<<fixed<<setprecision(2)<<mo2<<endl;
} //+++++++++++++++++++++++++++++++++++
void createfile() {
ofstream outfile("ensemble.out");
outfile<<fixed<<setprecision(2)<<mo1<<" "<<fixed<<setprecision(2)<<mo2<<endl;
} /////////////////////////////////////////

