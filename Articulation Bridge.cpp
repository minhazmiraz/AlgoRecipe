#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAX 100

int dtime;
vector< pair< int,int > > artiPnt;
vector< int > graph[MAX];
int d[MAX],vis[MAX],low[MAX];

void artiPoint(int s, int par=-1){
    dtime++;
    d[s]=low[s]=dtime;
    vis[s]=1;
    int u=s;
    int cnt=0;
    for(int i=0;i<graph[u].size();i++){
        int v = graph[u][i];
        if(v==par && cnt<1){
            cnt++;
            continue;
        }

        if(!vis[v]){
            artiPoint(v,u);
            low[u]=min(low[v],low[u]);

            if(d[u]<low[v]){
                artiPnt.pb({min(u,v),max(u,v)});
            }
        } else{
            low[u]=min(low[u],d[v]);
        }
    }
}



int main(){
    for(int i=0;i<MAX;i++) graph[i].clear();
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }

    memset(vis,0,sizeof vis);
    memset(d,0,sizeof d);
    memset(low,0,sizeof low);
    //memset(edge,0,sizeof edge);
    dtime=0;
    artiPoint(1);

    for(int i=0;i<artiPnt.size();i++){
        cout<<artiPnt[i].first<<" "<<artiPnt[i].second<<endl;
    }

    return 0;
}
