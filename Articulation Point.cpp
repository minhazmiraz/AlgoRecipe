#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int dtime;
vector< int > artiPnt;
vector< int > graph[100];
int d[100],vis[100],low[100],par[100],child[100];

void artiPoint(int s){
    dtime++;
    d[s]=low[s]=dtime;
    vis[s]=1;
    int u=s;
    //cout<<u<<" "<<graph[u].size()<<endl;
    for(int i=0;i<graph[u].size();i++){

        int v = graph[u][i];
        //cout<<v<<endl;
        if(v==par[u])
            continue;

        if(!vis[v]){
            child[u]++;
            par[v]=u;
            artiPoint(v);
            low[u]=min(low[v],d[u]);

            if(d[u]<=low[v] && par[u]!=0){
                artiPnt.pb(u);
            }

            //cout<<"Hello\n";


        } else{
            low[u]=min(low[u],d[v]);
        }
    }



    dtime++;
}


int main(){
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
    memset(child,0,sizeof child);
    par[1]=0;
    dtime=0;
    artiPoint(1);
    if(par[1]==0 && child[1]>1){
        artiPnt.pb(1);
    }
    for(int i=0;i<artiPnt.size();i++){
        cout<<artiPnt[i]<<" ";
    }

    return 0;
}
