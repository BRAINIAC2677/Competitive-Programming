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
#define SET(n, i) bool(n & (1LL << i))
#define PI 2 * acos(0.0)
#define all(r) (r).begin(), (r).end()
#define dbg(a) cout << #a << " ->->->-> " << a << "\n"
#define inf 100000000000000000
#define mod 1000000007
#define N 1000009

int dirx[] = {1, -1, 0, 0, 1, 1, -1, -1}, diry[] = {0, 0, 1, -1, 1, -1, 1, -1};

//=============================================ASIFAZAD==============================================//

ll ppow1[N], ppow2[N], pp1 = 33, pp2 = 31, hmod = 1000000009;
pll preHash[N], sufHash[N];

void calcPow()
{
    ppow1[0] = ppow2[0] = 1;
    for (int i = 1; i < N; i++)
    {
        ppow1[i] = ppow1[i - 1] * pp1 % hmod;
        ppow2[i] = ppow2[i - 1] * pp2 % hmod;
    }
}

pll Hash(string &s)
{
    int n = s.size();
    char lettercase = (s[0] < 'a' ? 'A' : 'a');
    pll res = {0, 0};
    for (int i = 0; i < n; i++)
    {
        res.first = (res.first + (s[i] - lettercase + 1) * ppow1[i] % hmod) % hmod;
        res.second = (res.second + (s[i] - lettercase + 1) * ppow2[i] % hmod) % hmod;
    }
    return res;
}

void completeHash(string &s)
{
    int n = s.size();
    char lettercase = (s[0] < 'a' ? 'A' : 'a');
    for (int i = 1; i <= n; i++)
    {
        preHash[i].first = (preHash[i - 1].first + (s[i - 1] - lettercase + 1) * ppow1[i - 1] % hmod) % hmod;
        preHash[i].second = (preHash[i - 1].second + (s[i - 1] - lettercase + 1) * ppow2[i - 1] % hmod) % hmod;

        sufHash[i].first = (sufHash[i - 1].first + (s[n - i] - lettercase + 1) * ppow1[i - 1] % hmod) % hmod;
        sufHash[i].second = (sufHash[i - 1].second + (s[n - i] - lettercase + 1) * ppow2[i - 1] % hmod) % hmod;
    }
}

//l and r are 1-indexed
//Hash multiplied by p^n

pll subStringHash(pll hash[], int n, int l, int r)
{
    if (l <= 0 || l > r || r > n)
        return {-1, -1};
    pll res = hash[r];

    res.first = (res.first - hash[l - 1].first + hmod) % hmod;
    res.second = (res.second - hash[l - 1].second + hmod) % hmod;

    res.first = res.first * ppow1[n - l + 1] % hmod;
    res.second = res.second * ppow2[n - l + 1] % hmod;

    return res;
}

int32_t main()
{
    io;
    calcPow();
    string s = "ab";

    return 0;
}
