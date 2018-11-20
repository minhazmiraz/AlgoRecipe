#include <Bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int MODval[1000];
//recursive
long long bigMOD(long long a, long long p){
	if(p==0) return 1;
	long long res=bigMOD(a,p/2)%MOD;
	if(p%2) return (res*res*a)%MOD;
	else return (res*res)%MOD;
}


int main(){
	//iterative
	long long a,p;
	cin>>a>>p;
	MODval[0]=1; MODval[1]=a;
	for(int i=2;i<1000;i++){
		int res=MODval[i/2]%MOD;
		if(i%2) MODval[i] = (res*res*a)%MOD;
		else MODval[i] = (res*res)%MOD;
	}
	cout<<MODval[p]<<endl;
	cout<<bigMOD(a,p)<<endl;
	return 0;
}