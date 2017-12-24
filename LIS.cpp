#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int seq[MAX],L[MAX],I[MAX],n;


int nlogn(){
	vector< int > vc;
	for(int i=1;i<=n;i++){
		//for increasing LIS
		auto inc = lower_bound(vc.begin(),vc.end(),seq[i]);
		//for non-decreasing LIS
		//auto ndec = upper_bound(vc.begin(),vc.end(),seq[i]);
		if(inc==vc.end()){
			vc.push_back(seq[i]);
			L[i]=vc.size();
		} else{
			vc[inc-vc.begin()]=seq[i];
			L[i]=(inc-vc.begin())+1;
		}
	}

	return (int)(vc.size());
}



int n2LIS(){
	int maxx=0;
	for(int i=1;i<=n;i++)
		L[i]=1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(seq[i]<seq[j])
				L[j]=max(L[i]+1,L[j]);
		}
		maxx=max(maxx,L[i]);
	}
	return maxx;
}


void LIScons(int maxx){
	vector< int > vc;
	for(int i=n;i>=1;i--){
		if(L[i]==maxx){
			maxx--;
			vc.push_back(seq[i]);
		}
	}
	int ptr=vc.size();
	while(ptr--) cout<<vc[ptr]<<endl;
}

void read(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>seq[i];
}


int main(){
	read();
	int maxx=nlogn();
	cout<<"LIS size: "<<maxx<<endl;
	LIScons(maxx);
	return 0;
}

//Extra

/*
int nlogkLIS(){
	memset(I,63,sizeof I);
	I[0]=-I[1];
	int Isize=0;
	for(int i=1;i<=n;i++){
		int lo=0,hi=Isize,mid;
		while(lo<=hi){
			mid=(hi+lo)/2;
			if(I[mid]<seq[i])
				lo=mid+1;
			else
				hi=mid-1;
		}
		I[lo]=seq[i];
		L[i]=lo;
		Isize=max(Isize,lo);
	}
	return Isize;
}

*/