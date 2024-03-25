/*BISMILLAH
THE WHITE WOLF
NO DREAM IS TOO BIG AND NO DREAMER IS TOO SMALL*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<long long> vll;
typedef vector<int> vi;

//MACROS
#define io ios_base::sync_with_stdio(false)
#define pb push_back
#define SET(n, i) bool(n & (1 << i))
#define PI 2 * acos(0.0)
#define all(r) (r).begin(), (r).end()
#define dbg(a) cout << #a << " ->->->-> " << a << "\n"
#define inf 100000000000000000
#define mod 1000000007
#define N 3000000

int dirx[] = {1, -1, 0, 0, 1, 1, -1, -1}, diry[] = {0, 0, 1, -1, 1, -1, 1, -1};

//=============================================ASIFAZAD==============================================//

typedef struct
{
    int u, v;
    ll w;
} edge;

/* reversing the cmpEdges will generate max spanning tree */
bool cmpEdges(edge a, edge b)
{
    return a.w > b.w;
}

vector<edge> minSpanningEdges;
ll minSpanningCost;
vi treeId(N);

vector<pll> adj[N];
vector<edge> edges;

void init()
{
    for (int i = 0; i < N; i++)
    {
        treeId[i] = i;
    }
}

int root(int x)
{
    while (treeId[x] != x)
    {
        treeId[x] = treeId[treeId[x]];
        x = treeId[x];
    }
    return x;
}

void connectComponents(int x, int y)
{
    int r1 = root(x);
    int r2 = root(y);
    treeId[r1] = treeId[r2];
}

void kruskals()
{
    minSpanningCost = 0;
    minSpanningEdges.clear();
    sort(all(edges), cmpEdges);
    for (auto e : edges)
    {
        int u = e.u;
        int v = e.v;
        ll w = e.w;
        if (root(u) != root(v))
        {
            minSpanningCost += w;
            minSpanningEdges.pb(e);
            connectComponents(u, v);
        }
    }
}

int main()
{
    init();
    /*insert edges in the edges vector as edge struct(u, v, w). N is the max number of nodes. */
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        edge e;
        cin >> e.u >> e.v >> e.w;
        edges.pb(e);
    }

    kruskals();
    /* minSpanningCost and minSpanningEdges */
    cout << minSpanningCost << "\n";

    return 0;
}