#include <algorithm>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <vector>

long N,R,Snr,Dnr;
std::set<std::pair<long,std::pair<long,long>>> edge;//ακμές: <βάρος,<από,προς>>
std::vector<bool> is_dest;
std::vector<std::vector<long>> adj;//πίνακας γειτνίασης εξερευνημένου γράφου (w<=L)
long L,C;

long bfs(){
    std::vector<bool> visit(N+1, false);
    long time = -1,//απόσταση σε ακμές από αφετηρία
         coins = 0;//χρυσά νομίσματα που ξοδέψαμε ως τώρα
    std::queue<long> Q;
    Q.push(0); visit[0]=true;
    while(!Q.empty()){
        time++;//προχωρήσαμε ακόμα μια ακμή (ημέρα εργασίας)
        for(long i=0, sz=Q.size(); i<sz; i++){//sz: κόμβοι απόστασης time από αφετηρία
            long v = Q.front(); Q.pop();
            for(auto u:adj[v]){
                if(visit[u]) continue;//τον ανακαλύψαμε νωρίτερα
                visit[u] = true;
                if(is_dest[u])//είναι τελικός κόμβος;
                    coins += time;
                Q.push(u);
            }
        }
    }
    return coins;
}

int main() {
    FILE *in = fopen("bureaucracy.in", "r");
    FILE *out= fopen("bureaucracy.out","w");    
    fscanf(in, "%ld%ld%ld%ld", &N, &Snr, &Dnr, &R);
    adj.resize(N+1);
    is_dest.resize(N+1,false);
    
    for (long s, i = 0; i < Snr; i++) {
        fscanf(in,"%ld", &s);
        edge.insert({0,{0,s}});//ακμή από dummy node προς αρχικό κόμβο
    }
    for (long d, i = 0; i < Dnr; i++) {
        fscanf(in,"%ld", &d);
        is_dest[d] = true;
    }
    for (long a, b, e, i = 0; i < R; i++) {
        fscanf(in,"%ld%ld%ld", &a, &b, &e);
        edge.insert( {e, {a, b} } );
    }
    
    long remain_dest = Dnr;
    std::vector<bool> visit(N+1, false);
    visit[0] = true;
    
    while(remain_dest){
        for(auto it = edge.begin();it!=edge.end();it++){
            auto w = it->first;
            auto [u,v] = it->second;
            
            if(!visit[u])continue;//δεν επεκτείνει τον εξερευνημένο γράφο
            if(!visit[v]){//επέκταση γράφου με τον κόμβο v
                visit[v] = true;
                if(is_dest[v]) --remain_dest;
            }
            adj[u].push_back(v);
            L = std::max(L,w);
            edge.erase(it);
            break;
        }
    }
    //πρόσθεσε όλες τις ακμές έως το όριο L που υπολογίσαμε στη λίστα γειτνίασης
    for(auto it=edge.begin();it!=edge.end();it++){
        auto w = it->first;
        auto [u,v] = it->second;
        if(w<=L)adj[u].push_back(v);
    }
    C = bfs();
    fprintf(out, "%ld %ld\n", L, C);
    
    fclose(out);
    fclose(in);
    return 0;
}