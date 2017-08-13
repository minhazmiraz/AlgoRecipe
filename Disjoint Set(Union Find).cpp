#include<bits/stdc++.h>
using namespace std;
#define MAX 10000

int root[MAX],weight[MAX];

void make_set(int n){
    root[n]=n;
    weight[n]=0;
}

int find_root(int n){
    if(n!=root[n])
        root[n]=find_root(root[n]);
    return root[n];
}

void union_set(int x, int y){
    int px = find_root(x);
    int py = find_root(y);
    if(px==py)
        return;
    if(weight[px]>weight[py]){
        root[py]=px;
        weight[px]+=weight[py];
    } else{
        root[px]=py;
        weight[py]+=weight[px];
    }
}

void disjoint_set(int n){
    for(int i=1;i<=n;i++){
        make_set(i);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    disjoint_set(n);
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        union_set(a,b);
    }
    vector< int  > st[n+5];
    set< int > par;
    for(int i=1;i<=n;i++){
        st[root[i]].push_back(i);
        par.insert(root[i]);
    }

    for(auto it = par.begin();it!=par.end();it++){
        for(int i=0;i<st[*it].size();i++)
            cout<<st[*it][i]<<" ";
        cout<<endl;
    }
}
