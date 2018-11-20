#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int prime[MAX],MODval[MAX];
void sieve(int n){
	memset(prime,0,sizeof prime);
	int sqrtN=sqrt(n);
	for(int i=3;i<=sqrtN;i+=2){
		if(!prime[i]){
			for(int j=i*i;j<=n;j+=(i+i))
				prime[j]=1;
		}
	}
}

int ExtendGCD(int a, int b, int &x, int &y){
	if(a==0){
		x=0,y=1;
		return b;
	}
	int x1,y1;
	int gcd=ExtendGCD(b%a,a,x1,y1);
	x=y1-(floor(b/a)*x1);
	y=x1;
	return gcd; 
}

int main(){
	sieve(500);
	int a,m;
	cin>>a>>m;
	MODval[0]=1, MODval[1]=a;
	for(int i=2;i<=m;i++){
		int res = MODval[i/2];
		if(i%2) MODval[i]=(res*res*a);
		else MODval[i]=(res*res);
	}
	if(m%2 && prime[m]==0){
		cout<<MODval[m-2]%m<<endl;
	} else{
		int x,y;
		int gcd=ExtendGCD(a,m,x,y);
		if(gcd!=1) cout<<"NO Solution\n";
		else{
			x=(x%m+m)%m;
			cout<<x<<endl;
		}
	}
	return 0;
}