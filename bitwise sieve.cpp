#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define SET(x,n) (x[n>>6]|=(1<<((n>>1)&31)))
#define GET(x,n) (x[n>>6]&(1<<((n>>1)&31)))

void sieve(LL n){
    LL sz = (n>>6)+5;
    LL status[sz];
    memset(status,0,sizeof status);
    LL sqrtN = (LL)sqrt((double)n);
    for(LL i=3;i<=sqrtN;i+=2){
        if(!GET(status,i)){
            for(LL j=i*i;j<=n;j+=(i+i)){
                SET(status,j);
            }
        }
    }
    printf("Primes: \n 2 ");
    for(LL i=3;i<=n;i+=2){
        if(!GET(status,i)){
            printf("%lld ",i);
        }
    }
}


int main(){
    LL n;
    scanf("%lld",&n);
    sieve(n);
    printf("\n");
    return 0;
}
