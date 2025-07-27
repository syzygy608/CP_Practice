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
    int n;
    cin >> n;
    vector<int> v(n);
    i64 bits[31] = {0}, base = 0, sum = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
        base += v[i];
        for(int j = 0; j < 30; ++j)
            if(v[i] >> j & 1)
                bits[j]++;
    }
    for(int i = 0; i < n; ++i)
    {
        i64 cur = base;
        for(int j = 0; j < 30; ++j)
            if(v[i] >> j & 1)
                cur += (n - 2 * bits[j]) * 1ll * (1ll << j);
        if(cur > sum)
            sum = cur;
    }
    cout << sum << '\n';
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