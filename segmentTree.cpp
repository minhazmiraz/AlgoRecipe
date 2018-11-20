#include <bits/stdc++.h>
using namespace std;
#define mx 100005
int arr[mx],tree[3*mx];

void init(int i, int tl, int tr){
	if(tl==tr) tree[i]=arr[tl];
	else {
		int tm=(tl+tr)/2;
		init(2*i,tl,tm);
		init(2*i+1,tm+1,tr);
		tree[i]=tree[2*i]+tree[2*i+1];
	}
}

void update(int i, int tl, int tr, int key, int value){
	if(tl>tr) return;
	else if(tl==tr && tl==key) tree[i]=0;
	else {
		int tm=(tl+tr)/2;
		if(key<=tm)
			update(2*i,tl,min(tm,tr),key,value);
		else
			update(2*i+1,max(tm+1,tl),tr,key,value);
		tree[i]=tree[2*i]+tree[2*i+1];
	}
}

int query(int i, int tl, int tr, int L, int R){
	if(L>R) return 0;
	else if(tl==L && tr==R) return tree[i];
	int tm=(tl+tr)/2;
	return query(2*i,tl,tm,L,min(R,tm))
		+query(2*i+1,tm+1,tr,max(L,tm+1),R);
}

int main(){
	int tcase;
	scanf("%d",&tcase);
	for(int kase=1;kase<=tcase;kase++){
		memset(arr,0,sizeof arr);
		memset(tree,0,sizeof tree);
		printf("Case %d:\n",kase);
		int n,q;
		scanf("%d%d",&n,&q);
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);

		init(1,0,n-1);
		
		for(int i=1;i<=q;i++){
			int a;
			scanf("%d",&a);
			if(a==1){
				int b;
				scanf("%d",&b);
				printf("%d\n",query(1,0,n-1,b,b));
				update(1,0,n-1,b,0);
			} else{
				int b,c;
				scanf("%d%d",&b,&c);
				if(a==2) update(1,0,n-1,b,c);
				else printf("%d\n",query(1,0,n-1,b,c));
			}
		}
	}
	return 0;
}