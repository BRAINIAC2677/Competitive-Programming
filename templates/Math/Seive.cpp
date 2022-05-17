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

vll prime;

void seive()
{
    vi ck(N);
    for (ll i = 3; i * i <= N; i += 2)
        if (!ck[i])
            for (ll j = i * i; j < N; j += 2 * i)
                ck[j] = 1;

    prime.pb(2);

    for (ll i = 3; i < N; i += 2)
        if (!ck[i])
            prime.pb(i);
}

int32_t main()
{
    io;
    seive();

    return 0;
}
