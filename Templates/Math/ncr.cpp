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

// MACROS
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

vi fac(N);

void fact()
{
    fac[0] = 1;
    for (int i = 1; i < N; i++)
        fac[i] = 1LL * fac[i - 1] * i % mod;
}

ll bigmod(ll x, ll p)
{
    ll res = 1;
    while (p)
    {
        if (p & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        p >>= 1;
    }
    return res;
}

ll ncr(int n, int r)
{
    ll res = (fac[n] * bigmod(1LL * fac[r] * fac[n - r] % mod, mod - 2)) % mod;
    return res;
}

int32_t main()
{
    io;
    fact();

    return 0;
}
