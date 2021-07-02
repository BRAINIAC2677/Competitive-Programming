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

#define io ios_base::sync_with_stdio(false)
#define pb push_back
#define isSet(n, i) bool(n & (1LL << i))
#define Set(n, i) (n | (1LL << i))
#define unSet(n, i) (n & !(1LL << i))
#define PI 2 * acos(0.0)
#define all(r) (r).begin(), (r).end()
#define rev(r) (r).rbegin(), (r).rend()
#define dbg(a) cout << #a << " ->->->-> " << a << "\n"
#define inf 1000000000000000000
#define mod 1000000007
#define N 500009

int dirx[] = {1, -1, 0, 0, 1, 1, -1, -1}, diry[] = {0, 0, 1, -1, 1, -1, 1, -1};

//=============================================ASIFAZAD==============================================//

int main()
{
    io;
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, m;
    cin >> n >> m;
    vi adj[n + 1], inDegree(n + 1, 0), ans;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        inDegree[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (inDegree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        ans.pb(cur);
        for (auto a : adj[cur])
        {
            inDegree[a]--;
            if (inDegree[a] == 0)
                q.push(a);
        }
    }

    if (ans.size() != n)
    {
        /*given graph is not a DAG */
    }
    else
    {
        /* topological order is in ans vector */
    }
    return 0;
}