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
#define N 500009

int dirx[] = {1, -1, 0, 0, 1, 1, -1, -1}, diry[] = {0, 0, 1, -1, 1, -1, 1, -1};

//=============================================ASIFAZAD==============================================//

vll inp(N);
vector<ll> segment[4 * N];

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
    //take input in inp(already declared); 1-indexed;
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
