/*BISMILLAH
THE WHITE WOLF
NO DREAM IS TOO BIG AND NO DREAMER IS TOO SMALL*/

#include <bits/stdc++.h>
using namespace std;

//=========================================== debugger ================================================
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
//=========================================== end of debugger ================================================

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<long long> vll;
typedef vector<int> vi;

#define io ios_base::sync_with_stdio(false)
#define pb push_back
#define is_set(n, i) bool(n & (1LL << i))
#define bit_set(n, i) (n | (1LL << i))
#define bit_unset(n, i) (n & !(1LL << i))
#define PI 2 * acos(0.0)
#define all(r) (r).begin(), (r).end()
#define rev(r) (r).rbegin(), (r).rend()
#define dbg(a) cout << #a << " ->->->-> " << a << "\n"

int dirx[] = {1, -1, 0, 0, 1, 1, -1, -1}, diry[] = {0, 0, 1, -1, 1, -1, 1, -1};
const int maxn = 100009;
const int maxv = 1000000009;
const int mod = 1000000007;
const long long int inf = 1000000000000000000;
//=============================================ASIFAZAD==============================================//

ll ppow1[maxn], ppow2[maxn], pp1 = 33, pp2 = 31, hmod = 1000000009;
pll preHash[maxn], sufHash[maxn];

void calcPow()
{
    ppow1[0] = ppow2[0] = 1;
    for (int i = 1; i < maxn; i++)
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

// l and r are 1-indexed
// Hash multiplied by p^n

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

    return 0;
}
