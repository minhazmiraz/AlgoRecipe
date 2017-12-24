#include <bits/stdc++.h>
using namespace std;
string str1,str2;
int dp[1000][1000];


int LCS(int a, int b){
	if(dp[a][b]!=-1) return dp[a][b];
	if(a==str1.length()||b==str2.length()) return 0;

	int p=0;
	if(str1[a]==str2[b]) p=1+LCS(a+1,b+1);
	else p=max(LCS(a+1,b),LCS(a,b+1));
	
	return dp[a][b]=p;
}

string ans;
void printLCS(int a, int b){
	if(a==str1.length()||b==str2.length()){
		cout<<ans<<endl;
		return;
	}

	if(str1[a]==str2[b]){
		ans+=str1[a];
		printLCS(a+1,b+1);
	} else{
		if(dp[a+1][b]>dp[a][b+1])
			printLCS(a+1,b);
		else
			printLCS(a,b+1);
	}
}


void printALL(int a, int b){
	if(a==str1.length()||b==str2.length()){
		cout<<ans<<endl;
		return;
	}

	if(str1[a]==str2[b]){
		ans+=str1[a];
		printALL(a+1,b+1);
		ans.erase(ans.end()-1);
	} else{
		if(dp[a+1][b]>dp[a][b+1])
			printALL(a+1,b);
		else if(dp[a+1][b]<dp[a][b+1])
			printALL(a,b+1);
		else{
			printALL(a+1,b);
			printALL(a,b+1);
		}
	}
}


int main(){
	cin>>str1>>str2;
	memset(dp,-1,sizeof dp);
	cout<<"LCS-size: "<<LCS(0,0)<<endl;
	cout<<"LCS: ";
	ans.clear();
	printLCS(0,0);
	ans.clear();
	cout<<"All LCS: \n";
	printALL(0,0);
	return 0;
}