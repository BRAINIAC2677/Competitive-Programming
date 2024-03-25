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

vll inp(maxn);
vector<ll> segment[4 * maxn];

vll merge(vll a, vll b)
{
    vll res;
    int ai = 0, bi = 0, an = a.size(), bn = b.size();
    while (ai < an || bi < bn)
    {
        if (ai >= an)
            res.pb(b[bi++]);
        else if (bi >= bn)
            res.pb(a[ai++]);
        else
            res.pb(a[ai] < b[bi] ? a[ai++] : b[bi++]);
    }
    return res;
}

void build(int cur, int strt, int en)
{
    if (strt == en)
        segment[cur] = vll(1, inp[en]);
    else
    {
        int mid = (strt + en) / 2;
        build(2 * cur, strt, mid);
        build(2 * cur + 1, mid + 1, en);
        segment[cur] = merge(segment[2 * cur], segment[2 * cur + 1]);
    }
}

void update(int cur, int strt, int en, int index, int value)
{
    if (strt == en)
        segment[cur] = vll(1, value);
    else
    {
        int mid = (strt + en) / 2;
        if (index <= mid)
            update(2 * cur, strt, mid, index, value);
        else
            update(2 * cur + 1, mid + 1, en, index, value);
        segment[cur] = merge(segment[2 * cur], segment[2 * cur + 1]);
    }
}

ll get(int cur, int strt, int en, int l, int r, int value)
{
    if (en < l || strt > r)
        return 0;
    else if (strt >= l && en <= r)
        return segment[cur].end() - upper_bound(all(segment[cur]), value);
    int mid = (strt + en) / 2;
    return get(2 * cur, strt, mid, l, r, value) + get(2 * cur + 1, mid + 1, en, l, r, value);
}

/* number of elements greater than a given number in a range*/

int32_t main()
{
    // take input in inp(already declared); 1-indexed;
    io;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> inp[i];
    build(1, 1, n);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r, v;
        cin >> l >> r >> v;
        cout << get(1, 1, n, l, r, v) << "\n";
    }

    return 0;
}
