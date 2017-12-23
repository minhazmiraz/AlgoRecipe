#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <list>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <iomanip>
#include <stack>
#define MAX 100005
#define pb push_back
#define all(c) (c.begin(), c.end())
#define mem(a, b) memset(a, b, sizeof(a))
#define EPS 1e-10
#define PI 3.14159265358979323846
#define MOD 10000000007
#define INF 2147483647
#define mp make_pair
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef vector<int> vi;
typedef vector< vector<int> >vii;
typedef vector<double> vd;
typedef vector<string> vs;
typedef long long ll;
typedef unsigned long long ull;

int table[MAX][20], cost[MAX][20];
vector<pii> graph[MAX];
int cst[MAX], depth[MAX], parent[MAX];
int anscestor;


void dfs(int from, int u, int dep)
{
    parent[u] = from;
    depth[u] = dep;

    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i].first;
        int c = graph[u][i].second;
        if(v == from)
            continue;
        cst[v] = c;
        dfs(u, v, dep+1);
    }
}

void init(int n)
{
    parent[0] = -1;
    for(int i = 0; i < n; i++){
        table[i][0] = parent[i];
        cost[i][0] = cst[i];
    }

    for(int j = 1; (1<<j) < n; j++){
        for(int i = 0; i < n ; i++){
            if(table[i][j-1] != -1){
                table[i][j] = table[table[i][j-1]][j-1];
                cost[i][j] = cost[i][j-1] + cost[table[i][j-1]][j-1];
            }
        }
    }
}

int LCA(int p, int q)
{
    int sum = 0;
    if(depth[p] < depth[q])
        swap(p, q);

    int lg = (int) log2(depth[p]) + 1;

    for(int i = lg; i >= 0; i--){
        if((depth[p] - (1<<i)) >= depth[q]){
            sum += cost[p][i];
            p = table[p][i];
        }
    }

    if(p == q){
        anscestor = p;
        return sum;
    }

    for(int i = lg; i >= 0; i--){
        if(table[p][i] != -1 && (table[p][i] != table[q][i])){
            sum += (cost[p][i] + cost[q][i]);
            p = table[p][i];
            q = table[q][i];
        }
    }

    sum += (cst[p] + cst[q]);

    anscestor = parent[p];
    return sum;
}

int main()
{
    int nodeNo, edgeNo, u, v, c;

    memset(parent, -1, sizeof(parent));
    memset(table, -1, sizeof(table));
    memset(cost, 0, sizeof(cost));

    scanf("%d %d", &nodeNo, &edgeNo);

    for(int i = 0; i < edgeNo; i++){
        scanf("%d %d %d", &u, &v, &c);
        graph[u].pb(mp(v, c));
        graph[v].pb(mp(u, c));
    }

    dfs(0, 0, 0);
    init(nodeNo);

    int q;

    scanf("%d", &q);

    for(int i = 0; i < q; i++){
        scanf("%d %d", &u, &v);
        printf("Lowest Common Ancestor: %d\nTotal Sum: %d\n", anscestor, LCA(u, v));
    }

    return 0;
}
