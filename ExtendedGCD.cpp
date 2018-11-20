#include <bits/stdc++.h>
using namespace std;

int ExtendedGCD(int a, int b, int &x, int &y){
	if(a==0){
		x=0,y=1;
		return b;
	}

	int x1,y1;
	int gcd=ExtendedGCD(b%a,a,x1,y1);
	x=y1-floor(b/a)*x1;
	y=x1;
	return gcd;
}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	int x,y;
	int gcd=ExtendedGCD(a,b,x,y);
	printf("(%d)*%d + (%d)*%d = %d\n",x,a,y,b,gcd);
	return 0;
}