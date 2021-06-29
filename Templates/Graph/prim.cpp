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

vector<pll> adj[N];
ll minSpanningCost;

void prims(int root)
{
    minSpanningCost = 0;
    vi marked(N);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, root});
    while (!pq.empty())
    {
        pll cur = pq.top();
        pq.pop();
        ll vertex = cur.second;
        ll weight = cur.first;
        if (marked[vertex])
            continue;
        marked[vertex] = 1;
        minSpanningCost += weight;
        for (pll a : adj[vertex])
        {
            ll vertex = a.second;
            if (!marked[vertex])
            {
                pq.push(a);
            }
        }
    }
}

int main()
{
    /* make adj list here. adj[i]:{weight, vertext}. N is the maximum no of nodes.*/
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].pb({w, v});
        adj[v].pb({w, u});
    }

    /* prims(1) for mst rooted at 1.minSpanningCost only. */
    prims(1);

    cout << minSpanningCost << "\n";

    return 0;
}