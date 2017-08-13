#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int dp[MAX][MAX];
bool vis[MAX][MAX];

int nCr(int n, int r){
	if(vis[n][r])
		return dp[n][r];
	else if(r==1){
		vis[n][r]=true;
		dp[n][r]=n;
		return dp[n][r];
	}
	else if(n==r){
		vis[n][r]=1;
		dp[n][r]=1;
		return dp[n][r];
	}

	dp[n][r]=nCr(n-1,r)+nCr(n-1,r-1);
	vis[n][r]=1;
	return dp[n][r];
}



int main(){
	memset(vis,false,sizeof vis);
	int n,r;
	cin>>n>>r;
	cout<<nCr(n,r)<<endl;
	return 0;
}