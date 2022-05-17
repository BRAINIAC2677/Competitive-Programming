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
vector<ll> segment(4 * N);

ll calc(ll a, ll b)
{
    return max(a, b);
}

void buildMax(int cur, int strt, int en)
{
    if (strt == en)
        segment[cur] = inp[en];
    else
    {
        int mid = (strt + en) / 2;
        buildMax(2 * cur, strt, mid);
        buildMax(2 * cur + 1, mid + 1, en);
        segment[cur] = calc(segment[2 * cur], segment[2 * cur + 1]);
    }
}

void updateMax(int cur, int strt, int en, int index, int value)
{
    if (strt == en)
        segment[cur] = inp[index] = value;
    else
    {
        int mid = (strt + en) / 2;
        if (index <= mid)
            updateMax(2 * cur, strt, mid, index, value);
        else
            updateMax(2 * cur + 1, mid + 1, en, index, value);
        segment[cur] = calc(segment[2 * cur], segment[2 * cur + 1]);
    }
}

ll getMax(int cur, int strt, int en, int l, int r)
{
    if (en < l || strt > r)
        return INT_MIN;
    else if (strt >= l && en <= r)
        return segment[cur];
    int mid = (strt + en) / 2;
    return calc(getMax(2 * cur, strt, mid, l, r), getMax(2 * cur + 1, mid + 1, en, l, r));
}

int32_t main()
{
    //take input in inp(already declared); 1-indexed;
    //buildMax(1,1,n); updateMax(1, 1, n, index, value); getMax(1,1, n, l, r);
    io;

    return 0;
}
