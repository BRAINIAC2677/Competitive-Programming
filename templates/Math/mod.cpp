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
#define mod 998244353
#define N 3000000

int dirx[] = {1, -1, 0, 0, 1, 1, -1, -1}, diry[] = {0, 0, 1, -1, 1, -1, 1, -1};

//=============================================ASIFAZAD==============================================//

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

//mod of a huge number in O(n)
int strMod(string a, int m)
{
    int cur = a[0] - '0';
    for (int i = 1; i < a.size(); i++)
    {
        cur *= 10;
        cur += (a[i] - '0');
        cur %= m;
    }
    return cur % m;
}

ll modInv(ll a)
{
    return bigmod(a, mod - 2) % mod;
}

ll divisionMod(ll a, ll b)
{
    return a % mod * modInv(b) % mod;
}

int32_t main()
{
    io;
    cout << divisionMod(1, 10);
    return 0;
}
