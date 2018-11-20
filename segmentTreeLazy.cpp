#include <bits/stdc++.h>
using namespace std;
#define mx 1000005
long long lazy[4*mx], tree[4*mx];
int n,c;
void push(int i, int tl, int tm, int tr){
	tree[2*i]+=(tm-tl+1)*lazy[i];
	tree[2*i+1]+=(tr-tm)*lazy[i];
	lazy[2*i]+=lazy[i];
	lazy[2*i+1]+=lazy[i];
	lazy[i]=0;
}

void update(int i, int tl, int tr, int l, int r, int val){
	if(l>r) return;
	else if(tl==l && tr==r){
		tree[i]+=(r-l+1LL)*val;
		lazy[i]+=val;
//		cout<<l<<"-"<<r<<": "<<tree[i]<<endl;
	} else{
		int tm=(tl+tr)/2;
		push(i,tl,tm,tr);
		update(2*i,tl,tm,l,min(tm,r),val);
		update(2*i+1,tm+1,tr,max(l,tm+1),r,val);
		tree[i]=tree[2*i]+tree[2*i+1];
	}
}

long long query(int i, int tl, int tr, int l, int r){
	if(l>r) return 0;
	else if(tl==l && tr==r){
		return tree[i];
	}
	int tm=(tl+tr)/2;
	push(i,tl,tm,tr);
	return query(2*i,tl,tm,l,min(tm,r))
		+query(2*i+1,tm+1,tr,max(tm+1,l),r);
}

int main(){
	int tcase;
	scanf("%d",&tcase);
	for(int kase = 1;kase<=tcase;kase++){
		memset(tree,0,sizeof tree);
		memset(lazy,0,sizeof lazy);
		scanf("%d%d",&n,&c);
		for(int i=1;i<=c;i++){
			int type, p,q,v;
			scanf("%d",&type);
			if(type==0){
				scanf("%d%d%d",&p,&q,&v);
				update(1,1,n,p,q,v);
			} else{
				scanf("%d%d",&p,&q);
				printf("%lld\n",query(1,1,n,p,q));
			}
		}
	}
	return 0;
}