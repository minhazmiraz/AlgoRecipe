#include <bits/stdc++.h>
using namespace std;
int der[25];
int main(){
	der[0]=1; der[1]=0; der[2]=1;
	for(int i=3;i<=21;i++)
		der[i]=(i-1)*(der[i-1]+der[i-2]);
	//if n=4 number of 
	//dearrangement is der[n]
	return 0;
}