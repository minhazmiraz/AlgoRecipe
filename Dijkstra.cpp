#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define debug(x,y) cout<<x<<y
#define NL printf("\n")
#define SP printf(" ")
#define inf 1e8;

typedef map< int, vector< pair<int,int> > > mpiii;

mpiii graph;
int dist[100];
void dijkstra(int source){
	set< int> st;
	st.insert(source);
	dist[source]=0;
	while(!st.empty()){
		auto top=st.begin();
		int u=*top;
		st.erase(u);
		for(int i=0;i<graph[u].size();i++){
			int v = graph[u][i].first;
			if(dist[u]+graph[u][i].second<dist[v]){
				st.erase(v);
				dist[v]=dist[u]+graph[u][i].second;
				st.insert(v);
			}
		}
	}
}

int main(){
	int node;
	printf("Enter Node no.: \n");
	scanf("%d",&node);
	printf("Enter your graph: \n");
	for(int i=1;i<=node;i++){
		int u,v,cost;
		scanf("%d%d%d",&u,&v,&cost);
		graph[u].pb(mp(v,cost));
	}
	for(int i=1;i<=node;i++)
		dist[i]=inf;
	dijkstra(0);
	printf("Assuming 1 as source shortest path of all the node: \n");
	for(int i=0;i<=4;i++){
		printf("Distance of %d: %d\n", i,dist[i]);
	}
	return 0;
}