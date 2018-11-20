#include <bits/stdc++.h>
using namespace std;

vector< bool > bs;
void sieve(){
	bs.resize(10000005);
	bs[1]=1;
	for(long long i=2;i<=10000000;i+=2) bs[i]=1;
	for(long long i=3;i<=10000000;i+=2) if(!bs[i]) for(long long j=i*i;j<=10000000;j+=(i+i)) bs[j]=1;
}

int main(){
	sieve();
	return 0;
}