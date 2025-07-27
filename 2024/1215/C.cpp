#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
using namespace std;
using ll = long long;
const int INF = numeric_limits<int>::max() / 2;
const ll LINF = numeric_limits<ll>::max() / 2;

void solve()
{
    int m, a, b, c;
    cin >> m >> a >> b >> c;
    a = min(a, m);
    b = min(b, m);
    int ans = a + b;
    if(a != m && c > 0)
    {
        ans += min(c, m - a);
        c -= min(c, m - a);
    }
    if(b != m && c > 0)
    {
        ans += min(c, m - b);
        c -= min(c, m - b);
    }
    cout << ans << '\n';
}

int main()
{
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}