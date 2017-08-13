#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAX 105


int n,m;
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

vector< edge > graph[MAX];
int vis[MAX];

void prim(int s){
    vector< int > vnew;
    vector< edge > enew;
    int u=s;
    vnew.pb(u);
    vis[u]=1;
    priority_queue<edge, vector< edge >, comp> pq;
    for(int i=0;i<graph[u].size();i++){
        if(!vis[graph[u][i].v])
            pq.push(graph[u][i]);
    }

    while(!pq.empty()){
        if(vnew.size()==n) break;
        edge e = pq.top();
        pq.pop();
        u = e.v;

        if(!vis[u] && vis[e.u]){
            vnew.pb(u);
            enew.pb(e);
            vis[u]=1;
            for(int i=0;i<graph[u].size();i++){
                if(!vis[graph[u][i].v])
                    pq.push(graph[u][i]);
            }
        }
    }

    for(int i=0;i<enew.size();i++){
        printf("%d %d %d\n",enew[i].u, enew[i].v, enew[i].cost);
    }
}


int main(){

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        graph[u].pb(edge(u,v,cost));
        graph[v].pb(edge(v,u,cost));
    }
    memset(vis,0,sizeof vis);
    prim(1);
    cout<<endl;
    return 0;
}
