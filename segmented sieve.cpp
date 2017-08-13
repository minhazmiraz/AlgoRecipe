#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define LL long long
#define SET(x,n) (x[n>>6]|=(1<<((n>>1)&31)))
#define GET(x,n) (x[n>>6]&(1<<((n>>1)&31)))


vector < LL > prime;
void sieve(LL n){
    LL sz = (n>>6)+1;
    LL status[sz];
    memset(status,0,sizeof status);


    LL sqrtN = (LL)sqrt((double)n);
    for(LL i=3;i<=sqrtN;i+=2){
        if(!GET(status,i)){
            prime.pb(i);
            for(LL j=i*i;j<=n;j+=(i+i)){
                SET(status,j);
            }
        }
    }
}


void segmented_sieve(LL a, LL b){
    LL sz = ((b-a+1)>>6)+1;
    if(a<3){cout<<"2 "; a=3;}
    if(a%2==0) a++;
    LL status[sz];
    memset(status,0,sizeof status);


    LL sqrtN = (LL)((double) sqrt(b));
    for(LL i=0;i<prime.size();i++){
        LL p=prime[i];
        LL j = p*p;
        if(j<a)
            j=p*((p+a-1)/p);

        if(j%2==0) j+=prime[i];
        for(;j<=b;j+=(p+p)){
            if(j!=primes[i])
                SET(status,(j-a));
        }
    }

    for(LL i=a;i<=b;i+=2){
        if(!GET(status,(i-a))){
            cout<<i<<" ";
        }
    }
}

int main(){
    LL a,b;
    scanf("%lld%lld",&a,&b);
    sieve(b);
    segmented_sieve(a,b);
    printf("\n");
    return 0;
}

