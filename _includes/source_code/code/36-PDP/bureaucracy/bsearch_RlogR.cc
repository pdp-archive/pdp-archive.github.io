#include <algorithm>
#include <climits>
#include <cstdio>
#include <queue>
#include <vector>

long N,R,Snr,Dnr;
std::vector<std::vector<std::pair<long,long>>> edge;//λίστα γειτνίασης με <βάρος,προορισμό>
std::vector<long> W;//όλα τα βάρη των ακμών
std::vector<bool> D;

long bfs(long limit){
    std::vector<bool> visit(N+1, false);
    long dest_reach = 0, //πόσους τελικούς κόμβους φτάσαμε 
         time = -1,//απόσταση σε ακμές από αφετηρία
         coins = 0;//χρυσά νομίσματα που ξοδέψαμε ως τώρα
    std::queue<long> Q;
    Q.push(0); visit[0]=true;
    while(!Q.empty()){
        time++;//προχωρήσαμε ακόμα μια ακμή (ημέρα εργασίας)
        for(long i=0, sz=Q.size(); i<sz; i++){//sz: κόμβοι απόστασης time από αφετηρία
            long v = Q.front(); Q.pop();
            for(auto [w,u]:edge[v]){//c++17 feature:structured bindings
                if(w > limit) continue; //βάρος εκτός ορίου
                if(visit[u]) continue;//τον ανακαλύψαμε νωρίτερα
                visit[u] = true;
                if(D[u])//είναι τελικός κόμβος;
                    ++dest_reach, coins += time;
                Q.push(u);
            }
        }
    }
    if(dest_reach == Dnr)
        return coins;//επέστρεψε τις συνολικές ακμές που διανύσαμε 
    return -1;//δεν φτάσαμε σε όλους τους τελικούς κόμβους
}

int main(){
    FILE *in = fopen("bureaucracy.in", "r");
    FILE *out= fopen("bureaucracy.out","w");    
    
    long L=-1/*min L*/, C=-1/*min νομίσματα*/;
    fscanf(in, "%ld%ld%ld%ld", &N, &Snr, &Dnr, &R);
    D.resize(N+1, false);
    edge.resize(N+1);
    
    //ανάγνωση αρχείου εισόδου
    for(long i=0, s; i < Snr; i++){ 
        fscanf(in, "%ld", &s); 
        edge[0].push_back( {0, s} ); 
    }
    for(long i=0, u; i < Dnr; i++){ 
        fscanf(in, "%ld", &u); 
        D[u] = true;/*u: τελικός κόμβος*/
    }
    for(long v, u, e, i=0; i < R; i++){
        fscanf(in, "%ld%ld%ld\n", &v, &u, &e);
        edge[v].push_back( {e, u} );
        W.push_back(e);
    }    
    
    //W:θα έχει όλα τα E(βάρη) σε γνησίως αύξουσα σειρά
    std::sort(W.begin(), W.end());
    //πέταξε τα διπλότυπα από τον W
    W.erase( std::unique(W.begin(), W.end()), W.end());
    
    long left = 0, right = W.size()-1;
    while(left <= right){
        long mid = (left + right) / 2, Ctest = bfs(W[mid]);
        if(Ctest > 0L){
            L = W[mid], C = Ctest;
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
    fprintf(out, "%ld %ld\n", L, C);
    
    fclose(out);
    fclose(in);
    return 0;
}
