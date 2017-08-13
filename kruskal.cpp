#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
#define pb push_back

int n,m,sum;
int root[MAX],weight[MAX];



struct edge{
    int u,v,cost;
    edge(int a, int b, int c){
        u=a;
        v=b;
        cost=c;
    }
};

struct comp{
    bool operator()(const edge &first, const edge &second){
        return first.cost>second.cost;
    }
};

priority_queue<edge, vector< edge >, comp> pq;

///disjoint set


int find_root(int n){
    if(n!=root[n])
        root[n]=find_root(root[n]);
    return root[n];
}

void union_set(int px, int py){
    if(weight[px]>weight[py]){
        root[py]=px;
        weight[px]+=weight[py];
    } else{
        root[px]=py;
        weight[py]+=weight[px];
    }
}

///kruskal

void kruskal(){
    int cnt=1;
    for(int i=1;i<=n;i++){
        root[i]=i;
        weight[i]=1;
    }

    vector< edge > enew;

    while(!pq.empty()){
        edge e=pq.top();
        pq.pop();
        int px = find_root(e.u);
        int py = find_root(e.v);
        if(px!=py){
            enew.pb(e);
            sum+=e.cost;
            union_set(px,py);
            cnt++;
            if(cnt==n) break;
        }
    }


    for(int i=0;i<enew.size();i++){
        cout<<enew[i].u<<" "<<enew[i].v<<" "<<enew[i].cost<<endl;
    }
}



int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        pq.push(edge(u,v,cost));
    }
    sum=0;
    kruskal();
    cout<<"Total Cost: "<<sum<<endl;
    return 0;
}
