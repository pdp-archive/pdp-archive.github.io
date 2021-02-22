#include <cstdio>
#include <cassert>
//using namespace std;

const int MAXN = 101;
int N,M;
bool Z[MAXN][MAXN];//κελιά (true αν μη πλημμυρισμένο)
int dj[MAXN*MAXN];//disjoint set.
bool leader[MAXN*MAXN];//για την καταμέτηση των ομάδων

inline int xy(int x,int y){//μετέτρεψε τις δυο διαστάσεις σε μία
    return y*N + x;
}

int dj_find(int xy){//βρες τον εκπρόσωπο του x,y
    //xy είναι η μονοδιάσταση συντεταγμένη του κάθε κελιού
    if(dj[xy] == xy)
        return xy;
    return dj[xy] = dj_find(dj[xy]);
}

void dj_union(int a,int b){//ένωσε τις δυο ομάδες
    a = dj_find(a), b = dj_find(b);
    assert(a>=0 && b>=0);//πρέπει να έχουν εκπρόσωπο
    if(a!=b)//δεν έχουν τον ίδιο εκπρόσωπο
        dj[b] = a;//κάνε τον a, εκπρόσωπο του b
}

int dj_count(){
    int ans = 0;
    for(int i=0,k=N*N;i<k;i++){
        if(dj[i]>=0){
            int leader1 = dj_find(i);
            if(!leader[leader1]){
                leader[leader1]=true;
                ans++;
            }
        }
    }
    return ans;
}

int main(){
   freopen("karla.in", "r",stdin);
   freopen("karla.out", "w",stdout);

    scanf("%d%d",&N,&M);
    for(int y=0;y<N;y++){
        for(int a,x=0;x<N;x++){
            scanf("%d",&a);
            Z[x][y] = a>M;
        }
    }

    for(int y=0;y<N;y++){
        for(int x=0;x<N;x++){
            if(!Z[x][y]){ //πλημμυρισμένο κελί,
                dj[xy(x,y)] = -1;//να μην έχει εκπρόσωπο
                continue;
            }
            dj[xy(x,y)] = xy(x,y);//κάνε το εκπρόσωπο του εαυτού του

            if(x>0 && Z[x-1][y])
                dj_union(xy(x,y),xy(x-1,y));
            if(y>0 && Z[x][y-1])
                dj_union(xy(x,y),xy(x,y-1));
        }
    }

    printf("%d\n",dj_count());
    return 0;
}
