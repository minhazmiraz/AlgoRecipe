#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAX 100005
#define LL long long
#define SET(x,n) (x[n>>6]|=(1<<((n>>1)&31)))
#define GET(x,n) (x[n>>6]&(1<<((n>>1)&31)))

vector< int > prime;

void sieve(unsigned n){
    unsigned sz = (n>>6)+5;
    unsigned status[sz];
    memset(status,0,sizeof status);
    unsigned sqrtN = (unsigned)sqrt((double)n);
    for(unsigned i=3;i<=sqrtN;i+=2){
        if(!GET(status,i)){
            for(unsigned j=i*i;j<=n;j+=(i+i)){
                SET(status,j);
            }
        }
    }
    prime.pb(2);
    for(unsigned i=3;i<=n;i+=2){
        if(!GET(status,i)){
            prime.pb(i);
        }
    }
}

vector< int > factor;
//int coun[MAX];
void prime_fact(unsigned n){
    //memset(coun,0,sizeof coun);
    unsigned sqrtN = (unsigned)sqrt((double)n);
    for(int i=0;i<prime.size()&&prime[i]<=sqrtN;i++){
        if(n%prime[i]==0){
            while(n%prime[i]==0){
                n/=prime[i];
                //coun[prime[i]]++;
                factor.pb(prime[i]);
            }
            sqrtN = (unsigned)sqrt((double)n);
        }
    }
    if(n!=1)
        factor.pb(n);
}


int main(){
    int n;
    cin>>n;
    sieve(n);
    prime_fact(n);
    for(int i=0;i<factor.size();i++)
        cout<<factor[i]<<endl;
    return 0;
}
