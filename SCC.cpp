#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAX 1000


vector< int > graph[MAX];
vector< int > rvrs[MAX];
int vis[MAX];
stack< int > finish;
int n,m;


void dfs(int src){
    vis[src]=1;
    int u=src;
    for(int i=0;i<graph[u].size();i++){
        int v=graph[u][i];
        if(!vis[v]){
            vis[v]=1;
            dfs(v);
        }
    }
    finish.push(u);
}



void dfs2(int src){
    vis[src]=1;
    int u=src;
    cout<<u<<" ";
    for(int i=0;i<rvrs[u].size();i++){
        int v=rvrs[u][i];
        if(!vis[v]){
            dfs2(v);
        }
    }
}


void scc(){
    memset(vis,0,sizeof vis);
    for(int i=1;i<=n;i++)
        if(!vis[i])
            dfs(i);
    memset(vis,0,sizeof vis);
    while(!finish.empty()){
        int i=finish.top();
        finish.pop();
        if(!vis[i]){
            dfs2(i);
            cout<<endl;
        }
    }
}


int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].pb(v);
        rvrs[v].pb(u);
    }
    scc();
    return 0;
}
