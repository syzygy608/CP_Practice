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
    string l, r;
    cin >> l >> r;
    int ans = 1e9;
    int n = size(l);
    auto dfs = [&](auto &&self, int i, int sum) -> void
    {
        if(i == n)
        {
            cmn(ans, sum);
            return;
        }
        // set
        self(self, i + 1, sum + !(l[i] != r[i]));
        // not set
        self(self, i + 1, sum );
    };
    dfs(dfs, 0, 0);
    cout << ans << '\n';
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