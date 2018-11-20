#include <bits/stdc++.h>
using namespace std;
#define Test(x) int x;cin>>x
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define MAX 1000

//Euler's Totient Function:
//Count all number which are co-prime of N smaller than N
//Count relatively prime number of N smaller than N

int singlephi(int n){					//Complexity: sqrt(n)
	int result=n;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			while(n%i==0) n/=i;	//Dividing By prime Factor
			result-=result/i;	//Substracting All multiple of i
		}
	}
	if(n>1) result-=result/n;
	return result;
}

int phi[MAX];
bool mark[MAX];

void allphi(int n){
	for(int i=1;i<=n;i++) phi[i]=i;

	phi[1]=1;
	mark[1]=1;
	for(int i=2;i<=n;i++){			//loop for prime divisor
		if(!mark[i]){
			for(int j=i;j<=n;j+=i){	//loop for multiple of prime divisor
				mark[j]=1;
				phi[j]=phi[j]/i*(i-1);
			}
		}
	}
}

int main() {
    //ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	cout<<"Phi of N: "<<singlephi(n)<<endl;
	allphi(n);
    cout<<"All phi between 1 to N:\n";
    for(int i=1;i<=n;i++)
    	cout<<phi[i]<<endl;
    return 0;
}
