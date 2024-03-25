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
#define bit_unset(n, i) (n & ~(1LL << i))
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

//=========================================== Debug WA ============================================
// 1. Before submission do a quick logical scan + incorrect output formatting + resetting ds in multi-testcases problem.

// 2. TLE/MLE: Look for allocating lots of vectors/ds inside loops and recursive functions + overflow check.

// 3. RE: check for index out of bounds.

// 4. Have a test case that breaks my program: use debug template

// 5. Have a bruteforce solution: bash generator for input and output match. Find a test case that breaks the code and go to 4.

// 6. Rewrite the code+keep it clean/give up.
//========================================== Debug WA ===============================================

int main()
{
    io;
    ifstream in("input.txt");
    ofstream out("output.txt");

    return 0;
}