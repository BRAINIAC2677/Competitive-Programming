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

ll phi[N];

void getPhiAll(int n)
{
    for (int i = 1; i <= n; i++)
        phi[i] = i;
    for (ll i = 2; i <= n; i++)
        if (phi[i] == i)
            for (ll j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
}

ll getPhi(ll n)
{
    ll res = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            ;
            res -= res / i;
        }
    }
    if (n > 1)
        res -= res / n;
    return res;
}

int32_t main()
{
    io;

    return 0;
}
