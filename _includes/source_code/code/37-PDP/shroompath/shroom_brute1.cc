#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int t,S,X,Y;
long ans = 1000000013;
vector<char> Z;

const char shrooms[] = "ab";//επιτρεπτοί χαρακτήρες
void add_length_w(vector<char>& str,int pos){
    //υπολόγισε όλους τους συνδυασμούς ξεκινώντας από τη θέση pos
    if(pos == str.size()){//καλύφθηκε το επιθυμητό μήκος
        Z.insert(Z.end(),str.begin(),str.end());
        return;
    }
    for(int i=0;shrooms[i]!=0;i++){
        str[pos] = shrooms[i];
        add_length_w(str,pos+1);
    }
}

int main(){
#ifdef CONTEST
    freopen("shroompath.in","r",stdin);
    freopen("shroompath.out","w",stdout);
#endif
    scanf("%d%d%d%d",&t,&S,&X,&Y);
    int A = (X>0) ? (S+X-1)/X : -1;
    int B = (Y>0) ? (S+Y-1)/Y : -1;
    for(int w=1;w<=max(A,B);w++){
        vector<char> str(w);
        add_length_w(str,0);
    }
    if(A>0){
        vector<char> f(A,'a');
        long pos = search(Z.begin(), Z.end(), f.begin(), f.end()) - Z.begin();
        ans = min(ans,pos+A);
    }
    if(B>0){
        vector<char> f(B,'b');
        long pos = search(Z.begin(), Z.end(), f.begin(), f.end()) - Z.begin();
        ans = min(ans,pos+B);
    }
    printf("%ld\n",ans);
    return 0;
}
