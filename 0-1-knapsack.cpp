#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


int n,cap,weight[MAX],cost[MAX];
int dp[MAX][MAX];
bool vis[MAX][MAX];


int knapsack(int i, int w){
	int profit1, profit2;
	if(vis[i][w])
		return dp[i][w];
	if(i==n+1){
		vis[i][w]=true;
		return dp[i][w]=0;
	}
	if(w+weight[i]<=cap)
		profit1=cost[i]+knapsack(i+1,w+weight[i]);
	else
		profit1=0;
	
	profit2=knapsack(i+1,w);

	vis[i][w]=true;
	dp[i][w]=max(profit1,profit2);
	return dp[i][w];
}



int main(){
	memset(vis,false,sizeof vis);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>weight[i]>>cost[i];
	}
	cin>>cap;

	cout<<knapsack(1,0)<<endl;
}