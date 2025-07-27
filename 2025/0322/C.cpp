#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

constexpr i64 MOD = 1e9 + 7;

template<class T>
static void cmn(T &a, T b) { a = (a <=> b > 0) ? b : a; }
template<class T>
static void cmx(T &a, T b) { a = (a <=> b < 0) ? b : a; }

void solve()
{
    i64 a[2];
    cin >> a[0] >> a[1];
    if(!(a[0] & a[1]))
        cout << "0\n";
    else
    {
        // a + b = a ^ b + 2 ( a & b )
        // (x + k) + (y + k) = (x + k) ^ (y + k) + 2 ((x + k) & (y + k))
        // (x + k) & (y + k) = 0
        i64 k = (1ll<<59) - max(a[0], a[1]);
        if((a[0] + k) & (a[1] + k))
            cout << "-1\n";
        else
            cout << k << '\n';
    }
}

int main()
{
    (cin.tie(0))->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}