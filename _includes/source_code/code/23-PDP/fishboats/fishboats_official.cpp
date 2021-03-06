/*
USER : pdp23u29
LANG : C++
TASK : fishboats
*/
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int N,M,x,mx=-10000,mn=10000;
vector<int> A;

int main() {
   int i,s;
   freopen("fishboats.in","r",stdin);
   freopen("fishboats.out","w",stdout);
   scanf("%d %d", &N,&M);
   for(i=0;i<N;i++) {
      scanf("%d", &x);
      A.push_back(x);
      if(x>mx)mx = x;
      if(x<mn)mn = x;
   }
   sort(A.begin(),A.end());
   long long sum = 0,mxsum=0,d, Max = 0;
   for(s=0;s<N;s++){
      if(A[s]>=0){
         for(i=0;i<N;i++){
            d = 0;
            if(i>s){
               if(A[i]>=0) d = A[i]+2*A[s]+2*abs(mn);
               else d = abs(A[i])+2*A[s];
               sum += (M-d>0)?M-d:0;
            }
            else {
               if(A[i]>=0) d = A[i];
               else d = abs(A[i])+2*A[s];
               sum += (M-d>0)?M-d:0;
            }
         }
         if(sum>mxsum)mxsum = sum;
      } else {
         for(i=0;i<N;i++) {
            d=0;
            if(i<s){
               if(A[i]>0) d = A[i]+2*abs(A[s]);
               else d = abs(A[i])+2*abs(A[s])+2*mx;
               sum += (M-d>0)?M-d:0;
            } else {
               if(A[i]>0) d = A[i]+2*abs(A[s]);
               else d = abs(A[i]);
               sum += (M-d>0)?M-d:0;
            }
         }
         if(sum>mxsum)mxsum = sum;
      }
      if(mxsum>Max)Max = mxsum;
      sum=0;
   }
   printf("%lld\n", Max);
   return 0;
}
