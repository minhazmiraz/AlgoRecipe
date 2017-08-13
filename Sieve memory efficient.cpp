
///
/// article in LightOJ
/// http://lightoj.com/article_show.php?article=1001
///


#include<bits/stdc++.h>
using namespace std;
#define pb push_back

void sieve(int n){
    int sz = n;
    int status[sz>>1];
    vector< int > prime;
    memset(status,0,sizeof status);
    int sqrtN=int(sqrt(double(sz)));
    prime.pb(2);
    for(int i=3;i<=sqrtN;i+=2){
        if(status[i>>1]==0){
            prime.pb(i);
            for(int j=i*i;j<=sz;j+=(i+i)){
                status[j>>1]=1;
            }
        }
    }

    for(int i=sqrtN+1;i<=sz;i+=2){
        if(status[i>>1]==0) prime.pb(i);
    }
    printf("PrimeS: %d\n",prime.size());
    for(int i=0;i<prime.size();i++){
        printf("%d ",prime[i]);
    }

}

int main(){
    int n;
    scanf("%d",&n);
    sieve(n);
    printf("\n");
    return 0;
}
