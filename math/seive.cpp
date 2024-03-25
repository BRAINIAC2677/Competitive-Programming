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

vll prime;
// complexity: maxn*loglog(maxn)
void seive()
{
    vi ck(maxn);
    for (ll i = 3; i * i <= maxn; i += 2)
        if (!ck[i])
            for (ll j = i * i; j < maxn; j += 2 * i)
                ck[j] = 1;

    prime.pb(2);

    for (ll i = 3; i < maxn; i += 2)
        if (!ck[i])
            prime.pb(i);
}
// complexity: ((R-L+1)loglog(R) + sqrt(R)loglog*sqrt(R))
vector<bool> range_sieve(long long L, long long R)
{
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i)
    {
        if (!mark[i])
        {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<bool> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

int32_t main()
{
    io;
    seive();

    int l, r;
    l = 2;
    r = 5;
    vector<bool> is_prime = range_sieve(l, r);
    for (int i = 0; i < r - l + 1; i++)
    {
        cout << is_prime[i] << " ";
    }

    return 0;
}
