#include <cstdio>
#include <map>

std::map<long,long> Acc;

int main(){
    freopen("bankacc.in", "r",stdin);
    freopen("bankacc.out","w",stdout);
    long N;
    scanf("%ld",&N);
    for(long i=0;i<N;i++){
        long A,x;
        char tp;
        scanf(" %c %ld",&tp,&A);
        switch(tp){
            case 'q':
                printf("%ld\n",Acc[A]);
                break;
            case 'd':
                scanf("%ld",&x);
                Acc[A] += x;
                printf("s\n");
                break;
            case 'w':
                scanf("%ld",&x);
                if(Acc[A] < x){
                    printf("f\n");
                }else{
                    Acc[A] -= x;
                    printf("s\n");
                }
                break;
        }
    }
    return 0;
}
