#include <algorithm>
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <cmath>

typedef long long ll;

typedef std::vector<int> bigint; //η θέση 0 περιέχει το Least Significant Digit 

void read(bigint& a){
    char s[45];
    scanf(" %s",s);
    a.clear();
    for(int i=strlen(s)-1;i>=0;i--)
        a.push_back(s[i]-'0');
}

void write(const bigint& a){
    printf("%d",a.size()==0?0:a[a.size()-1]);
    for(int i=a.size()-2;i>=0;i--)
        printf("%0d",a[i]);
}

bigint operator +(const bigint& a,const bigint& b){
    bigint c;
    int remain=0;
    for(int i=0;remain or i<a.size() or i<b.size();i++){
        int result = remain;
        if(i<a.size()) result += a[i];
        if(i<b.size()) result += b[i];
        c.push_back(result % 10);
        remain = result / 10;
    }
    return c;
}

bigint& operator +=(bigint& a,const bigint& b){
    return a = a + b;
}

int cmp(const bigint& a,const bigint& b){
    if(a.size()<b.size())return -1;
    if(b.size()<a.size())return 1;
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]<b[i])return -1;//a<b
        if(a[i]>b[i])return 1;//a>b
    }
    return 0;//a==b
}

bool operator < (const bigint& a,const bigint& b){
    return cmp(a,b)<0;
}

bool operator == (const bigint& a,const bigint& b){
    return cmp(a,b)==0;
}

bool operator <= (const bigint& a,const bigint& b){
    return cmp(a,b)<=0;
}

bigint operator - (const bigint& a,const bigint& b){
    //προσοχή λειτουργεί σωστά μόνο όταν a>=b
    assert(b<=a);
    bigint c;
    int remain = 0;
    for(int i=0;i<a.size() or i<b.size();i++){
        if(i<b.size())remain += b[i];
        ll result = -remain;
        if(i<a.size()) result += a[i];
        remain = 0;
        if(result<0){//έχουμε κρατούμενο
            remain++;
            result+=10;
        }
        assert(result<10);
        c.push_back(result);
    }
    return c;
}

bigint abs_diff(const bigint& a,const bigint& b){//calculate abs(a-b)
    return (a<b) ? b - a : a - b;
}

int main(){
    freopen("polybox.in", "r", stdin);
    freopen("polybox.out", "w", stdout);
    long subtask,N;
    scanf("%ld%ld",&subtask,&N);
    std::vector<bigint> w(N),h(N);
    for(long i=0;i<N;i++)
        read(w[i]), read(h[i]);

    //υπολόγισε στη μεταβλητή box την πιο πάνω και την πιο κάτω πλευρά της στοίβας
    bigint box = w[0] + w[N-1];
    //πρόσθεσε στη box όλα τα ενδιάμεσα εκτεθημένα τμήματα
    for(long i=0;i<N-1;i++)
        box += abs_diff(w[i],w[i+1]);
    //πρόσθεσε τα ύψη όλων των κουτιών
    for(long i=0;i<N;i++)
        box += h[i] + h[i];
    write(box);
    putchar('\n');
    return 0;
}
