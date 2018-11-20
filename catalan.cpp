#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mx 1000
int catalan[mx];
void init(){
	catalan[0]=catalan[1]=1;
	for(int i=2;i<mx;i++){
		catalan[i]=0;
		for(int j=0;j<i;j++){
			catalan[i]=(catalan[i]+(catalan[j]*catalan[i-j-1])%MOD)%MOD;
		}
	}
}

int main(){
	init();
	int n;
	cin>>n;
	cout<<catalan[n]<<endl;
	return 0;
}