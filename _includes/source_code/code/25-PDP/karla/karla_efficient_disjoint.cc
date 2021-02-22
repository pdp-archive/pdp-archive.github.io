#include <cstdio>
//using namespace std;

const int MAXN = 101;
int N, M, ans;
bool Z[MAXN][MAXN];//κελιά (true αν μη πλημμυρισμένο)
int dj[MAXN*MAXN];//disjoint set.

inline int xy(int x,int y){//μετέτρεψε τις δυο διαστάσεις σε μία
    return y*N + x;
}

int dj_find(int xy){//βρες τον εκπρόσωπο του xy
    if(dj[xy] == xy)
        return xy;
    return dj[xy] = dj_find(dj[xy]);
}

bool dj_union(int a,int b){//ένωσε τα δυο set
    a = dj_find(a), b = dj_find(b);
    if(a!=b){//δεν έχουν τον ίδιο εκπρόσωπο
        dj[b] = a;//κάνε τον a, εκπρόσωπο του b
        return true;//έγινε συνέωση
    }
    return false;//ανήκουν στο ίδιο set
}

inline void dj_create(int xy){//δημιουργήθηκε ένα νέο set με το κελί αυτό
    dj[xy] = xy;
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
            if(!Z[x][y]) //πλημμυρισμένο κελί, αγνόησε το
                continue;
            
            dj_create(xy(x,y));
            ans++;
            
            if(x>0 && Z[x-1][y] && dj_union(xy(x,y),xy(x-1,y)))
                ans--;
            
            if(y>0 && Z[x][y-1] && dj_union(xy(x,y),xy(x,y-1)))
                ans--;
        }
    }
    printf("%d\n",ans);
    return 0;
}
